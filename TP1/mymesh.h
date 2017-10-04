#ifndef MYMESH_H
#define MYMESH_H

#include "vector"
#include "string"
#include "iostream"
#include "fstream"
#include "map"
#include "geometryaug.h"
#include "geocirculators.h"
#include <GL/gl.h>

class circulateur_de_faces;
class circulateur_de_sommets;

class MyMesh
{
public:
    MyMesh();
    void draw();
    void drawLine();
    void drawTriangle();
    void load(std::string filename);
    void loadPoints(std::string filename);
    void triangulationInit();
    unsigned int inTriangle(MyPoint p1);
    void addPoint(unsigned int idTriangle, unsigned int p1);
    void updateNeighbors(unsigned int idtR, unsigned int idtO, unsigned int newid);
    void addPointOut(unsigned int p1);
    void debug();
    void maj(std::map<std::pair<unsigned int, unsigned int>, unsigned int> & corresp, unsigned int id0, unsigned int id1, unsigned int id2);
    circulateur_de_faces faces_incidente(Sommet & v);
    circulateur_de_sommets sommets_adjacents(Sommet & v);
    std::vector<Sommet> & getSommets(){return sommets;};
    std::vector<MyTriangleAug> & getTriangles(){return triangles;};


private:
    std::vector<MyTriangleAug> triangles;
    std::vector<Sommet> sommets;
    typedef std::vector<MyTriangleAug>::iterator face_iterator;
    face_iterator face_begin() { return triangles.begin(); }
    face_iterator face_end() { return triangles.end(); }

    typedef std::vector<Sommet>::iterator sommet_iterator;
    sommet_iterator sommet_begin() { return sommets.begin(); }
    sommet_iterator sommet_end() { return sommets.end(); }
    std::ofstream debugfile;
};

#endif // MYMESH_H
