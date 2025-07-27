#pragma once 
#include <vector>
#include <iostream>

#include "camera.h"
#include "object.h"
#include "utils.h"

class Scene {

    private:
        Light light; //zukünfig können mehrere sein.
        std::vector<object*> objs;
        cam camera;
        
    public:
        Scene();
        void render();
    private:
        RayHit rayMarching(Ray r, std::vector<object*> toObjects);
        RayHit rayMarching(Ray r) { return rayMarching(r,objs); }
        // void printInColor(std::string s, Vektor rgb) { printInColor(); }
        void printInColor(std::string s, Vektor tRGB, Vektor bRGB = Vektor()) { std::cout << 
            "\033[38;2;"<<int(tRGB[0])<<";"<<int(tRGB[1])<<";"<<int(tRGB[2])<<"m" <<
            "\033[48;2;"<<int(bRGB[0])<<";"<<int(bRGB[1])<<";"<<int(bRGB[2])<<"m" <<
            s << "\033[0m"; 
        }



};