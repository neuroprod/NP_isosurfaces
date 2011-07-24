//
//  IsoCube.h
//  emptyExample
//
//  Created by Kris Temmerman on 17/07/11.
//  Copyright 2011 Neuro Productions. All rights reserved.
//
#pragma once

#include "IsoPoint.h"
#include "ofMain.h"

class IsoCube 
{
public:
    IsoPoint *point1;
    IsoPoint *point2;
    IsoPoint *point3;
    IsoPoint *point4;
    
    IsoPoint *point5;
    IsoPoint *point6;
    IsoPoint *point7;
    IsoPoint *point8;

    
    void setup(int _resolution);
    int getPointPos(int x,int y, int z);
    int resolution;
    vector<IsoCube*> isoCubes;
    vector<IsoPoint*> isoPoints;
};