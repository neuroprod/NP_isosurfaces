#include "Particles.h"

// constructor
Particles::Particles() {
    center =new ofVec3f(350,350,350);
}

void Particles::setup() {
    x =ofRandom(100,boxsize-200);
    y=ofRandom(100,boxsize-200);
    z =ofRandom(100,boxsize-200);
    
    float velX   =ofRandom(-16,16);
    float velY   =ofRandom(-16,16);

    float velZ   =ofRandom(-16,16);
    
    position = new ofVec3f(x,y,z);
    direction =new ofVec3f(velX,velY,velZ);
    direction->normalize();
    speed =ofRandom(7,15);
    atr =ofRandom(1,2);
}

void Particles::update() {
    
    if(ofRandom(100)>99){
    speed =ofRandom(7,15);
        atr =ofRandom(1,2);}
    
    
    ofVec3f dir =*position-*center ;
   // float distsq = dir.lengthSquared();
   dir.normalize();
    *direction -= dir*atr;
    
    direction->normalize();
    *direction *= speed;
    *position+=*direction;
    //cout << *direction <<"-- "<< *position << "--"<<dir<<"\n"; 
    x =position->x;//*1.3 -100;
    y =position->y;//*1.3-100;
    z =position->z;//*1.3-100;
}



