#include "mytriangle.h"
#include "iostream"

MyTriangle::MyTriangle(unsigned int _p0, unsigned int _p1, unsigned int _p2)
{
    p0 = _p0;
    p1 = _p1;
    p2 = _p2;
}

unsigned int MyTriangle::getOppose(unsigned int po1, unsigned int po2){
    if((po1 == p0 && po2 == p1) || (po2 == p0 && po1 == p1)){
        return 2;
    }
    else if((po1 == p1 && po2 == p2) || (po2 == p1 && po1 == p2)){
        return 0;
    }
    else if((po1 == p0 && po2 == p2) || (po2 == p0 && po1 == p2))  return 1;
    else {
        return -1;
    }
}

