#pragma once

#include "ofMain.h"

class Particles  {
public:

    Particles();

    

    float x;
    float y;
    float z;
    
    float velX;
    float velY;
    float velZ;
    
    float boxsize;

    void setup();
    void update();
   

};
