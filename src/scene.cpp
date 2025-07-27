#include "scene.h"
#include "object.h"
#include "ray.h"
#include "utils.h"
#include <algorithm>
#include <cstddef>
#include <vector>

Scene::Scene() {
    // camera = cam(0,0,0);
    Light* mainLight = new Light(15,5,-2);
    mainLight->setColor(.33f, 0.33f, 0.33f);
    // objs.resize(1);
    light = *mainLight;
    Sphere* sp  = new Sphere(10, 0, 10, 4);
    sp->setColor(0.5f, 0.5f, 0.5f);
    // Sphere* sp1 = new Sphere(10, 2, 10, 10); //für die zunkunft mach das mal einwenig glass artig
    // sp1.name = 420;
    objs.push_back(sp);
    objs.push_back(mainLight);

    // objs.push_back(sp1);
}

void Scene::render() {
    
    for(int i = 0; i < camera.maxRays; i++) {
        Ray r = camera.allRays[i];

        RayHit rayHit = rayMarching(r);
        int brightnessLvl = 1;
        Vektor color = Vektor();

        if(rayHit.hit) {
            //calc light level
            // raymarche zur allen licht quellen
            object* hittetObj = rayHit.hittetObj;
            Ray rayToLight;
            rayToLight.dir = utils::normalize(light.getPos()-rayHit.pos);
            rayToLight.startPos = rayHit.pos+(rayToLight.dir*MIN_RADIUS);
            
            RayHit secondRayFromObject = rayMarching(rayToLight);
            if(secondRayFromObject.hit) {
                object* inTheWayOfLight = secondRayFromObject.hittetObj;
                if(dynamic_cast<Light*>(inTheWayOfLight)) { //ist das zweite obj das getroffen wurde nh lichtquelle?
                    brightnessLvl = 4;
                } else {
                    brightnessLvl = 4;
                }

                // color =  (inTheWayOfLight->getColor()+rayHit.hittetObj->getColor())*.5;
                Vektor normal = hittetObj->getNormal(rayHit.pos);
                // std::cout << normal[0] << " " << normal[1] << " " << normal[2] << ","; 
                float intesivity = std::max((normal*rayToLight.dir), .3f);
                color = Vektor(
                    hittetObj->getColor()[0]*inTheWayOfLight->getColor()[0], 
                    hittetObj->getColor()[1]*inTheWayOfLight->getColor()[1], 
                    hittetObj->getColor()[2]*inTheWayOfLight->getColor()[2]
                )*intesivity;
                brightnessLvl = int(intesivity*3)+1;
            }
            // std::cout << secondRayFromObject.iter;
        }
        printInColor(utils::BRIGHTNESS_LEVEL[brightnessLvl], color*255);
        // std::cout << utils::BRIGHTNESS_LEVEL[brightnessLvl];
    }   
    
    std::cout << "\n\n" << camera.maxRays;
    std::cout << "\n\n" << camera.getTopLeft()[0] << "," <<camera.getTopLeft()[1] << "," <<camera.getTopLeft()[2];  
}

RayHit Scene::rayMarching(Ray r, std::vector<object*> toObjects) {
    Vektor RPos = r.startPos;
    bool hit = false;
    int iter=0;
    object* oHit = nullptr;
    for(int step = 0; step < MAX_STEPS; step++, iter++) {
        float min = 10000000;
        object* oMin = nullptr;
        for(int j = 0; j < toObjects.size(); j++) {
            // Sphere *sp = dynamic_cast<Sphere*>(objs.at(i));
            object* o = toObjects.at(j);
            // if(o!=nullptr) {
                float sdf = o->SDF(RPos);
                if(sdf < min) { min = sdf; oMin = o; }
            // }
        }
        RPos = RPos+(r.dir*min);
        if(min < MIN_RADIUS) { hit = true; oHit = oMin; break; }
    }
    RayHit rh{hit, RPos, iter, oHit}; //oHit kann auch mit oMin ersetzt werden aber ich mag das wenn nicht gehittet wird ein nullpts ist
    return rh;
}