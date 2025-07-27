#include "object.h"
#include "utils.h"

float object::SDF(const Vektor p) { std::cout << "WRONG SDF MAN";  return INFINITY; }

float Sphere::SDF(const Vektor p) {
    return (utils::distance(p, getPos()))-r;
    // float b,t,h;
    // b = t = h = r*2*r*2;
    // return (2/b*(p[0]*p[0]) + 2/h*(p[1]*p[1]) + 2/t*(p[2]*p[2]))-r;
}
Vektor object::getNormal(Vektor p) {
    float epsi = 0.001;

    float dx = SDF(p+Vektor(epsi, 0, 0))-SDF(p-Vektor(epsi, 0, 0));
    float dy = SDF(p+Vektor(0, epsi, 0))-SDF(p-Vektor(0, epsi, 0));
    float dz = SDF(p+Vektor(0, 0, epsi))-SDF(p-Vektor(0, 0, epsi));

    return utils::normalize(Vektor(dx,dy,dz));
}


float Point::SDF(const Vektor p) {
    return utils::distance(p, getPos());
}

