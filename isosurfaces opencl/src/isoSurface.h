

#pragma once

#include "ofMain.h"
#include "Particles.h"
#include "IsoCube.h"
#include "IsoPoint.h"
#include "IsoTriangle.h"
#include "MSAOpenCL.h"
#import "MSAOpenCLTypes.h"

class isoSurface {
public:

    isoSurface();
    
    MSA::OpenCL			opencl;
    MSA::OpenCLProgram	*clProgram;
    MSA::OpenCLKernel	*kernel;
    MSA::OpenCLBuffer	clMemParticles;	
 
    MSA::OpenCLBuffer   clMemPoints;
    MSA::OpenCLBuffer   clMemNormals;
    
    float4 * normalPointer;
   float4  *partData;
    float *openglbuffer;
    int numTriangles;
    int getPointPos(int x,int y, int z);
    void updatePoints();
    void updateCubes();
    void updateCL();
    vector<Particles> particles;
    
    float gridsize;
    int resolution;

    float isoValue;

    vector<IsoCube*> isoCubes;
    vector<IsoPoint*> isoPoints;
    
    
    vector<IsoPoint> isoVertices;
    vector<IsoPoint*> pointVector;
    map<int,IsoPoint> pointMap;
    map<int,IsoPoint>::iterator pointIt;
    
  
    vector< vector<IsoPoint> > triangles;

    int edgeTable[255];
    int triTable[255][16];

    IsoPoint vertexInterpolation(IsoPoint point1, IsoPoint point2);
    IsoPoint* getPoint(IsoPoint *point);
    void setup();
    void update();
    void draw();

};
