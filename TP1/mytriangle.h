#ifndef MYTRIANGLE_H
#define MYTRIANGLE_H


class MyTriangle
{
public:
    MyTriangle(unsigned int _p0, unsigned int _p1, unsigned int _p2);
    ~MyTriangle(){}
    unsigned int getP0(){return p0;};
    void setP0(unsigned int idp0){ p0= idp0;};
    unsigned int getP1(){return p1;};
    void setP1(unsigned int idp1){ p1= idp1;};
    unsigned int getP2(){return p2;};
    void setP2(unsigned int idp2){ p2= idp2;};
    unsigned int getOppose(unsigned int po1, unsigned int po2);

private:
    unsigned int p0;
    unsigned int p1;
    unsigned int p2;

};

#endif // MYTRIANGLE_H
