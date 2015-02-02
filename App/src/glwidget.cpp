 #include "glwidget.h"

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    _qCam = new mqCam(-1,-1,0,1,1,-4.0);
}

GLWidget::~GLWidget()
{
    delete _qCam;
}

void GLWidget::initializeGL()
{
    glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void GLWidget::resizeGL(int width, int height)
{
    if(height == 0) height = 1;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)width/(GLfloat)height, 0.1f, 1000.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    _qCam->look();

    glColor3f(0,1,0);
    glBegin(GL_POLYGON);
        glVertex3f(-1000,-1000,-0.5);
        glVertex3f(-1000,+1000,-0.5);
        glVertex3f(+1000,+1000,-0.5);
        glVertex3f(+1000,+1000,-0.5);
    glEnd();

    cgml.drawModel();
}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
    _qCam->mouse(event);
    updateGL();
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    _qCam->motion(event);
    updateGL();
}

void GLWidget::keyPressEvent(QKeyEvent *keyEvent)
{
    _qCam->keyboard(keyEvent);
    updateGL();

}

void GLWidget::timerEvent(QTimerEvent)
{
    updateGL();
}
