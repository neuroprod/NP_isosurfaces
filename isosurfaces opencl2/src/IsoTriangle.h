//
//  IsoTriangle.h
//  emptyExample
//
//  Created by Kris Temmerman on 18/07/11.
//  Copyright 2011 Neuro Productions. All rights reserved.
//
#pragma once

#include "IsoPoint.h"
class IsoTriangle 
{
public:
    IsoPoint *p1;
    IsoPoint *p2;
    IsoPoint *p3;
    
    float nX;
    float nY;
    float nZ;
    
    
    void calculateNormal();
    
    
};