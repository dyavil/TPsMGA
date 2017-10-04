        #ifndef GEOMETRYAUG_H
    #define GEOMETRYAUG_H

    #include "mypoint.h"
    #include "mytriangle.h"
    #include "iostream"
    #include <string>



    class Sommet
    {
    public:
        Sommet(MyPoint _p, int _idT);
        ~Sommet(){}
        MyPoint getPoint(){return p;};
        unsigned int getCorrespTriangle(){return idTriangle;};
        void setCorrespTriangle(unsigned int idT){idTriangle = idT;};
        bool operator ==(Sommet & comp);
        std::string toString(){
            std::string r = ("x : "+ std::to_string(p.getX()) + ", y : " + std::to_string(p.getY()) + ", z : "
                             + std::to_string(p.getZ()) );
                               return r;};

    private:
        MyPoint p;
        unsigned int idTriangle;
    };

    class MyTriangleAug{
    public:
        MyTriangleAug(MyTriangle t, unsigned int v0, unsigned int v1, unsigned int v2);
        MyTriangle & getTriangle(){return triangle;};
        bool operator ==(MyTriangleAug & comp);
        bool operator !=(MyTriangleAug & comp);
        unsigned int getT0(){return t0;};
        void setT0(unsigned int nt0){t0 = nt0;};
        unsigned int getT1(){return t1;};
        void setT1(unsigned int nt1){t1 = nt1;};
        unsigned int getT2(){return t2;};
        void setT2(unsigned int nt2){t2 = nt2;};
        std::string toString(){
            std::string r = ("T0 : "+ std::to_string(t0) + ", T1 : " + std::to_string(t1) + ", T2 : "
                             + std::to_string(t2) + "\nPoints : P0 : " + std::to_string(triangle.getP0())
                             + ", P1 : " + std::to_string(triangle.getP1()) + ", P2 : " + std::to_string(triangle.getP2()));
                               return r;};

        void addNeighbor(unsigned int idt, int a1, int a2);

    private:
        MyTriangle triangle;
        unsigned int t0;
        unsigned int t1;
        unsigned int t2;

    };




    #endif // GEOMETRYAUG_H
