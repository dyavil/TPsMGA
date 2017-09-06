#ifndef GLDISPLAY_H
#define GLDISPLAY_H

#include <QGLWidget>
#include <gasket.h>
#include <QMouseEvent>

class GLDisplay : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLDisplay(QWidget *parent = 0);

    virtual void initializeGL();

    virtual void paintGL();

    virtual void resizeGL(int w, int h);

    virtual void changeColor();

    virtual void zoomIn();

    virtual void zoomOut();

    virtual void modeDraw(int m);

protected:
    virtual void mouseMoveEvent ( QMouseEvent * event );
    virtual void mousePressEvent ( QMouseEvent * event );

private:
    void drawSierpinski();
    Gasket gasket;

    float _angle;
    QPoint _position;
    float _zoom;
    int _mode;
    int _colorM;
    
signals:
    
public slots:
    
};

#endif // GLDISPLAY_H
