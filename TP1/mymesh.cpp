#include "mymesh.h"

MyMesh::MyMesh()
{
    /*MyPoint p1 = MyPoint(0.5, 0.5, 0.5);
    MyPoint p2 = MyPoint(0.5, -0.5, 0.5);
    MyPoint p3 = MyPoint(0.5, 0.5, -0.5);

    sommets.push_back(p1);
    sommets.push_back(p2);
    sommets.push_back(p3);

    MyTriangle t1 = MyTriangle(0, 1, 2);
    triangles.push_back(t1);*/
    load("queen.off");
}

void MyMesh::draw(){
    glBegin(GL_POINTS);

    for( unsigned int i = 0; i < triangles.size(); i++ ) {
        glVertex3f(sommets[triangles[i].getP0()].getX(), sommets[triangles[i].getP0()].getY(), sommets[triangles[i].getP0()].getZ());
        glVertex3f(sommets[triangles[i].getP1()].getX(), sommets[triangles[i].getP1()].getY(), sommets[triangles[i].getP1()].getZ());
        glVertex3f(sommets[triangles[i].getP2()].getX(), sommets[triangles[i].getP2()].getY(), sommets[triangles[i].getP2()].getZ());
    }

    glEnd();
}

void MyMesh::drawLine(){


    for( unsigned int i = 0; i < triangles.size(); i++ ) {
        glBegin(GL_LINE_STRIP);
        glVertex3f(sommets[triangles[i].getP0()].getX(), sommets[triangles[i].getP0()].getY(), sommets[triangles[i].getP0()].getZ());
        glVertex3f(sommets[triangles[i].getP1()].getX(), sommets[triangles[i].getP1()].getY(), sommets[triangles[i].getP1()].getZ());
        glVertex3f(sommets[triangles[i].getP2()].getX(), sommets[triangles[i].getP2()].getY(), sommets[triangles[i].getP2()].getZ());
        glVertex3f(sommets[triangles[i].getP0()].getX(), sommets[triangles[i].getP0()].getY(), sommets[triangles[i].getP0()].getZ());
        glEnd();
    }

}

void MyMesh::drawTriangle(){

    glBegin(GL_TRIANGLES);
    for( unsigned int i = 0; i < triangles.size(); i++ ) {
        glVertex3f(sommets[triangles[i].getP0()].getX(), sommets[triangles[i].getP0()].getY(), sommets[triangles[i].getP0()].getZ());
        glVertex3f(sommets[triangles[i].getP1()].getX(), sommets[triangles[i].getP1()].getY(), sommets[triangles[i].getP1()].getZ());
        glVertex3f(sommets[triangles[i].getP2()].getX(), sommets[triangles[i].getP2()].getY(), sommets[triangles[i].getP2()].getZ());

    }
    glEnd();
}


void MyMesh::load(std::__cxx11::string filename){
    std::ifstream file;
    file.open("/home/dyavil/Documents/Master2/MaillageGeoAlgo/ToLoad/" + filename);
    std::string start;
    file >> start;
    unsigned int nbs, nbf, nbw;
    file >> nbs >> nbf >> nbw;
    float x0, y0, z0;
    for(unsigned int i = 0; i < nbs; i++){
        file >> x0 >> y0 >> z0;
        sommets.push_back(MyPoint(x0, y0, z0));
    }
    unsigned int s, id0, id1, id2;
    for(unsigned int i = 0; i < nbf; i++){
        file >> s >> id0 >> id1 >> id2;
        triangles.push_back(MyTriangle(id0, id1, id2));
    }
    file.close();
}

