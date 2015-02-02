#include "citygmlhandler.h"
#include <cfloat>

//constucteur
citygmlHandler::citygmlHandler()
{
    _params.tesselate = true;
}
//destructeur
citygmlHandler::~citygmlHandler()
{
}
//fonction qui charge le fichier cityGML
void citygmlHandler::loadFile(QString f)
{
    QFileInfo fileInf(f);
    fileName = f;							//le nom du fichier
    filePath = fileInf.absolutePath()+"/";  //le chemin du fichier

    _params.maxLOD = 4;						// max niveau de détail
    _params.minLOD = 0;						// min niveau de détail

    _city = citygml::load(fileName.toStdString(),_params);
}
// fonction qui dessine le model cityGML chargé 
void citygmlHandler::drawModel()
{
    if(fileName.isEmpty()) return; // si le fichier n'est pas chargé le programme ne fait rien

    const citygml::CityObjectsMap& cityObjectsMap = _city->getCityObjectsMap();	// récupération de l'objet
    citygml::CityObjectsMap::const_iterator it = cityObjectsMap.begin();		// récupération du premier point de l'objet
// boucle pour dessiner tout les points de l'objet
    for ( ; it != cityObjectsMap.end(); it++ )
    {
        const citygml::CityObjects& objList = it->second;

        for(unsigned int i=0 ; i<objList.size() ; i++)
        {
            citygml::CityObject *obj = objList.at(i);
            drawObject(obj);
        }
    }
}
// fonction qui affecte ses paramètres aux attributs valeurs min et max du niveau de détail
void citygmlHandler::setLOD(int min, int max)
{
    _params.minLOD = min;
    _params.maxLOD = max;
}

unsigned int *citygmlHandler::getMinMaxLOD()
{
    const citygml::CityObjectsMap& cityObjectsMap = _city->getCityObjectsMap();
    citygml::CityObjectsMap::const_iterator it = cityObjectsMap.begin();
    unsigned int *minmax = new unsigned int[2];
    minmax[0] = 4;
    minmax[1] = 0;
    for ( ; it != cityObjectsMap.end(); it++ )
    {
        const citygml::CityObjects& objList = it->second;
        #pragma omp parallel for
        for(unsigned int i=0 ; i<objList.size() ; i++)
        {
            citygml::CityObject *ob = objList.at(i);
            #pragma omp parallel for
            for(unsigned int j=0 ; j<ob->size() ; j++)
            {
                const citygml::Geometry *geo = ob->getGeometry(j);
                minmax[0] = geo->getLOD()<minmax[0]?geo->getLOD():minmax[0];
                minmax[1] = geo->getLOD()>minmax[1]?geo->getLOD():minmax[1];
            }
        }
    }

    return minmax;
}
// fonction qui charge et applique la texture
void citygmlHandler::loadTexture(QString url)
{
    QImage qim_Texture;
    QImage qim_TempTexture;
    qim_TempTexture.load(filePath+url);
    qim_Texture = QGLWidget::convertToGLFormat( qim_TempTexture );

    glGenTextures( 1, &_texture[url] );

    glBindTexture( GL_TEXTURE_2D, _texture[url]);

    glTexImage2D( GL_TEXTURE_2D, 0, 3, qim_Texture.width(), qim_Texture.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, qim_Texture.bits() );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
}

void citygmlHandler::applyTexture(QString url)
{
    if(!_texture.contains(url))
    {
        loadTexture(url);
    }
    glBindTexture( GL_TEXTURE_2D, _texture[url]);
}

QMap<QString, double> citygmlHandler::getEnvelope()
{
    QMap<QString,double> res;
    if(fileName.isEmpty()) return res;

    citygml::Envelope env = _city->getEnvelope();
    if(env.getLowerBound().x == env.getUpperBound().x && env.getLowerBound().y == env.getUpperBound().y)
    {
        env = getEnvelopeFromModel();
    }

    res["xCam"] = env.getLowerBound().x;    res["xTar"] = env.getUpperBound().x;
    res["yCam"] = env.getLowerBound().y;    res["yTar"] = env.getUpperBound().y;
    res["zCam"] = env.getLowerBound().z;    res["zTar"] = env.getUpperBound().z;

    return res;
}

citygml::Envelope citygmlHandler::getEnvelopeFromModel()
{
    double lowerX = DBL_MAX, lowerY = DBL_MAX, upperX = -DBL_MAX, upperY = -DBL_MAX;

    const citygml::CityObjectsMap& cityObjectsMap = _city->getCityObjectsMap();
    citygml::CityObjectsMap::const_iterator it = cityObjectsMap.begin();

    for ( ; it != cityObjectsMap.end(); it++ )
    {
        const citygml::CityObjects& objList = it->second;
        #pragma omp parallel for
        for(unsigned int i=0 ; i<objList.size() ; i++)
        {
            citygml::CityObject *ob = objList.at(i);
            citygml::Envelope e = ob->getEnvelope();

            lowerX = e.getLowerBound().x<lowerX ? e.getLowerBound().x : lowerX;
            lowerY = e.getLowerBound().y<lowerY ? e.getLowerBound().y : lowerY;
            upperX = e.getUpperBound().x>upperX ? e.getUpperBound().x : upperX;
            upperY = e.getUpperBound().y>upperY ? e.getUpperBound().y : upperY;
        }
    }

    return citygml::Envelope(TVec3d(lowerX,lowerY,0),TVec3d(upperX,upperY,0));
}

void citygmlHandler::drawObject(citygml::CityObject *obj)
{
    for(unsigned int i=0 ; i<obj->size() ; i++)
    {
        const citygml::Geometry *geo = obj->getGeometry(i);
        if(geo->getLOD() >= _params.minLOD && geo->getLOD() <= _params.maxLOD)
        {
            const citygml::Polygon *pol = geo->operator [](0);

            TVec4f col = obj->getDefaultColor();
            glColor4f(col.r,col.g,col.b,col.a);

            drawPolygone(pol);
        }
    }
}

void citygmlHandler::drawPolygone(const citygml::Polygon *pol)
{
    const citygml::Texture *tex = pol->getTexture();
    citygml::TexCoords texCoords;

    if(tex)
    {
        applyTexture(QString(tex->getUrl().c_str()));
        texCoords =  pol->getTexCoords();
    }

    glBegin(GL_POLYGON);
    for(unsigned int i=0 ; i<pol->getVertices().size() ;i++)
    {
        TVec3d ver = pol->getVertices()[i];
        if(tex)
        {
            glColor4f(255,255,255,255);
            glTexCoord2f(texCoords.at(i).x, texCoords.at(i).y);
        }
        glVertex3f(ver.x, ver.y, ver.z);
    }
    glEnd();

}