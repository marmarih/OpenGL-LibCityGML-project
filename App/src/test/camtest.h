#ifndef CAMTEST_H
#define CAMTEST_H

#include <QObject>
#include <QtTest/QtTest>
#include "mqcam.h"

class camTest : public QObject
{
    Q_OBJECT

private slots:
    void testAccessors();

};

#endif // CAMTEST_H
