#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QtOpenGL>
#include "mqcam.h"
#include "citygmlhandler.h"

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);
    ~GLWidget();

protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent( QKeyEvent *keyEvent );
    void timerEvent(QTimerEvent);

public:
    mqCam *_qCam;
    citygmlHandler cgml;

};

#endif // GLWIDGET_H
