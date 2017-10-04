#include "geometryaug.h"

Sommet::Sommet(MyPoint _p, int _idT):
    p(_p),
    idTriangle(_idT)
{}

bool Sommet::operator ==(Sommet & comp){
    if(this == &comp) return true;
    return false;
}


MyTriangleAug::MyTriangleAug(MyTriangle t, unsigned int v0, unsigned int v1, unsigned int v2):
    triangle(t),
    t0(v0),
    t1(v1),
    t2(v2)
{
}



bool MyTriangleAug::operator ==(MyTriangleAug & comp){
    if(t0 == comp.getT0() && t1 == comp.getT1() && t2 == comp.getT2()) return true;
    return false;
}

bool MyTriangleAug::operator !=(MyTriangleAug & comp){
    if(t0 == comp.getT0() && t1 == comp.getT1() && t2 == comp.getT2()) return false;
    return true;
}

void MyTriangleAug::addNeighbor(unsigned int idt, int a1, int a2)
{
    if(triangle.getOppose(a1, a2) == 0){
        t0 = idt;
    }
    else if(triangle.getOppose(a1, a2) == 1){
        t1 = idt;
    }
    else if(triangle.getOppose(a1, a2) == 2){
        t2 = idt;
    }
    else{
        std::cout << "test" << std::endl;
    }
}
