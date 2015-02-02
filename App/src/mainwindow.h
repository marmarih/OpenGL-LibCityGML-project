#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
// constructeur
    explicit MainWindow(QWidget *parent = 0);
// destructeur
    ~MainWindow();

private slots:
    void on_openButton_clicked();

    void on_lodMin_valueChanged(int nMin);

    void on_lodMax_valueChanged(int nMax);

    void on_lookAt_clicked();

    void on_xyzSpeed_valueChanged(double v);

    void on_rotSpeed_valueChanged(double v);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
