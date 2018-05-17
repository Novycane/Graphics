// --------------------------------------------------
// BSP.test.c  
// 
// BSP Test Routines
//
// Steven Novak
//
// 05/14/2018
//
// --------------------------------------------------

#include <stdio.h>

#include "../BSP.h"

// --------------------------------------------------
// ------------------------- Externals

int classifyPolygon(float3* normal, TriangleF4* face);

// --------------------------------------------------
// ------------------------- Headers

int TestClassifyPolygon();
int TestBSP();

// --------------------------------------------------
// ------------------------- Main

int main(int argCount, char** args)
{
    
    TestClassifyPolygon();

    return 1;
}

int TestClassifyPolygon()
{
    int sum = 0;
    float3 norm = (float3) {0.0, 0.0, 1.0};
    TriangleF4 face;

    face.p0 = (float4) {1.0, 1.0, 1.0, 1.0};

    printf("Testing Classify Polygon\n");

    classifyPolygon(&norm, &face);

    return sum;
}

int TestBSP()
{
    int sum = 0;

    printf("Testing BSP Tree\n");

    return sum;
}