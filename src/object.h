#pragma once
#include "utils.h"
#include <iostream>

class object {
    Vektor centerPos;
    Vektor RGB;
    public:
        object(int _x, int _y, int _z) : centerPos(_x, _y, _z), RGB() {}
        ~object() {}
        virtual float SDF(const Vektor p);
        Vektor getNormal(const Vektor p);
        Vektor getPos() { return centerPos; }
        Vektor getColor() { return RGB; }
        void setColor(float r, float g, float b) { RGB[0] = r; RGB[1] = g; RGB[2] = b; }
};

class Sphere : public virtual object {
    int r;
    public:
        Sphere(int _x, int _y, int _z, int _r) : object(_x, _y, _z), r{_r} {}
        float SDF(const Vektor p) override;
};

class Point : public object {
    
    public:
        Point(int _x, int _y, int _z) : object(_x, _y, _z) {};
        float SDF(const Vektor p) override;
};

class Light : public Point {
    public: 
        Light() : Light(0,0,0) {}
        Light(int _x, int _y, int _z) : Point(_x, _y, _z) {}
};