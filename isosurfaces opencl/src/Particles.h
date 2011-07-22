#pragma once

#include "ofMain.h"

class Particles  {
public:

    Particles();
 ofVec3f *center;
    ofVec3f *position;
    ofVec3f *direction;
    float speed;
    

    float x;
    float y;
    float z;
    float atr;
    float velX;
    float velY;
    float velZ;
    
    float boxsize;

    void setup();
    void update();
   

};
