#include "utils.h"
#include <cmath>
#include <iostream>

Vektor operator+(const Vektor A, const Vektor B) {
    Vektor v(0,0);
    for(int i = 0; i < 3; i++) {
        v[i] = A[i] + B[i];
    }
    return v;
}

Vektor operator-(const Vektor A, const Vektor B) {
    Vektor v(0,0);
    for(int i = 0; i < 3; i++) {
        v[i] = A[i] - B[i];
    }
    return v;
}

float Vektor::operator*(const Vektor other) {
    float s = 0;
    for(int i = 0; i < 3; i++) {
        s += this->data[i]*other[i];
    }
    return s;
}

Vektor Vektor::operator*(float s) {
    return Vektor(this->data[0]*s, this->data[1]*s, this->data[2]*s);
}

float Vektor::length() {
    float sum = 0;
    for(int i = 0; i < 3; i++) {
        sum+=data[i]*data[i];
    }
    return std::sqrt(sum);
}

float utils::distance(const Vektor a, const Vektor b) {
    Vektor v(0,0);
    v = a-b;
    return v.length();
}

Vektor utils::cross(Vektor a, Vektor b) {
    Vektor v;

    v[0] = a[1]*b[2] - a[2]*b[1];
    v[1] = a[2]*b[0] - a[0]*b[2];
    v[2] = a[0]*b[1] - a[1]*b[0];
    
    return v;
}

Vektor utils::normalize(Vektor a) {
    float len = 1/a.length();
    return a*len;
}