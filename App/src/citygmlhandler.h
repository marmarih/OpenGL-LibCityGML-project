#ifndef CITYGMLHANDLER_H
#define CITYGMLHANDLER_H

#include <QString>
#include <QImage>
#include <QtOpenGL>
#include "citygml.h"
#include <omp.h>

class citygmlHandler
{
private:
    citygml::CityModel *_city;
    citygml::ParserParams _params;
    QString fileName;
    QString filePath;
    QMap<QString,GLuint> _texture;

public:
    citygmlHandler();	//constructeur
    ~citygmlHandler();  //destructeur

    void loadFile(QString f);
    void drawModel();
    void setLOD(int min, int max);
    unsigned int *getMinMaxLOD();
    void loadTexture(QString url);
    void applyTexture(QString url);
    QMap<QString, double> getEnvelope();

protected:
    citygml::Envelope getEnvelopeFromModel();
    void drawObject(citygml::CityObject *obj);
    void drawPolygone(const citygml::Polygon *pol);
};

#endif // CITYGMLHANDLER_H
