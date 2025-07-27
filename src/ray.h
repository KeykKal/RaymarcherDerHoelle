#pragma once
#include "object.h"
#include "utils.h"
static const float MAX_RADIUS = 100.0f;
static const float MAX_STEPS = 100.;
static const float MIN_RADIUS = 0.001f;

struct RayHit {
    bool hit;//if hit or not
    Vektor pos;
    int iter; //iterationen bis er ihrgentwas getroffen hat
    object* hittetObj;
};

struct Ray {
    static const int MAX_DIST = 100;
    Vektor startPos;
    Vektor dir;
};
