#include "gldisplay.h"

GLDisplay::GLDisplay(QWidget *parent) :
    QGLWidget(parent),
    _angle(0.0f),
    _zoom(2.0f),
    _mode(0),
    _colorM(0)
{
}

void GLDisplay::initializeGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glColor3f(1.0, 1.0, 0.0);
}

void GLDisplay::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glScaled(_zoom, _zoom, _zoom);

    glRotatef(_angle, 0.0f, 1.0f, 0.0f);

    gasket.draw(_mode);
}

void GLDisplay::changeColor(){
    if(_colorM > 1) _colorM = 0;
    else _colorM++;
    gasket.switchColor(_colorM);
    updateGL();
}

void GLDisplay::modeDraw(int m){
    _mode = m;
    updateGL();
}

void GLDisplay::zoomIn(){
    _zoom = _zoom + 0.2f;
    updateGL();
}

void GLDisplay::zoomOut(){
    _zoom = _zoom - 0.2f;
    updateGL();
}

void GLDisplay::resizeGL(int w, int h)
{
    glMatrixMode(GL_PROJECTION);

    glViewport(0, 0, w, h);
    glScaled(_zoom, _zoom, _zoom);
    glOrtho(-1.5f, 1.5f, -1.5f, 1.5f, -1.5f, 1.5f);

    //glOrtho(0.0f, windowWidth, windowHeight, 0.0f, 0.0f, 1.0f);

    glMatrixMode(GL_MODELVIEW);
}

void GLDisplay::mouseMoveEvent(QMouseEvent *event)
{
    if( event != NULL ) {
        QPoint position = event->pos();

        _angle += (position.x() - _position.x());

        _position = position;

        updateGL();
    }
}

void GLDisplay::mousePressEvent(QMouseEvent *event)
{
    if( event != NULL )
        _position = event->pos();
}
