#include "mainwindow.h"
#include "ui_mainwindow.h"


//constructeur
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}


// destructeur
MainWindow::~MainWindow()
{
    delete ui;
}


//fonction qui charge le fichier cityGML
void MainWindow::on_openButton_clicked()
{
// bouton pour le chargement du fichier cityGML
    QString filename= QFileDialog::getOpenFileName(
                this,
                tr("Ouvrir un fichier"),
                "./",
                "All files (*.*ml*);;Text File (*.xml);;");

    if(filename.isEmpty()) return;
	
// chargement du fichier cityGML
    ui->glWidget->cgml.loadFile(filename);

// récupération des coordonnées de l'envelope du fichier et les affecter à la variable env
    QMap<QString,double> env = ui->glWidget->cgml.getEnvelope();
// appel d la fonction lookAt avec des paramètres qui correspondent aux coordonnées de l'enveloppe
    ui->glWidget->_qCam->lookAt(QVector3D(env["xCam"],env["yCam"],env["zCam"]),
                            QVector3D(env["xTar"],env["yTar"],env["zCam"]));

    unsigned int * minmax = ui->glWidget->cgml.getMinMaxLOD();

    ui->glWidget->cgml.setLOD(minmax[0],minmax[1]);

    ui->lodMin->setMinimum(minmax[0]);  ui->lodMin->setValue(minmax[0]);
    ui->lodMax->setMinimum(minmax[0]);
    ui->lodMin->setMaximum(minmax[1]);
    ui->lodMax->setMaximum(minmax[1]);  ui->lodMax->setValue(minmax[1]);

    ui->glWidget->setFocus();
}

void MainWindow::on_lodMin_valueChanged(int nMin)
{
    ui->lodMax->setMinimum(nMin);
    ui->glWidget->cgml.setLOD(nMin,ui->lodMax->value());

    ui->glWidget->setFocus();
}

void MainWindow::on_lodMax_valueChanged(int nMax)
{
    ui->lodMin->setMaximum(nMax);
    ui->glWidget->cgml.setLOD(ui->lodMin->value(),nMax);

    ui->glWidget->setFocus();
}

void MainWindow::on_lookAt_clicked()
{
    QVector3D cam(ui->xCam->value(),ui->yCam->value(),ui->zCam->value());
    QVector3D tar(ui->xTar->value(),ui->yTar->value(),ui->zTar->value());

    ui->glWidget->_qCam->lookAt(cam,tar);

    ui->glWidget->setFocus();
}


void MainWindow::on_xyzSpeed_valueChanged(double v)
{
    ui->glWidget->_qCam->setXyzSpeed(v);
}

void MainWindow::on_rotSpeed_valueChanged(double v)
{
    ui->glWidget->_qCam->setRotSpeed(v);
}
