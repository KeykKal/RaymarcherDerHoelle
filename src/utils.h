#pragma once

#include <cmath>
#include <cstddef>
#include <string>
class Vektor {
    float data[3];
    public:
        Vektor() : data{0,0,0} {}
        Vektor(float _x, float _y) : data{_x,_y,0} {}
        Vektor(float _x, float _y, float _z) : data{_x,_y,_z} {}
    public:
        friend Vektor operator+(const Vektor A, const Vektor B);
        friend Vektor operator-(const Vektor A,const Vektor B);
        float operator*(const Vektor other);
        float& operator[](std::size_t idx) { return data[idx]; }
        const float& operator[](std::size_t idx) const { return data[idx]; }
        Vektor operator*(float s);
    public:
        float length();
};

namespace utils {
    const static std::string BRIGHTNESS_LEVEL[] = {" ",
        // " \u258F","\u258E","\u258D","\u258C",
        // "\u258B","\u258A","\u2589","\u2588", 

        "\u2591","\u2592","\u2593","\u2588",
        
    }; //from darkest to brightest " .':/7X@"


    float distance(const Vektor a, const Vektor b);
    Vektor cross(const Vektor a, const Vektor b);
    Vektor normalize(const Vektor a);
}