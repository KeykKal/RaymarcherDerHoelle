#include <cmath>
#include <iostream>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

#include "ray.h"
#include "utils.h"
class cam {
    private:
        Vektor pos; //center pos of camera
        Vektor dir = Vektor(0,0,1);
        Vektor camUp = Vektor(0,1,0);
        Vektor camRight = utils::normalize(utils::cross(dir, camUp));
        //rotation eher nicht kein bock auf quatoren und son scheiß
        //cam guckt also immer rightung positiv Z 
        float fov = 90.;
        float aspect; // = width/height

        public:
        int width, height; //top left = x-(width/2), y-(height/2)
        int maxRays;
        Ray *allRays;

    public:
        cam(int _x, int _y, int _z) : pos(_x, _y, _z) {  
            struct winsize w; 
            ioctl(STDOUT_FILENO, TIOCGWINSZ, &w); 
            width = w.ws_col; height = w.ws_row;
            maxRays = (width * height); allRays = new Ray[maxRays];
            aspect = width/float(height); 
            
            for(int i = 0; i < maxRays; i++) {
                int x = i%width, y = i/width;
                Ray ray;
                // ray.startPos = Vektor(i%width, i/width, 0)-(Vektor(width/2,height/2));
                float px = (2.0 * x / width - 1.0) * aspect;
                float py = 1.0 - 2.0 * y / height;

                ray.startPos = pos; // sonst px und py


                float tanFov = std::tan((fov*0.5)); 

                ray.dir = utils::normalize(dir + (camRight*(px*tanFov)) + (camUp*(py*tanFov)));
                
                allRays[i] = ray;
                x++;
                if(x>width) { x=0; y++; }
            }
            
        }
        cam(int _x, int _y) : cam(_x,_y,0) {}
        cam() : cam(0,0,0) {}
    public:
        Vektor getCenterPos()   { return pos; }
        Vektor getTopLeft()     { return pos+Vektor(-width/2., -height/2., 0); }
        Vektor getTopRight()    { return pos+Vektor(width/2. , -height/2., 0); }
        Vektor getButtomLeft()  { return pos+Vektor(-width/2., height/2. , 0); }
        Vektor getButtomRight() { return pos+Vektor(width/2. , height/2. , 0); }

};