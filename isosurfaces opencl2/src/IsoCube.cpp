//
//  IsoCube.cpp
//  emptyExample
//
//  Created by Kris Temmerman on 17/07/11.
//  Copyright 2011 Neuro Productions. All rights reserved.
//

#include "IsoCube.h"

void IsoCube::setup(int _resolution)
{
    resolution =_resolution;
    int i;
    int j;
    int k;
    
  
    
    float  gridsize = point3->x-point2->x;
    
    int count=0;
    float step =gridsize/resolution;
    resolution+=1;
   
   //// cout << gridsize<< " "<< step<<" \n";
    for(i =0;i<resolution;i++)
    {
        for(j=0;j<resolution;j++)
        {
            for (k=0;k<resolution;k++)
            {
                IsoPoint *point =new IsoPoint();
                point->x =i*step+point1->x;
                point->y =j*step+point1->y;
                point->z =k*step+point1->z;
                //cout <<"->"<<point->x<<" " << point->y<<" " << point->z<<"<- ";
                
                isoPoints.push_back(point);
                
              
            }
        }
    }
    
    for(i =0;i<resolution-1;i++)
    {
        for(j=0;j<resolution-1;j++)
        {
            for (k=0;k<resolution-1;k++)
            {
                IsoCube *cube =new IsoCube();
                cube->point1 = isoPoints[getPointPos(i,j,k)];
                
              

                cube->point2 = isoPoints[getPointPos(i+1,j,k)];
                cube->point3 = isoPoints[getPointPos(i+1,j,k+1)];
                cube->point4 = isoPoints[getPointPos(i,j,k+1)];
                
                cube->point5 = isoPoints[getPointPos(i,j+1,k)];
                cube->point6 = isoPoints[getPointPos(i+1,j+1,k)];
                cube->point7 = isoPoints[getPointPos(i+1,j+1,k+1)];
                cube->point8 = isoPoints[getPointPos(i,j+1,k+1)];
               
                isoCubes.push_back(cube);
            

            }
        }
    }

}
int IsoCube::getPointPos(int x,int y, int z)
{
    return x+y*resolution+z*resolution*resolution;
}