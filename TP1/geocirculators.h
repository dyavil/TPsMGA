#ifndef GEOCIRCULATORS_H
#define GEOCIRCULATORS_H
#include "mymesh.h"

class MyMesh;

class circulateur_de_faces{
public:
    circulateur_de_faces(MyTriangleAug * ft, Sommet & p, MyMesh * m):start(ft), current(ft), pivot(p), mesh(m){}
    circulateur_de_faces operator =(MyTriangleAug* s){current = s; return *this;};
    bool operator !=(MyTriangleAug* s){if(current != s) return true; return false;};
    MyTriangleAug * debut(){return start;};
    MyTriangleAug * operator ++();
    MyTriangleAug * operator *(){return current;};
    void getIdSommet();

private:

    Sommet & pivot;
    MyTriangleAug * current;
    MyTriangleAug * start;
    MyMesh * mesh;
    unsigned int indexPivot;
};

class circulateur_de_sommets{
public:
    circulateur_de_sommets(MyTriangleAug * ft, Sommet & p, MyMesh * m):currentT(ft), start(ft), current(&p), pivot(p), mesh(m), last(false){}
    circulateur_de_sommets operator =(Sommet* s);
    bool operator !=(Sommet* s){if(current != s) return true; return false;};
    Sommet * debut();
    Sommet * operator ++();
    Sommet * operator *(){return current;};
    void getIdSommet();

private:

    Sommet & pivot;
    Sommet * startP;
    Sommet * current;
    MyTriangleAug * currentT;
    MyTriangleAug * start;
    MyMesh * mesh;

    bool last;
    unsigned int indexPivot;
};


#endif // GEOCIRCULATORS_H
