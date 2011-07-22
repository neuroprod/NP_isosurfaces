#include "Particles.h"

// constructor
Particles::Particles() {
}

void Particles::setup() {
    x =ofRandom(100,boxsize-200);
    y=ofRandom(100,boxsize-200);
    z =ofRandom(100,boxsize-200);
    
    velX   =ofRandom(-6,6);
    velY   =ofRandom(-6,6);

    velZ   =ofRandom(-6,6);

    
}

void Particles::update() {

    x+=velX;
    y+=velY;
    z+=velZ;
    
    // check boundaries
    if(x<100 || x>boxsize-200) velX*=-1;
    if(y<100 || y>boxsize-200) velY*=-1;
    if(z<100 || z>boxsize-200) velZ*=-1;
}



