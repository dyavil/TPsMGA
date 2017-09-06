#ifndef MYTRIANGLE_H
#define MYTRIANGLE_H


class MyTriangle
{
public:
    MyTriangle(unsigned int _p0, unsigned int _p1, unsigned int _p2);
    ~MyTriangle(){}
    unsigned int getP0(){return p0;};
    unsigned int getP1(){return p1;};
    unsigned int getP2(){return p2;};

private:
    unsigned int p0;
    unsigned int p1;
    unsigned int p2;

};

#endif // MYTRIANGLE_H
