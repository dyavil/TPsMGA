#ifndef MYMESH_H
#define MYMESH_H

#include "vector"
#include "string"
#include "iostream"
#include "fstream"
#include "mytriangle.h"
#include "mypoint.h"
#include <GL/gl.h>

class MyMesh
{
public:
    MyMesh();
    void draw();
    void drawLine();
    void drawTriangle();
    void load(std::string filename);

private:
    std::vector<MyTriangle> triangles;
    std::vector<MyPoint> sommets;
};

#endif // MYMESH_H
