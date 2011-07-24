//
//  IsoPoint.cpp
//  emptyExample
//
//  Created by Kris Temmerman on 17/07/11.
//  Copyright 2011 Neuro Productions. All rights reserved.
//

#include "IsoPoint.h"
#include "ofMain.h"

IsoPoint::IsoPoint()
{

}

void IsoPoint::setID()
{
   // id = x+(y*1000)+(z*1000000);
    //cout<<" id:"<< id <<" ";
}
void IsoPoint::normalize()
{

    
    float length = sqrt(xn*xn +yn*yn +zn*zn);
    xn/=length;
    yn/=length;
    zn/=length;
//cout << "normal "<<xn <<" "<<yn<<" "<< zn<<" "<<length <<" \n";

}