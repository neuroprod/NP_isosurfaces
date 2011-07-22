//
//  IsoPoint.h
//  emptyExample
//
//  Created by Kris Temmerman on 17/07/11.
//  Copyright 2011 Neuro Productions. All rights reserved.
//
#pragma once

class IsoPoint
{
    
    public:
    IsoPoint();
    
    unsigned int index;
    
    float x;
    float y;
    float z;
    
    float xn;
    float yn;
    float zn;

    float isoValue;
    int id;
    void setID();
    void normalize();
};