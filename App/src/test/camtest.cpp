#include "camtest.h"

void camTest::testAccessors()
{
    QVector3D posCam(1,1,0), posTar(0,0,0);
    QVector3D posCamBis(2,2,0), posTarBis(4,4,0), pos;
    mqCam cam(posCam,posTar);

    bool res;
    // tests de dépassement de la limite possible de la vitesse
    res = cam.setXyzSpeed(-2);
    if(res==true) QFAIL("setXyzSpeed accepts negative values");
    res = cam.setXyzSpeed(MAX_XYZ_SPEED+1);
    if(res==true) QFAIL("setXyzSpeed accepts values bigger than MAX_XYZ_SPEED");

    res = cam.setRotSpeed(-2);
    if(res==true) QFAIL("setRotSpeed accepts negative values..");
    res = cam.setRotSpeed(MAX_ROT_SPEED+1);
    if(res==true) QFAIL("setRotSpeed accepts values bigger than MAX_ROT_SPEED");

    res = cam.setPosCam(pos);
    if(res==true) QFAIL("setPosCam accepts NULL values");
    res = cam.setPosTar(pos);
    if(res==true) QFAIL("setPosTar accepts NULL values");

    res = cam.setPosCam(posCamBis);
    if(res==false) QFAIL("setPosCam failed in changing the camera's position");
    pos = cam.posCam();
    QCOMPARE(pos,posCamBis);

    res = cam.setPosTar(posTarBis);
    if(res==false) QFAIL("setPosTar failed in changing the target's position");
    pos = cam.posTar();
    QCOMPARE(pos,posTarBis);
}
