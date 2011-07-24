#include "Particles.h"

// constructor
Particles::Particles() {
    center =new ofVec3f(350,350,350);
}

void Particles::setup() {
    x =ofRandom(100,boxsize-200);
    y=ofRandom(100,boxsize-200);
    z =ofRandom(100,boxsize-200);
     //center =new ofVec3f(350+ofRandom(-16,16);,350,350);
    float velX   =ofRandom(-16,16);
    float velY   =ofRandom(-16,16);

    float velZ   =ofRandom(-16,16);
    
    position = new ofVec3f(x,y,z);
    direction =new ofVec3f(velX,velY,velZ);
    direction->normalize();
    speed =ofRandom(5,23);
    atr =speed*0.2;

}

void Particles::update(float value =1,float value2 =2) {
    
   if(ofRandom(100)>99){
        center =new ofVec3f(350+ofRandom(-60,60),350+ofRandom(-60,60),350+ofRandom(-60,60));
    //   speed =ofRandom(5,13);
     //  atr =ofRandom(1,3);
    }
    
    
    ofVec3f dir =*position-*center ;
   // float distsq = dir.lengthSquared();
   dir.normalize();
    *direction -= dir*atr;
    
    direction->normalize();
   
    *direction *= speed*value;
    *position+=*direction;
    //cout << *direction <<"-- "<< *position << "--"<<dir<<"\n"; 
    x =position->x;//*1.3 -100;
    y =position->y;//*1.3-100;
    z =position->z;//*1.3-100;
}



