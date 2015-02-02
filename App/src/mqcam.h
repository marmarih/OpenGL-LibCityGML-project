#ifndef MQCAM_H
#define MQCAM_H

#include <GL/glu.h>
#include <QQuaternion>
#include <QMouseEvent>
#include <QKeyEvent>

#define MAX_XYZ_SPEED 10
#define MAX_ROT_SPEED 10

class mqCam
{

// déclaration des attributs privés
private:

// instanciation des objets de la classe QVector3D (vecteur 3D)
    QVector3D _posCam,_posTar;
    QVector3D _up,_right,_fwd;
	
// la vitesse de translation et de rotation
    float _xyzSpeed;
    float _rotSpeed;

// déclaration des méthodes
public:

// les constructeurs
    mqCam(QVector3D posCam, QVector3D posTar);
    mqCam(float xCam, float yCam, float zCam,
          float xTar, float yTar, float zTar);

// autres méthodes
    void look();
    void lookAt(QVector3D posCam, QVector3D posTar);
    void mouse(QMouseEvent *event);
    void motion(QMouseEvent *event);
    void keyboard(QKeyEvent *event);
    void roll(float angle);
    void yawPitch(float yaw, float pitch);

    void lookBehind();

    QVector3D posCam() const;
    bool setPosCam(QVector3D posCam);
    QVector3D posTar() const;
    bool setPosTar(QVector3D posTar);
    float xyzSpeed() const;
    bool setXyzSpeed(float xyzSpeed);
    float rotSpeed() const;
    bool setRotSpeed(float rotSpeed);
};

#endif // MQCAM_H
