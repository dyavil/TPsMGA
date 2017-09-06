#ifndef GASKET_H
#define GASKET_H
#include "mymesh.h"
struct point {
    double x, y, z;
};

class Gasket
{
public:
    Gasket();

    void draw(int m);
    void switchColor(int c);

private:
    point * points;
    MyMesh mesh;
};

#endif // GASKET_H
