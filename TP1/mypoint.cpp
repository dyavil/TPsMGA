#include "mypoint.h"
#include "iostream"


void MyPoint::getVals(float &rx, float &ry, float &rz)
{
    rx = x;
    ry = y;
    rz = z;
}

MyPoint MyPoint::prodVec(MyPoint p2){
    MyPoint res = MyPoint(0, 0, 0);
    res.x = y*p2.getZ()-z*p2.getY();
    res.y = p2.x*z-p2.getZ()*x;
    res.z = x*p2.getY()-y*p2.getX();
    return res;
}


MyPoint MyPoint::operator-(MyPoint comp){
    MyPoint res = MyPoint(0, 0, 0);
    res.x = comp.getX()-x;
    res.y = comp.getY()-y;
    res.z = comp.getZ()-z;
    return res;
}
