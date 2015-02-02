/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
#include "glwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *openButton;
    QLabel *LODMinLabel;
    QLabel *targetCoordLabel;
    QSpinBox *zTar;
    QSpinBox *lodMax;
    QSpinBox *xTar;
    QSpinBox *yTar;
    QDoubleSpinBox *xyzSpeed;
    QSpinBox *yCam;
    QLabel *xyzSpeedLabel;
    QSpinBox *lodMin;
    QLabel *cameraCoordLabel;
    QSpinBox *xCam;
    QSpacerItem *verticalSpacer;
    GLWidget *glWidget;
    QLabel *rotSpeedLabel;
    QSpinBox *zCam;
    QPushButton *lookAt;
    QLabel *LODMaxLabel;
    QDoubleSpinBox *rotSpeed;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(665, 578);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        openButton = new QPushButton(centralWidget);
        openButton->setObjectName(QString::fromUtf8("openButton"));
        openButton->setMinimumSize(QSize(120, 0));
        openButton->setMaximumSize(QSize(130, 16777215));

        gridLayout->addWidget(openButton, 20, 2, 1, 1);

        LODMinLabel = new QLabel(centralWidget);
        LODMinLabel->setObjectName(QString::fromUtf8("LODMinLabel"));

        gridLayout->addWidget(LODMinLabel, 1, 2, 1, 1);

        targetCoordLabel = new QLabel(centralWidget);
        targetCoordLabel->setObjectName(QString::fromUtf8("targetCoordLabel"));

        gridLayout->addWidget(targetCoordLabel, 9, 2, 1, 1);

        zTar = new QSpinBox(centralWidget);
        zTar->setObjectName(QString::fromUtf8("zTar"));

        gridLayout->addWidget(zTar, 12, 2, 1, 1);

        lodMax = new QSpinBox(centralWidget);
        lodMax->setObjectName(QString::fromUtf8("lodMax"));
        lodMax->setMaximum(4);
        lodMax->setValue(4);

        gridLayout->addWidget(lodMax, 4, 2, 1, 1);

        xTar = new QSpinBox(centralWidget);
        xTar->setObjectName(QString::fromUtf8("xTar"));

        gridLayout->addWidget(xTar, 10, 2, 1, 1);

        yTar = new QSpinBox(centralWidget);
        yTar->setObjectName(QString::fromUtf8("yTar"));

        gridLayout->addWidget(yTar, 11, 2, 1, 1);

        xyzSpeed = new QDoubleSpinBox(centralWidget);
        xyzSpeed->setObjectName(QString::fromUtf8("xyzSpeed"));
        xyzSpeed->setDecimals(2);
        xyzSpeed->setMinimum(0);
        xyzSpeed->setMaximum(10);
        xyzSpeed->setValue(1);

        gridLayout->addWidget(xyzSpeed, 15, 2, 1, 1);

        yCam = new QSpinBox(centralWidget);
        yCam->setObjectName(QString::fromUtf8("yCam"));

        gridLayout->addWidget(yCam, 7, 2, 1, 1);

        xyzSpeedLabel = new QLabel(centralWidget);
        xyzSpeedLabel->setObjectName(QString::fromUtf8("xyzSpeedLabel"));

        gridLayout->addWidget(xyzSpeedLabel, 14, 2, 1, 1);

        lodMin = new QSpinBox(centralWidget);
        lodMin->setObjectName(QString::fromUtf8("lodMin"));
        lodMin->setMaximum(4);

        gridLayout->addWidget(lodMin, 2, 2, 1, 1);

        cameraCoordLabel = new QLabel(centralWidget);
        cameraCoordLabel->setObjectName(QString::fromUtf8("cameraCoordLabel"));

        gridLayout->addWidget(cameraCoordLabel, 5, 2, 1, 1);

        xCam = new QSpinBox(centralWidget);
        xCam->setObjectName(QString::fromUtf8("xCam"));

        gridLayout->addWidget(xCam, 6, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 18, 2, 1, 1);

        glWidget = new GLWidget(centralWidget);
        glWidget->setObjectName(QString::fromUtf8("glWidget"));
        glWidget->setMinimumSize(QSize(512, 500));
        glWidget->setFocusPolicy(Qt::StrongFocus);
        openButton->raise();

        gridLayout->addWidget(glWidget, 1, 0, 21, 2);

        rotSpeedLabel = new QLabel(centralWidget);
        rotSpeedLabel->setObjectName(QString::fromUtf8("rotSpeedLabel"));

        gridLayout->addWidget(rotSpeedLabel, 16, 2, 1, 1);

        zCam = new QSpinBox(centralWidget);
        zCam->setObjectName(QString::fromUtf8("zCam"));

        gridLayout->addWidget(zCam, 8, 2, 1, 1);

        lookAt = new QPushButton(centralWidget);
        lookAt->setObjectName(QString::fromUtf8("lookAt"));

        gridLayout->addWidget(lookAt, 13, 2, 1, 1);

        LODMaxLabel = new QLabel(centralWidget);
        LODMaxLabel->setObjectName(QString::fromUtf8("LODMaxLabel"));

        gridLayout->addWidget(LODMaxLabel, 3, 2, 1, 1);

        rotSpeed = new QDoubleSpinBox(centralWidget);
        rotSpeed->setObjectName(QString::fromUtf8("rotSpeed"));
        rotSpeed->setMaximum(10);
        rotSpeed->setValue(2);

        gridLayout->addWidget(rotSpeed, 17, 2, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 665, 19));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        openButton->setText(QApplication::translate("MainWindow", "Ouvrir un fichier", 0, QApplication::UnicodeUTF8));
        LODMinLabel->setText(QApplication::translate("MainWindow", "LOD min", 0, QApplication::UnicodeUTF8));
        targetCoordLabel->setText(QApplication::translate("MainWindow", "Cible (xyz)", 0, QApplication::UnicodeUTF8));
        lodMax->setSuffix(QString());
        xyzSpeedLabel->setText(QApplication::translate("MainWindow", "Vitesse (XYZ)", 0, QApplication::UnicodeUTF8));
        cameraCoordLabel->setText(QApplication::translate("MainWindow", "Cam\303\251ra (xyz)", 0, QApplication::UnicodeUTF8));
        rotSpeedLabel->setText(QApplication::translate("MainWindow", "Vitesse (rotation)", 0, QApplication::UnicodeUTF8));
        lookAt->setText(QApplication::translate("MainWindow", "Look At", 0, QApplication::UnicodeUTF8));
        LODMaxLabel->setText(QApplication::translate("MainWindow", "LOD max", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
