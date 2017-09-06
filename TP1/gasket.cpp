#include "gasket.h"
#include <GL/gl.h>
#include <cstdlib>
#include <time.h>


#define POINTS 6000
#define CONTROL_VERTICES 4

Gasket::Gasket()
{
    point vertices[CONTROL_VERTICES] = {
        {-1.0f, -1.0f, 1.0f},
        {0.0f,  1.0f, 1.0f},
        {1.0f, -1.0f, 1.0f},
        {0.0f, 0.0f, -1.0f}
    };

    points = new point[POINTS];

    point p = {0.0, 0.0, 0.0};

    srand(time(NULL));

    for( int i = 0; i < POINTS; i++ ) {
        int index = rand() % CONTROL_VERTICES;

        point newPoint = { (vertices[index].x + p.x) / 2.0,
                           (vertices[index].y + p.y) / 2.0,
                           (vertices[index].z + p.z) / 2.0};

        p = newPoint;
        points[i] = newPoint;
    }
}

void Gasket::draw(int m)
{
    if(m == 1) mesh.drawLine();
    else if(m == 2) mesh.drawTriangle();
    else mesh.draw();
    /*glBegin(GL_POINTS);

    for( int i = 0; i < POINTS; i++ ) {
        glVertex3f(points[i].x, points[i].y, points[i].z);
    }

    glEnd();*/
}


void Gasket::switchColor(int c){
    switch (c) {
    case 1:
        glColor3f(1.0, 0.0, 0.0);
        break;
    case 2:
        glColor3f(1.0, 0.0, 1.0);
        break;
    default:
        glColor3f(1.0, 1.0, 0.0);
        break;
    }

}
