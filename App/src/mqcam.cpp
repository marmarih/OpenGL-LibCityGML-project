#include "mqcam.h"

int ppx=0,ppy=0,mmvt;

// fonction qui renvoie la vitesse de translation de la caméra
float mqCam::xyzSpeed() const
{
    return _xyzSpeed;
}

// fonction qui affecte son paramètre à la variable _xyzSpeed qui présente la vitesse de translation de la caméra
// elle renvoie vrai si le paramètre est à la fois >0 et < à la vitessse maximale de translation  
bool mqCam::setXyzSpeed(float xyzSpeed)
{
    if(xyzSpeed<0 || xyzSpeed>MAX_XYZ_SPEED) return false;
    _xyzSpeed = xyzSpeed;
    return true;
}

// fonction qui renvoie la vitesse de rotation de la caméra
float mqCam::rotSpeed() const
{
    return _rotSpeed;
}


// fonction qui affecte son paramètre à la variable _xyzSpeed qui présente la vitesse de rotation de la caméra
// elle renvoie vrai si le paramètre est à la fois >0 et < à la vitessse maximale de rotation
bool mqCam::setRotSpeed(float rotSpeed)
{
    if(rotSpeed<0 || rotSpeed>MAX_ROT_SPEED) return false;
    _rotSpeed = rotSpeed;
    return true;
}

// constructeur avec deux paramètres :le vecteur position de la caméra et le vecteur position du point cible
mqCam::mqCam(QVector3D posCam, QVector3D posTar)
{
    setPosCam(posCam);
    setPosTar(posTar);

    _up    = QVector3D(0,0,1);
    _fwd   = posTar-posCam; _fwd.normalize();
    _right = QVector3D::crossProduct(_fwd,_up);

    _xyzSpeed = 1;
    _rotSpeed = 2;
}

// constructeur avec 6 paramètres : X, Y et Z de la position de la caméra et X, Y et Z de la position du point cible
mqCam::mqCam(float xCam, float yCam, float zCam,
             float xTar, float yTar, float zTar)
{
    setPosCam(QVector3D(xCam,yCam,zCam)); // set le vecteur position de la caméra : _posCam
    setPosTar(QVector3D(xTar,yTar,zTar)); // set le vecteur position du point cible : _posTar

    _up    = QVector3D(0,0,1);
    _fwd   = (posTar()-posCam());   _fwd.normalize();
    _right = QVector3D::crossProduct(_fwd,_up);

    _xyzSpeed = 1;
    _rotSpeed = 2;
}

// fonction qui place la caméra dans la position _posCam et fixe le point de vision à _posTar
void mqCam::look()
{
    gluLookAt(_posCam.x(),_posCam.y(),_posCam.z(),
              _posTar.x(),_posTar.y(),_posTar.z(),
              _up.x(),_up.y(),_up.z());
}

// fonction qui prend en paramètre les positions de la caméra et du point cible
//puis elle initialise les variables avec les valeurs en entrée 
void mqCam::lookAt(QVector3D posCam, QVector3D posTar)
{
    setPosCam(posCam);
    setPosTar(posTar);
    _up    = QVector3D(0,0,1);
    _fwd   = posTar-posCam; _fwd.normalize();
    _right = QVector3D::crossProduct(_fwd,_up);
    look();
}

// définition des fonctionnalités des clicks souris

void mqCam::mouse(QMouseEvent *event)
{
    mmvt = event->button() == Qt::LeftButton && event->buttons() == Qt::LeftButton;
    if(!mmvt) return;
    ppx = event->x();
    ppy = event->y();

}

void mqCam::motion(QMouseEvent *event)
{
    if(!mmvt) return;

    float yaw   = -(event->x()-ppx)*_rotSpeed/100;
    float pitch = -(event->y()-ppy)*_rotSpeed/100;

    yawPitch(yaw,pitch);

    ppx = event->x();
    ppy = event->y();
}

// définition des fonctionnalités des touches clavier
void mqCam::keyboard(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Z:
        _posCam += _fwd*_xyzSpeed;
        break;
    case Qt::Key_S:
        _posCam -= _fwd*_xyzSpeed;
        break;
    case Qt::Key_Q:
        _posCam -= _right*_xyzSpeed;
        break;
    case Qt::Key_D:
        _posCam += _right*_xyzSpeed;
        break;
    case Qt::Key_A:
        roll(_rotSpeed);
        break;
    case Qt::Key_E:
        roll(-_rotSpeed);
        break;
    case Qt::Key_Plus:
        _posCam += _up*_xyzSpeed;
        break;
    case Qt::Key_Minus:
        _posCam -= _up*_xyzSpeed;
        break;
    case Qt::Key_I:
        lookBehind();
        break;
    case Qt::Key_Escape:
        exit(0);
        break;
    default:
        break;
    }
    _posTar = _posCam + _fwd;
}


void mqCam::yawPitch(float yaw, float pitch)
{
    QQuaternion y = QQuaternion::fromAxisAndAngle(_up,yaw);
    QQuaternion p = QQuaternion::fromAxisAndAngle(_right,pitch);

    QQuaternion u(0,_fwd);
    QQuaternion v(0,_up);
    QQuaternion w(0,_right);

    u = (p*y)*u*(y.conjugate()*p.conjugate());
    v = (p*y)*v*(y.conjugate()*p.conjugate());
    w = (p*y)*w*(y.conjugate()*p.conjugate());

    _fwd   = u.vector();
    _up    = v.vector();
    _right = w.vector();

    _posTar = _posCam + _fwd;

}

void mqCam::lookBehind()
{
    QVector3D posCamTemp(_posCam);
    _posCam = _posTar;
    _posTar = posCamTemp;

    _right = -_right;
    _fwd   = -_fwd;
}

void mqCam::roll(float angle)
{
    QQuaternion q = QQuaternion::fromAxisAndAngle(_fwd,angle);

    QQuaternion u(0,_up);

    u = q*u*q.conjugate();

    _up = u.vector();
    _right = QVector3D::crossProduct(_fwd,_up);
}

// fonction qui renvoie le vecteur position de la caméra
QVector3D mqCam::posCam() const
{
    return _posCam;
}

// fonction setter qui affecte son paramètre ( vecteur ) à la variable _posCam qui constitue le vecteur position de la caméra
bool mqCam::setPosCam(QVector3D posCam)
{
    if(posCam.isNull()) return false;
    _posCam = posCam;
    return true;
}

// fonction qui renvoie le vecteur position du point cible
QVector3D mqCam::posTar() const
{
    return _posTar;
}

// fonction setter qui affecte son paramètre ( vecteur ) à la variable _posTar qui constitue le vecteur position du point cible
bool mqCam::setPosTar(QVector3D posTar)
{
    if(posTar.isNull()) return false;
    _posTar = posTar;
    return true;
}



