

#pragma once

#include "ofMain.h"
#include "Particles.h"
#include "IsoCube.h"
#include "IsoPoint.h"
#include "IsoTriangle.h"

class isoSurface : public ofNode {
public:

    isoSurface();

    int getPointPos(int x,int y, int z);
    void updatePoints();
    void updateCubes();
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
    
    //vector<IsoTriangle*> triangles;
    
   // vector< vector<ofVec3f> > cubes;
   // vector< vector<float> > isovalues;
    vector< vector<IsoPoint> > triangles;

    int edgeTable[255];
    int triTable[255][16];

    IsoPoint vertexInterpolation(IsoPoint point1, IsoPoint point2);
    IsoPoint* getPoint(IsoPoint *point);
    void setup();
    void update();
    void customDraw();

};
