//
//  Thing.cpp
//  emptyExample
//
//  Created by Kris Temmerman on 13/07/11.
//  Copyright 2011 Neuro Productions. All rights reserved.
//

#include "Thing.h"

Thing::Thing ()
{
    position =new ofVec3f ;
    
    float posX =ofRandom(20);//((rand()/RAND_MAX)-0.5)*100;
    float posY =ofRandom(20);//((rand()/RAND_MAX)-0.5)*100;
    float posZ =ofRandom(20);//((rand()/RAND_MAX)-0.5)*100;
    position->x =posX;
    position->y = posY;
    position->z = posZ;
    
    //= new ofVec3f(posX,posY,posZ);
    setPosition(ofRandomWidth(),ofRandomHeight(),20);

}


void Thing::customDraw()
{
    ofColor(255,0,0);
   // glPushMatrix();
    //cout<< position->x;
    //ofTranslate(position->x,position->y,position->z);
    ofCircle(0,0,0);
    //glPopMatrix();


}

