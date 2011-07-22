//
//  Thing.h
//  emptyExample
//
//  Created by Kris Temmerman on 13/07/11.
//  Copyright 2011 Neuro Productions. All rights reserved.
//

#pragma  once


#include "ofMain.h"

class Thing : public ofNode
{
    
private:    
    
protected:

public:
    ofVec3f *position;

    Thing();
    void customDraw();
    

};