#include "geocirculators.h"


void circulateur_de_faces::getIdSommet(){
    for (int i = 0; i < mesh->getSommets().size(); ++i) {
        if(mesh->getSommets()[i] == pivot) {
            //std::cout << "found" << std::endl;
            indexPivot = i;
        }

        //else std::cout << "notfound" << std::endl;
    }
}

void circulateur_de_sommets::getIdSommet(){
    for (int i = 0; i < mesh->getSommets().size(); ++i) {
        if(mesh->getSommets()[i] == pivot) {
            std::cout << i << std::endl;
            indexPivot = i;
        }
    }
    if(currentT->getTriangle().getP0() == indexPivot) {
        startP = &(mesh->getSommets()[currentT->getTriangle().getP1()]);;
    }
    else if(currentT->getTriangle().getP1() == indexPivot) {
        startP = &(mesh->getSommets()[currentT->getTriangle().getP2()]);;
    }
    else {
        startP = &(mesh->getSommets()[currentT->getTriangle().getP0()]);;
    }
    current = startP;

}

circulateur_de_sommets circulateur_de_sommets::operator =(Sommet* s){
    current = s;
    return *this;
}


Sommet * circulateur_de_sommets::debut(){
    return startP;
}

MyTriangleAug * circulateur_de_faces::operator ++(){

    if(current->getTriangle().getP0() == indexPivot) {
        current = &(mesh->getTriangles()[current->getT1()]);
    }
    else if(current->getTriangle().getP1() == indexPivot) {
        current = &(mesh->getTriangles()[current->getT2()]);
    }
    else {
        current = &(mesh->getTriangles()[current->getT0()]);
    }

    return current;
}


Sommet * circulateur_de_sommets::operator ++(){

    if(currentT->getTriangle().getP0() == indexPivot) {
        currentT = &(mesh->getTriangles()[currentT->getT1()]);
    }
    else if(currentT->getTriangle().getP1() == indexPivot) {
        currentT = &(mesh->getTriangles()[currentT->getT2()]);
    }
    else {
        currentT = &(mesh->getTriangles()[currentT->getT0()]);
    }
    if(currentT->getTriangle().getP0() == indexPivot) {
        current = &(mesh->getSommets()[currentT->getTriangle().getP1()]);
    }
    else if(currentT->getTriangle().getP1() == indexPivot) {
        current = &(mesh->getSommets()[currentT->getTriangle().getP2()]);
    }
    else {
        current = &(mesh->getSommets()[currentT->getTriangle().getP0()]);
    }

    return current;
        /*if(currentT->getTriangle().getP0() == indexPivot) {

            current = &(mesh->getSommets()[currentT->getTriangle().getP2()]);
            currentT = &(mesh->getTriangles()[currentT->getT1()]);
            std::cout << "sommet id : " << currentT->getTriangle().getP2() << std::endl;
        }
        else if(currentT->getTriangle().getP1() == indexPivot) {

            current = &(mesh->getSommets()[currentT->getTriangle().getP0()]);
            currentT = &(mesh->getTriangles()[currentT->getT2()]);
            std::cout << "sommet id : " << currentT->getTriangle().getP0() << std::endl;
        }
        else {

            current = &(mesh->getSommets()[currentT->getTriangle().getP1()]);
            currentT = &(mesh->getTriangles()[currentT->getT0()]);
            std::cout << "sommet id : " <<  currentT->getTriangle().getP1() << std::endl;
        }*/

    //}
}

