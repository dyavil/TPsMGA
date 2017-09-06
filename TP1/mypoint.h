#ifndef MYPOINT_H
#define MYPOINT_H




class MyPoint{
public:
    MyPoint(float _x, float _y, float _z):x(_x), y(_y), z(_z){};
    ~MyPoint(){};
    void getVals(float& rx, float& ry, float& rz);
    float getX(){return x;};
    float getY(){return y;};
    float getZ(){return z;};

private:
    float x, y, z;
};

#endif // MYPOINT_H
