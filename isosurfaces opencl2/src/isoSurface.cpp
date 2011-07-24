#include "isoSurface.h"

// constructor
isoSurface::isoSurface() {

     int edgeTable1[256] = { 0x0 , 0x109, 0x203, 0x30a, 0x406, 0x50f, 0x605, 0x70c,0x80c, 0x905, 0xa0f, 0xb06, 0xc0a, 0xd03, 0xe09, 0xf00,0x190, 0x99 , 0x393, 0x29a,0x596, 0x49f, 0x795, 0x69c,0x99c, 0x895, 0xb9f, 0xa96, 0xd9a, 0xc93, 0xf99, 0xe90,0x230, 0x339, 0x33 , 0x13a, 0x636, 0x73f, 0x435, 0x53c,0xa3c, 0xb35, 0x83f, 0x936, 0xe3a, 0xf33, 0xc39, 0xd30,0x3a0, 0x2a9, 0x1a3, 0xaa , 0x7a6, 0x6af, 0x5a5, 0x4ac,0xbac, 0xaa5, 0x9af, 0x8a6, 0xfaa, 0xea3, 0xda9, 0xca0,0x460, 0x569, 0x663, 0x76a, 0x66 , 0x16f, 0x265, 0x36c,0xc6c, 0xd65, 0xe6f, 0xf66, 0x86a, 0x963, 0xa69, 0xb60,0x5f0, 0x4f9, 0x7f3, 0x6fa, 0x1f6, 0xff , 0x3f5, 0x2fc,0xdfc, 0xcf5, 0xfff, 0xef6, 0x9fa, 0x8f3, 0xbf9, 0xaf0,0x650, 0x759, 0x453, 0x55a, 0x256, 0x35f, 0x55 , 0x15c,0xe5c, 0xf55, 0xc5f, 0xd56, 0xa5a, 0xb53, 0x859, 0x950,0x7c0, 0x6c9, 0x5c3, 0x4ca, 0x3c6, 0x2cf, 0x1c5, 0xcc ,0xfcc, 0xec5, 0xdcf, 0xcc6, 0xbca, 0xac3, 0x9c9, 0x8c0,0x8c0, 0x9c9, 0xac3, 0xbca, 0xcc6, 0xdcf, 0xec5, 0xfcc,0xcc , 0x1c5, 0x2cf, 0x3c6, 0x4ca, 0x5c3, 0x6c9, 0x7c0,0x950, 0x859, 0xb53, 0xa5a, 0xd56, 0xc5f, 0xf55, 0xe5c,0x15c, 0x55 , 0x35f, 0x256, 0x55a, 0x453, 0x759, 0x650,0xaf0, 0xbf9, 0x8f3, 0x9fa, 0xef6, 0xfff, 0xcf5, 0xdfc,0x2fc, 0x3f5, 0xff , 0x1f6, 0x6fa, 0x7f3, 0x4f9, 0x5f0,0xb60, 0xa69, 0x963, 0x86a, 0xf66, 0xe6f, 0xd65, 0xc6c,0x36c, 0x265, 0x16f, 0x66 , 0x76a, 0x663, 0x569, 0x460,0xca0, 0xda9, 0xea3, 0xfaa, 0x8a6, 0x9af, 0xaa5, 0xbac,0x4ac, 0x5a5, 0x6af, 0x7a6, 0xaa , 0x1a3, 0x2a9, 0x3a0,0xd30, 0xc39, 0xf33, 0xe3a, 0x936, 0x83f, 0xb35, 0xa3c,0x53c, 0x435, 0x73f, 0x636, 0x13a, 0x33 , 0x339, 0x230,0xe90, 0xf99, 0xc93, 0xd9a, 0xa96, 0xb9f, 0x895, 0x99c,0x69c, 0x795, 0x49f, 0x596, 0x29a, 0x393, 0x99 , 0x190,0xf00, 0xe09, 0xd03, 0xc0a, 0xb06, 0xa0f, 0x905, 0x80c,0x70c, 0x605, 0x50f, 0x406, 0x30a, 0x203, 0x109, 0x0   };
    
    for ( int i=0 ; i<255 ; i++ )
    {
        edgeTable[i] =edgeTable1[i];
    }

    int triTable1[256][16]=
    {{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {0, 8, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {0, 1, 9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {1, 8, 3, 9, 8, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {1, 2, 10, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {0, 8, 3, 1, 2, 10, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {9, 2, 10, 0, 2, 9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {2, 8, 3, 2, 10, 8, 10, 9, 8, -1, -1, -1, -1, -1, -1, -1},
    {3, 11, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {0, 11, 2, 8, 11, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {1, 9, 0, 2, 3, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {1, 11, 2, 1, 9, 11, 9, 8, 11, -1, -1, -1, -1, -1, -1, -1},
    {3, 10, 1, 11, 10, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {0, 10, 1, 0, 8, 10, 8, 11, 10, -1, -1, -1, -1, -1, -1, -1},
    {3, 9, 0, 3, 11, 9, 11, 10, 9, -1, -1, -1, -1, -1, -1, -1},
    {9, 8, 10, 10, 8, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {4, 7, 8, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {4, 3, 0, 7, 3, 4, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {0, 1, 9, 8, 4, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {4, 1, 9, 4, 7, 1, 7, 3, 1, -1, -1, -1, -1, -1, -1, -1},
    {1, 2, 10, 8, 4, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {3, 4, 7, 3, 0, 4, 1, 2, 10, -1, -1, -1, -1, -1, -1, -1},
    {9, 2, 10, 9, 0, 2, 8, 4, 7, -1, -1, -1, -1, -1, -1, -1},
    {2, 10, 9, 2, 9, 7, 2, 7, 3, 7, 9, 4, -1, -1, -1, -1},
    {8, 4, 7, 3, 11, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {11, 4, 7, 11, 2, 4, 2, 0, 4, -1, -1, -1, -1, -1, -1, -1},
    {9, 0, 1, 8, 4, 7, 2, 3, 11, -1, -1, -1, -1, -1, -1, -1},
    {4, 7, 11, 9, 4, 11, 9, 11, 2, 9, 2, 1, -1, -1, -1, -1},
    {3, 10, 1, 3, 11, 10, 7, 8, 4, -1, -1, -1, -1, -1, -1, -1},
    {1, 11, 10, 1, 4, 11, 1, 0, 4, 7, 11, 4, -1, -1, -1, -1},
    {4, 7, 8, 9, 0, 11, 9, 11, 10, 11, 0, 3, -1, -1, -1, -1},
    {4, 7, 11, 4, 11, 9, 9, 11, 10, -1, -1, -1, -1, -1, -1, -1},
    {9, 5, 4, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {9, 5, 4, 0, 8, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {0, 5, 4, 1, 5, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {8, 5, 4, 8, 3, 5, 3, 1, 5, -1, -1, -1, -1, -1, -1, -1},
    {1, 2, 10, 9, 5, 4, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {3, 0, 8, 1, 2, 10, 4, 9, 5, -1, -1, -1, -1, -1, -1, -1},
    {5, 2, 10, 5, 4, 2, 4, 0, 2, -1, -1, -1, -1, -1, -1, -1},
    {2, 10, 5, 3, 2, 5, 3, 5, 4, 3, 4, 8, -1, -1, -1, -1},
    {9, 5, 4, 2, 3, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {0, 11, 2, 0, 8, 11, 4, 9, 5, -1, -1, -1, -1, -1, -1, -1},
    {0, 5, 4, 0, 1, 5, 2, 3, 11, -1, -1, -1, -1, -1, -1, -1},
    {2, 1, 5, 2, 5, 8, 2, 8, 11, 4, 8, 5, -1, -1, -1, -1},
    {10, 3, 11, 10, 1, 3, 9, 5, 4, -1, -1, -1, -1, -1, -1, -1},
    {4, 9, 5, 0, 8, 1, 8, 10, 1, 8, 11, 10, -1, -1, -1, -1},
    {5, 4, 0, 5, 0, 11, 5, 11, 10, 11, 0, 3, -1, -1, -1, -1},
    {5, 4, 8, 5, 8, 10, 10, 8, 11, -1, -1, -1, -1, -1, -1, -1},
    {9, 7, 8, 5, 7, 9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {9, 3, 0, 9, 5, 3, 5, 7, 3, -1, -1, -1, -1, -1, -1, -1},
    {0, 7, 8, 0, 1, 7, 1, 5, 7, -1, -1, -1, -1, -1, -1, -1},
    {1, 5, 3, 3, 5, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {9, 7, 8, 9, 5, 7, 10, 1, 2, -1, -1, -1, -1, -1, -1, -1},
    {10, 1, 2, 9, 5, 0, 5, 3, 0, 5, 7, 3, -1, -1, -1, -1},
    {8, 0, 2, 8, 2, 5, 8, 5, 7, 10, 5, 2, -1, -1, -1, -1},
    {2, 10, 5, 2, 5, 3, 3, 5, 7, -1, -1, -1, -1, -1, -1, -1},
    {7, 9, 5, 7, 8, 9, 3, 11, 2, -1, -1, -1, -1, -1, -1, -1},
    {9, 5, 7, 9, 7, 2, 9, 2, 0, 2, 7, 11, -1, -1, -1, -1},
    {2, 3, 11, 0, 1, 8, 1, 7, 8, 1, 5, 7, -1, -1, -1, -1},
    {11, 2, 1, 11, 1, 7, 7, 1, 5, -1, -1, -1, -1, -1, -1, -1},
    {9, 5, 8, 8, 5, 7, 10, 1, 3, 10, 3, 11, -1, -1, -1, -1},
    {5, 7, 0, 5, 0, 9, 7, 11, 0, 1, 0, 10, 11, 10, 0, -1},
    {11, 10, 0, 11, 0, 3, 10, 5, 0, 8, 0, 7, 5, 7, 0, -1},
    {11, 10, 5, 7, 11, 5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {10, 6, 5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {0, 8, 3, 5, 10, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {9, 0, 1, 5, 10, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {1, 8, 3, 1, 9, 8, 5, 10, 6, -1, -1, -1, -1, -1, -1, -1},
    {1, 6, 5, 2, 6, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {1, 6, 5, 1, 2, 6, 3, 0, 8, -1, -1, -1, -1, -1, -1, -1},
    {9, 6, 5, 9, 0, 6, 0, 2, 6, -1, -1, -1, -1, -1, -1, -1},
    {5, 9, 8, 5, 8, 2, 5, 2, 6, 3, 2, 8, -1, -1, -1, -1},
    {2, 3, 11, 10, 6, 5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {11, 0, 8, 11, 2, 0, 10, 6, 5, -1, -1, -1, -1, -1, -1, -1},
    {0, 1, 9, 2, 3, 11, 5, 10, 6, -1, -1, -1, -1, -1, -1, -1},
    {5, 10, 6, 1, 9, 2, 9, 11, 2, 9, 8, 11, -1, -1, -1, -1},
    {6, 3, 11, 6, 5, 3, 5, 1, 3, -1, -1, -1, -1, -1, -1, -1},
    {0, 8, 11, 0, 11, 5, 0, 5, 1, 5, 11, 6, -1, -1, -1, -1},
    {3, 11, 6, 0, 3, 6, 0, 6, 5, 0, 5, 9, -1, -1, -1, -1},
    {6, 5, 9, 6, 9, 11, 11, 9, 8, -1, -1, -1, -1, -1, -1, -1},
    {5, 10, 6, 4, 7, 8, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {4, 3, 0, 4, 7, 3, 6, 5, 10, -1, -1, -1, -1, -1, -1, -1},
    {1, 9, 0, 5, 10, 6, 8, 4, 7, -1, -1, -1, -1, -1, -1, -1},
    {10, 6, 5, 1, 9, 7, 1, 7, 3, 7, 9, 4, -1, -1, -1, -1},
    {6, 1, 2, 6, 5, 1, 4, 7, 8, -1, -1, -1, -1, -1, -1, -1},
    {1, 2, 5, 5, 2, 6, 3, 0, 4, 3, 4, 7, -1, -1, -1, -1},
    {8, 4, 7, 9, 0, 5, 0, 6, 5, 0, 2, 6, -1, -1, -1, -1},
    {7, 3, 9, 7, 9, 4, 3, 2, 9, 5, 9, 6, 2, 6, 9, -1},
    {3, 11, 2, 7, 8, 4, 10, 6, 5, -1, -1, -1, -1, -1, -1, -1},
    {5, 10, 6, 4, 7, 2, 4, 2, 0, 2, 7, 11, -1, -1, -1, -1},
    {0, 1, 9, 4, 7, 8, 2, 3, 11, 5, 10, 6, -1, -1, -1, -1},
    {9, 2, 1, 9, 11, 2, 9, 4, 11, 7, 11, 4, 5, 10, 6, -1},
    {8, 4, 7, 3, 11, 5, 3, 5, 1, 5, 11, 6, -1, -1, -1, -1},
    {5, 1, 11, 5, 11, 6, 1, 0, 11, 7, 11, 4, 0, 4, 11, -1},
    {0, 5, 9, 0, 6, 5, 0, 3, 6, 11, 6, 3, 8, 4, 7, -1},
    {6, 5, 9, 6, 9, 11, 4, 7, 9, 7, 11, 9, -1, -1, -1, -1},
    {10, 4, 9, 6, 4, 10, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {4, 10, 6, 4, 9, 10, 0, 8, 3, -1, -1, -1, -1, -1, -1, -1},
    {10, 0, 1, 10, 6, 0, 6, 4, 0, -1, -1, -1, -1, -1, -1, -1},
    {8, 3, 1, 8, 1, 6, 8, 6, 4, 6, 1, 10, -1, -1, -1, -1},
    {1, 4, 9, 1, 2, 4, 2, 6, 4, -1, -1, -1, -1, -1, -1, -1},
    {3, 0, 8, 1, 2, 9, 2, 4, 9, 2, 6, 4, -1, -1, -1, -1},
    {0, 2, 4, 4, 2, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {8, 3, 2, 8, 2, 4, 4, 2, 6, -1, -1, -1, -1, -1, -1, -1},
    {10, 4, 9, 10, 6, 4, 11, 2, 3, -1, -1, -1, -1, -1, -1, -1},
    {0, 8, 2, 2, 8, 11, 4, 9, 10, 4, 10, 6, -1, -1, -1, -1},
    {3, 11, 2, 0, 1, 6, 0, 6, 4, 6, 1, 10, -1, -1, -1, -1},
    {6, 4, 1, 6, 1, 10, 4, 8, 1, 2, 1, 11, 8, 11, 1, -1},
    {9, 6, 4, 9, 3, 6, 9, 1, 3, 11, 6, 3, -1, -1, -1, -1},
    {8, 11, 1, 8, 1, 0, 11, 6, 1, 9, 1, 4, 6, 4, 1, -1},
    {3, 11, 6, 3, 6, 0, 0, 6, 4, -1, -1, -1, -1, -1, -1, -1},
    {6, 4, 8, 11, 6, 8, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {7, 10, 6, 7, 8, 10, 8, 9, 10, -1, -1, -1, -1, -1, -1, -1},
    {0, 7, 3, 0, 10, 7, 0, 9, 10, 6, 7, 10, -1, -1, -1, -1},
    {10, 6, 7, 1, 10, 7, 1, 7, 8, 1, 8, 0, -1, -1, -1, -1},
    {10, 6, 7, 10, 7, 1, 1, 7, 3, -1, -1, -1, -1, -1, -1, -1},
    {1, 2, 6, 1, 6, 8, 1, 8, 9, 8, 6, 7, -1, -1, -1, -1},
    {2, 6, 9, 2, 9, 1, 6, 7, 9, 0, 9, 3, 7, 3, 9, -1},
    {7, 8, 0, 7, 0, 6, 6, 0, 2, -1, -1, -1, -1, -1, -1, -1},
    {7, 3, 2, 6, 7, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {2, 3, 11, 10, 6, 8, 10, 8, 9, 8, 6, 7, -1, -1, -1, -1},
    {2, 0, 7, 2, 7, 11, 0, 9, 7, 6, 7, 10, 9, 10, 7, -1},
    {1, 8, 0, 1, 7, 8, 1, 10, 7, 6, 7, 10, 2, 3, 11, -1},
    {11, 2, 1, 11, 1, 7, 10, 6, 1, 6, 7, 1, -1, -1, -1, -1},
    {8, 9, 6, 8, 6, 7, 9, 1, 6, 11, 6, 3, 1, 3, 6, -1},
    {0, 9, 1, 11, 6, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {7, 8, 0, 7, 0, 6, 3, 11, 0, 11, 6, 0, -1, -1, -1, -1},
    {7, 11, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {7, 6, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {3, 0, 8, 11, 7, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {0, 1, 9, 11, 7, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {8, 1, 9, 8, 3, 1, 11, 7, 6, -1, -1, -1, -1, -1, -1, -1},
    {10, 1, 2, 6, 11, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {1, 2, 10, 3, 0, 8, 6, 11, 7, -1, -1, -1, -1, -1, -1, -1},
    {2, 9, 0, 2, 10, 9, 6, 11, 7, -1, -1, -1, -1, -1, -1, -1},
    {6, 11, 7, 2, 10, 3, 10, 8, 3, 10, 9, 8, -1, -1, -1, -1},
    {7, 2, 3, 6, 2, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {7, 0, 8, 7, 6, 0, 6, 2, 0, -1, -1, -1, -1, -1, -1, -1},
    {2, 7, 6, 2, 3, 7, 0, 1, 9, -1, -1, -1, -1, -1, -1, -1},
    {1, 6, 2, 1, 8, 6, 1, 9, 8, 8, 7, 6, -1, -1, -1, -1},
    {10, 7, 6, 10, 1, 7, 1, 3, 7, -1, -1, -1, -1, -1, -1, -1},
    {10, 7, 6, 1, 7, 10, 1, 8, 7, 1, 0, 8, -1, -1, -1, -1},
    {0, 3, 7, 0, 7, 10, 0, 10, 9, 6, 10, 7, -1, -1, -1, -1},
    {7, 6, 10, 7, 10, 8, 8, 10, 9, -1, -1, -1, -1, -1, -1, -1},
    {6, 8, 4, 11, 8, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {3, 6, 11, 3, 0, 6, 0, 4, 6, -1, -1, -1, -1, -1, -1, -1},
    {8, 6, 11, 8, 4, 6, 9, 0, 1, -1, -1, -1, -1, -1, -1, -1},
    {9, 4, 6, 9, 6, 3, 9, 3, 1, 11, 3, 6, -1, -1, -1, -1},
    {6, 8, 4, 6, 11, 8, 2, 10, 1, -1, -1, -1, -1, -1, -1, -1},
    {1, 2, 10, 3, 0, 11, 0, 6, 11, 0, 4, 6, -1, -1, -1, -1},
    {4, 11, 8, 4, 6, 11, 0, 2, 9, 2, 10, 9, -1, -1, -1, -1},
    {10, 9, 3, 10, 3, 2, 9, 4, 3, 11, 3, 6, 4, 6, 3, -1},
    {8, 2, 3, 8, 4, 2, 4, 6, 2, -1, -1, -1, -1, -1, -1, -1},
    {0, 4, 2, 4, 6, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {1, 9, 0, 2, 3, 4, 2, 4, 6, 4, 3, 8, -1, -1, -1, -1},
    {1, 9, 4, 1, 4, 2, 2, 4, 6, -1, -1, -1, -1, -1, -1, -1},
    {8, 1, 3, 8, 6, 1, 8, 4, 6, 6, 10, 1, -1, -1, -1, -1},
    {10, 1, 0, 10, 0, 6, 6, 0, 4, -1, -1, -1, -1, -1, -1, -1},
    {4, 6, 3, 4, 3, 8, 6, 10, 3, 0, 3, 9, 10, 9, 3, -1},
    {10, 9, 4, 6, 10, 4, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {4, 9, 5, 7, 6, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {0, 8, 3, 4, 9, 5, 11, 7, 6, -1, -1, -1, -1, -1, -1, -1},
    {5, 0, 1, 5, 4, 0, 7, 6, 11, -1, -1, -1, -1, -1, -1, -1},
    {11, 7, 6, 8, 3, 4, 3, 5, 4, 3, 1, 5, -1, -1, -1, -1},
    {9, 5, 4, 10, 1, 2, 7, 6, 11, -1, -1, -1, -1, -1, -1, -1},
    {6, 11, 7, 1, 2, 10, 0, 8, 3, 4, 9, 5, -1, -1, -1, -1},
    {7, 6, 11, 5, 4, 10, 4, 2, 10, 4, 0, 2, -1, -1, -1, -1},
    {3, 4, 8, 3, 5, 4, 3, 2, 5, 10, 5, 2, 11, 7, 6, -1},
    {7, 2, 3, 7, 6, 2, 5, 4, 9, -1, -1, -1, -1, -1, -1, -1},
    {9, 5, 4, 0, 8, 6, 0, 6, 2, 6, 8, 7, -1, -1, -1, -1},
    {3, 6, 2, 3, 7, 6, 1, 5, 0, 5, 4, 0, -1, -1, -1, -1},
    {6, 2, 8, 6, 8, 7, 2, 1, 8, 4, 8, 5, 1, 5, 8, -1},
    {9, 5, 4, 10, 1, 6, 1, 7, 6, 1, 3, 7, -1, -1, -1, -1},
    {1, 6, 10, 1, 7, 6, 1, 0, 7, 8, 7, 0, 9, 5, 4, -1},
    {4, 0, 10, 4, 10, 5, 0, 3, 10, 6, 10, 7, 3, 7, 10, -1},
    {7, 6, 10, 7, 10, 8, 5, 4, 10, 4, 8, 10, -1, -1, -1, -1},
    {6, 9, 5, 6, 11, 9, 11, 8, 9, -1, -1, -1, -1, -1, -1, -1},
    {3, 6, 11, 0, 6, 3, 0, 5, 6, 0, 9, 5, -1, -1, -1, -1},
    {0, 11, 8, 0, 5, 11, 0, 1, 5, 5, 6, 11, -1, -1, -1, -1},
    {6, 11, 3, 6, 3, 5, 5, 3, 1, -1, -1, -1, -1, -1, -1, -1},
    {1, 2, 10, 9, 5, 11, 9, 11, 8, 11, 5, 6, -1, -1, -1, -1},
    {0, 11, 3, 0, 6, 11, 0, 9, 6, 5, 6, 9, 1, 2, 10, -1},
    {11, 8, 5, 11, 5, 6, 8, 0, 5, 10, 5, 2, 0, 2, 5, -1},
    {6, 11, 3, 6, 3, 5, 2, 10, 3, 10, 5, 3, -1, -1, -1, -1},
    {5, 8, 9, 5, 2, 8, 5, 6, 2, 3, 8, 2, -1, -1, -1, -1},
    {9, 5, 6, 9, 6, 0, 0, 6, 2, -1, -1, -1, -1, -1, -1, -1},
    {1, 5, 8, 1, 8, 0, 5, 6, 8, 3, 8, 2, 6, 2, 8, -1},
    {1, 5, 6, 2, 1, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {1, 3, 6, 1, 6, 10, 3, 8, 6, 5, 6, 9, 8, 9, 6, -1},
    {10, 1, 0, 10, 0, 6, 9, 5, 0, 5, 6, 0, -1, -1, -1, -1},
    {0, 3, 8, 5, 6, 10, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {10, 5, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {11, 5, 10, 7, 5, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {11, 5, 10, 11, 7, 5, 8, 3, 0, -1, -1, -1, -1, -1, -1, -1},
    {5, 11, 7, 5, 10, 11, 1, 9, 0, -1, -1, -1, -1, -1, -1, -1},
    {10, 7, 5, 10, 11, 7, 9, 8, 1, 8, 3, 1, -1, -1, -1, -1},
    {11, 1, 2, 11, 7, 1, 7, 5, 1, -1, -1, -1, -1, -1, -1, -1},
    {0, 8, 3, 1, 2, 7, 1, 7, 5, 7, 2, 11, -1, -1, -1, -1},
    {9, 7, 5, 9, 2, 7, 9, 0, 2, 2, 11, 7, -1, -1, -1, -1},
    {7, 5, 2, 7, 2, 11, 5, 9, 2, 3, 2, 8, 9, 8, 2, -1},
    {2, 5, 10, 2, 3, 5, 3, 7, 5, -1, -1, -1, -1, -1, -1, -1},
    {8, 2, 0, 8, 5, 2, 8, 7, 5, 10, 2, 5, -1, -1, -1, -1},
    {9, 0, 1, 5, 10, 3, 5, 3, 7, 3, 10, 2, -1, -1, -1, -1},
    {9, 8, 2, 9, 2, 1, 8, 7, 2, 10, 2, 5, 7, 5, 2, -1},
    {1, 3, 5, 3, 7, 5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {0, 8, 7, 0, 7, 1, 1, 7, 5, -1, -1, -1, -1, -1, -1, -1},
    {9, 0, 3, 9, 3, 5, 5, 3, 7, -1, -1, -1, -1, -1, -1, -1},
    {9, 8, 7, 5, 9, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {5, 8, 4, 5, 10, 8, 10, 11, 8, -1, -1, -1, -1, -1, -1, -1},
    {5, 0, 4, 5, 11, 0, 5, 10, 11, 11, 3, 0, -1, -1, -1, -1},
    {0, 1, 9, 8, 4, 10, 8, 10, 11, 10, 4, 5, -1, -1, -1, -1},
    {10, 11, 4, 10, 4, 5, 11, 3, 4, 9, 4, 1, 3, 1, 4, -1},
    {2, 5, 1, 2, 8, 5, 2, 11, 8, 4, 5, 8, -1, -1, -1, -1},
    {0, 4, 11, 0, 11, 3, 4, 5, 11, 2, 11, 1, 5, 1, 11, -1},
    {0, 2, 5, 0, 5, 9, 2, 11, 5, 4, 5, 8, 11, 8, 5, -1},
    {9, 4, 5, 2, 11, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {2, 5, 10, 3, 5, 2, 3, 4, 5, 3, 8, 4, -1, -1, -1, -1},
    {5, 10, 2, 5, 2, 4, 4, 2, 0, -1, -1, -1, -1, -1, -1, -1},
    {3, 10, 2, 3, 5, 10, 3, 8, 5, 4, 5, 8, 0, 1, 9, -1},
    {5, 10, 2, 5, 2, 4, 1, 9, 2, 9, 4, 2, -1, -1, -1, -1},
    {8, 4, 5, 8, 5, 3, 3, 5, 1, -1, -1, -1, -1, -1, -1, -1},
    {0, 4, 5, 1, 0, 5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {8, 4, 5, 8, 5, 3, 9, 0, 5, 0, 3, 5, -1, -1, -1, -1},
    {9, 4, 5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {4, 11, 7, 4, 9, 11, 9, 10, 11, -1, -1, -1, -1, -1, -1, -1},
    {0, 8, 3, 4, 9, 7, 9, 11, 7, 9, 10, 11, -1, -1, -1, -1},
    {1, 10, 11, 1, 11, 4, 1, 4, 0, 7, 4, 11, -1, -1, -1, -1},
    {3, 1, 4, 3, 4, 8, 1, 10, 4, 7, 4, 11, 10, 11, 4, -1},
    {4, 11, 7, 9, 11, 4, 9, 2, 11, 9, 1, 2, -1, -1, -1, -1},
    {9, 7, 4, 9, 11, 7, 9, 1, 11, 2, 11, 1, 0, 8, 3, -1},
    {11, 7, 4, 11, 4, 2, 2, 4, 0, -1, -1, -1, -1, -1, -1, -1},
    {11, 7, 4, 11, 4, 2, 8, 3, 4, 3, 2, 4, -1, -1, -1, -1},
    {2, 9, 10, 2, 7, 9, 2, 3, 7, 7, 4, 9, -1, -1, -1, -1},
    {9, 10, 7, 9, 7, 4, 10, 2, 7, 8, 7, 0, 2, 0, 7, -1},
    {3, 7, 10, 3, 10, 2, 7, 4, 10, 1, 10, 0, 4, 0, 10, -1},
    {1, 10, 2, 8, 7, 4, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {4, 9, 1, 4, 1, 7, 7, 1, 3, -1, -1, -1, -1, -1, -1, -1},
    {4, 9, 1, 4, 1, 7, 0, 8, 1, 8, 7, 1, -1, -1, -1, -1},
    {4, 0, 3, 7, 4, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {4, 8, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {9, 10, 8, 10, 11, 8, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {3, 0, 9, 3, 9, 11, 11, 9, 10, -1, -1, -1, -1, -1, -1, -1},
    {0, 1, 10, 0, 10, 8, 8, 10, 11, -1, -1, -1, -1, -1, -1, -1},
    {3, 1, 10, 11, 3, 10, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {1, 2, 11, 1, 11, 9, 9, 11, 8, -1, -1, -1, -1, -1, -1, -1},
    {3, 0, 9, 3, 9, 11, 1, 2, 9, 2, 11, 9, -1, -1, -1, -1},
    {0, 2, 11, 8, 0, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {3, 2, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {2, 3, 8, 2, 8, 10, 10, 8, 9, -1, -1, -1, -1, -1, -1, -1},
    {9, 10, 2, 0, 9, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {2, 3, 8, 2, 8, 10, 0, 1, 8, 1, 10, 8, -1, -1, -1, -1},
    {1, 10, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {1, 3, 8, 9, 1, 8, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {0, 9, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {0, 3, 8, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}};
    
    for ( int i=0 ; i<255 ; i++ )
    {
        
        for(int j=0;j<16;j++)
        {
            triTable[i][j] =triTable1[i][j];
        }
        
    }

}

void isoSurface::setup() 
{
    
openglbuffer = new float[18];
    // setup points
    int i;
    int j;
    int k;
   
    float4 *pointData;
    pointData =new float4[resolution*resolution*resolution];
   
   
    
    int count=0;
    float step =gridsize/resolution;
    cout<<" step    "<< step<<"    ";
    for(i =0;i<resolution;i++)
    {
        for(j=0;j<resolution;j++)
        {
            for (k=0;k<resolution;k++)
            {
                IsoPoint *point =new IsoPoint();
                point->x =i*step;
                point->y =j*step;
                point->z =k*step;
                
                
                isoPoints.push_back(point);
                
                pointData[count].z = i*step;
                pointData[count].y =j*step;
                pointData[count].x =k*step;
                pointData[count].w =1;
                count++;
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
                cube->setup(resolutionPass2);
                
        
                isoCubes.push_back(cube);
                
                            }
        }
    }
    
    
    
    opencl.setup(CL_DEVICE_TYPE_GPU,1);
    
    clProgram = opencl.loadProgramFromFile("TestProgram.cl");
	kernel = opencl.loadKernel("update", clProgram);
    
    
    clMemPoints.initBuffer(resolution*resolution*resolution * sizeof(float4), CL_MEM_WRITE_ONLY);
    
   
    
    int numParticles = particles.size();
    
    
    partData =new float4[numParticles];
    
    
    
    
    clMemParticles.initBuffer(numParticles * sizeof(float4), CL_MEM_WRITE_ONLY);
    
    
    clMemNormals.initBuffer(resolution*resolution*resolution * sizeof(float4), CL_MEM_READ_WRITE);
    normalPointer =new float4[resolution*resolution*resolution];
    
    
    
    opencl.flush();

    clMemPoints.write(pointData, 0, resolution*resolution*resolution * sizeof(float4),true);
    opencl.finish();
    kernel->setArg(0, clMemPoints.getCLMem());
    kernel->setArg(1, clMemNormals.getCLMem());
    
    kernel->setArg(2, clMemParticles.getCLMem());
    kernel->setArg(3,numParticles);
}

void isoSurface::updateCL() 
{
    int numParticles = particles.size();
    int i;
    
   
    
    int count=0;
    for (i=0;i<numParticles;++i)
    {
        partData[i].x =particles[i].x;
        partData[i].y =particles[i].y;
        partData[i].z =particles[i].z;
       // partData[i].w =0;
     
    }
    
    
    
    clMemParticles.write(partData, 0, numParticles * sizeof(float4),true);
    kernel->setArg(2, clMemParticles.getCLMem());
 
    int res = resolution*resolution*resolution;
    kernel->run1D(res );
    
    
    clMemNormals.read(normalPointer,0,resolution*resolution*resolution * sizeof(float4),true);
    opencl.finish();
    

}
int isoSurface::getPointPos(int x,int y, int z)
{
    return x+y*resolution+z*resolution*resolution;
}
void isoSurface::updatePoints()
{
    int i;
    int j;
    int pSize = isoPoints.size();
    int numParticles = particles.size();
    
    for (i =0;i<pSize;++i)
    {
    
        IsoPoint *point= isoPoints[i];
       
        
        point->isoValue =normalPointer[i].w;
        
        
        point ->xn =normalPointer[i].x;
        point->yn=normalPointer[i].y;
        point->zn =normalPointer[i].z;
        /*
        for( j=0; j<numParticles; ++j) 
        {
            Particles part =particles[j];
            
            float px =part.x-point->x;
            float py =part.y-point->y;
            float pz =part.z-point->z;
            
            float pointWeight =(px*px + py*py +pz*pz);
            point ->xn-=px/pointWeight; 
            point ->yn -=py/pointWeight; 
            point->zn -=pz/pointWeight; 
            
            point ->isoValue += 1.0/pointWeight;
        
        
        }
        point->normalize();
       // cout << point->isoValue << " "<<point->x << " ";
         */
    }


}

void isoSurface::updateCubes()
{   
    numTriangles=0;
   
    
    pointMap.clear();
    pointVector.clear();
    pointsMain.clear();
    pointsSup.clear();
    int numCubes =isoCubes.size();
    int i;
    int count =0;
    for(i=0; i<numCubes; ++i ) 
    {
        IsoCube *cube  =isoCubes[i];
        
        int cubeIndex = 0;
       
        
        if(cube->point1->isoValue > isoValue) {cubeIndex |= 1;pointsMain.push_back(*cube->point1);}
        if(cube->point2->isoValue > isoValue) {cubeIndex |= 2;pointsMain.push_back(*cube->point2);}
        if(cube->point3->isoValue > isoValue) {cubeIndex |= 4;pointsMain.push_back(*cube->point3);}
        if(cube->point4->isoValue > isoValue) {cubeIndex |= 8;pointsMain.push_back(*cube->point4);}
        if(cube->point5->isoValue> isoValue) {cubeIndex |= 16;pointsMain.push_back(*cube->point5);}
        if(cube->point6->isoValue > isoValue){ cubeIndex |= 32;pointsMain.push_back(*cube->point6);}
        if(cube->point7->isoValue > isoValue) {cubeIndex |= 64;pointsMain.push_back(*cube->point7);}
        if(cube->point8->isoValue> isoValue) {cubeIndex |= 128;pointsMain.push_back(*cube->point8);}
     
        
        if(cubeIndex==0)continue;
      //if(cubeIndex==255)continue;
        count++;
        pointsMain.push_back(*cube->point1);
        pointsMain.push_back(*cube->point2);
        pointsMain.push_back(*cube->point1);
        pointsMain.push_back(*cube->point4);
        pointsMain.push_back(*cube->point1);
        pointsMain.push_back(*cube->point5);
        
        //pointsMain.push_back(*cube->point7);
        //pointsMain.push_back(*cube->point8);
       // pointsMain.push_back(*cube->point7);
        //pointsMain.push_back(*cube->point6);
        //pointsMain.push_back(*cube->point7);
        //pointsMain.push_back(*cube->point3);
        //cout << "cube->point1->isoValue "<< cube->point1->isoValue <<"\n ";
        //cout << "cube "<< cube->point1->x <<" "<<cube->point1->y <<" "<<cube->point1->z <<" ";
        devideCube(cube);
        
       
        
    }
    
 // cout << numTriangles <<" "<<count<< "\n ";
    delete [] openglbuffer;
    openglbuffer = new float[numTriangles*18];
    
    for(i=0;i<numTriangles;i++)
    {
        int pos =i*18;
       
        openglbuffer[pos] =triangles[i][0].x;
        pos++;
        openglbuffer[pos] =triangles[i][0].y;
        pos++;
        openglbuffer[pos] =triangles[i][0].z;
        pos++;
       
      openglbuffer[pos] =triangles[i][0].xn;
        pos++;
        openglbuffer[pos] =triangles[i][0].yn;
        pos++;
        openglbuffer[pos] =triangles[i][0].zn;
        pos++;
       
        
        openglbuffer[pos] =triangles[i][1].x;
        pos++;
        openglbuffer[pos] =triangles[i][1].y;
        pos++;
        openglbuffer[pos] =triangles[i][1].z;
        pos++;
       
        openglbuffer[pos] =triangles[i][1].xn;
        pos++;
        openglbuffer[pos] =triangles[i][1].yn;
        pos++;
        openglbuffer[pos] =triangles[i][1].zn;
        pos++;
        
        openglbuffer[pos] =triangles[i][2].x;
        pos++;
        openglbuffer[pos] =triangles[i][2].y;
        pos++;
        openglbuffer[pos] =triangles[i][2].z;
        pos++;
       
        openglbuffer[pos] =triangles[i][2].xn;
        pos++;
        openglbuffer[pos] =triangles[i][2].yn;
        pos++;
        openglbuffer[pos] =triangles[i][2].zn;
        pos++;
    }    
    
    for(int i=0; i<triangles.size(); ++i ) 
    {
        triangles[i].clear();
    }
    triangles.clear();
}

void isoSurface::devideCube(IsoCube *cube)
{

    int pSize = cube->isoPoints.size();
    int numParticles = particles.size();
    int i;
    int j;
   // cout <<"\n point1 "<< pSize<< "  "<<cube->isoPoints[0]->x <<" % "<< cube->point1->x <<" ";
    for (i =0;i<pSize;++i)
    {
        
        IsoPoint *point= cube->isoPoints[i];
       // cout <<" "<< point->x <<" ";        
        point ->xn=0; 
        point ->yn =0; 
        point->zn =0; 
        
        point ->isoValue =0;
         for( j=0; j<numParticles; ++j) 
         {
         Particles part =particles[j];
         
         float px =part.z-point->x;
         float py =part.y-point->y;
         float pz =part.x-point->z;
        
         float pointWeight =(px*px + py*py +pz*pz);
        float  pwN =  pointWeight*pointWeight; 
         point ->xn+=px/pwN; 
         point ->yn +=py/pwN; 
         point->zn +=pz/pwN; 
         
         point ->isoValue += 1.0/pointWeight;
      
         
         }

        // point->normalize(); normalize in shader
        
    }

    int numCubes =cube->isoCubes.size();
   //cout <<" \n"<< numCubes<<" \n";
    int count =0;
    for(i=0; i<numCubes; ++i ) 
    {
        IsoCube *cubee  =cube->isoCubes[i];
  
        
               int cubeIndex = 0;
        if(cubee->point1->isoValue > isoValuePass2) {cubeIndex |= 1;}
        if(cubee->point2->isoValue > isoValuePass2) cubeIndex |= 2;
        if(cubee->point3->isoValue > isoValuePass2) cubeIndex |= 4;
        if(cubee->point4->isoValue > isoValuePass2) cubeIndex |= 8;
        if(cubee->point5->isoValue> isoValuePass2) cubeIndex |= 16;
        if(cubee->point6->isoValue > isoValuePass2) cubeIndex |= 32;
        if(cubee->point7->isoValue > isoValuePass2) cubeIndex |= 64;
        if(cubee->point8->isoValue> isoValuePass2) cubeIndex |= 128;
    
        if(cubeIndex==0)continue;
        if(cubeIndex==255)continue;
        
        
     
        
        
        
   
        vector <IsoPoint> vertices(12);
        int edge  =edgeTable[cubeIndex];
     
        if((edge& 1)==1) {       vertices[0]  = vertexInterpolation(cubee->point1, cubee->point2);
     
     
        }
     
        if((edge & 2)==2) {       vertices[1]  = vertexInterpolation(cubee->point2, cubee->point3); 
     
        }
        if((edge & 4)==4) {       vertices[2]  = vertexInterpolation(cubee->point3, cubee->point4);
     
        }
        if((edge & 8)==8) {       vertices[3]  = vertexInterpolation(cubee->point4, cubee->point1);
     
     
        }
        if((edge & 16)==16) {     vertices[4]  = vertexInterpolation(cubee->point5, cubee->point6); }
        if((edge & 32)==32) {     vertices[5]  = vertexInterpolation(cubee->point6, cubee->point7); }
        if((edge & 64)==64) {     vertices[6]  = vertexInterpolation(cubee->point7, cubee->point8); }
        if((edge & 128)==128) {   vertices[7]  = vertexInterpolation(cubee->point8, cubee->point5); }
        if((edge & 256)==256) {   vertices[8]  = vertexInterpolation(cubee->point1, cubee->point5);}
        if((edge & 512)==512) {   vertices[9]  = vertexInterpolation(cubee->point2, cubee->point6); }
        if((edge & 1024)==1024) { vertices[10] = vertexInterpolation(cubee->point3, cubee->point7); }     
        if((edge & 2048)==2048) { vertices[11] = vertexInterpolation(cubee->point4, cubee->point8); }
     
     
    
     
        
        IsoPoint p0, p1, p2;
        for(int i=0; i<15; i+=3) 
        {
     
            if(triTable[cubeIndex][i] == -1)continue;
     
                 
     
            p0 = vertices[triTable[cubeIndex][i]];
            p1 = vertices[triTable[cubeIndex][i+1]];
     
            p2 = vertices[triTable[cubeIndex][i+2]];
          
        
             numTriangles++;
    
     
            vector <IsoPoint> triangle(3);
            triangle[0] = p0;
            triangle[1] = p1;
            triangle[2] = p2;
            
            
            triangles.push_back(triangle);
    
        }
        vertices.clear();
     
     }






}
//old methode for removing duplicated indices...
IsoPoint* isoSurface::getPoint(IsoPoint *point)
{
   pointIt=pointMap.find(point->id);

    if(pointIt == pointMap.end())
    {
  
        pointVector.push_back(point);
        point->index = (unsigned int)pointVector.size()-1;
        pointMap.insert ( pair<int,IsoPoint>(point->id,*point) );
     
        
     
        return point; 
    }else
    {
     
       return  &pointIt->second;
      
    }
     

}

void isoSurface::update() {

    updateCL();
    updatePoints();
    updateCubes();


}

IsoPoint isoSurface::vertexInterpolation(IsoPoint *point1, IsoPoint *point2) {
    

    
    
    float isovalue1 = point1->isoValue;
    float isovalue2 =point2->isoValue;
    IsoPoint point ;//=new IsoPoint();
    
    float diff = (isoValuePass2-isovalue1) / (isovalue2-isovalue1);
        // set vector
    point.zn = point1->xn + diff * (point2->xn-point1->xn);
    point.yn = point1->yn + diff * (point2->yn-point1->yn);
    point.xn = point1->zn + diff * (point2->zn-point1->zn);
    
    point.x = point1->x + diff * (point2->x-point1->x);
    point.y = point1->y + diff * (point2->y-point1->y);
    point.z = point1->z + diff * (point2->z-point1->z);
   
   
    return point;
}

void isoSurface::draw() {

    
  
    
  
   
    
    
  /*  for(int i=0; i<pointsMain.size(); i+=2) {
        glBegin(GL_LINES);
        glVertex3f(pointsMain[i].x, pointsMain[i].y, pointsMain[i].z);
        glVertex3f(pointsMain[i+1].x, pointsMain[i+1].y, pointsMain[i+1].z);
         glEnd();
    }*/
    
    glColor3f(1.2, 1.2, 1.2);
    IsoPoint p1,p2,p3;
  
    for(int i=0; i<triangles.size(); ++i) {
        // get vertices
        p1 = triangles[i][0];
        p2 = triangles[i][1];
        p3 = triangles[i][2];
        glBegin(GL_POINTS);
   
            glVertex3f(p1.x, p1.y, p1.z);
        
        
      
            glVertex3f(p2.x, p2.y, p2.z);
        
        
        
         
            glVertex3f(p3.x, p3.y, p3.z);
        
    
        glEnd();

    }








}


