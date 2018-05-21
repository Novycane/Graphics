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

int classifyPolygon(TriangleF4* split, TriangleF4* face);
void normalF4(TriangleF4*, float4*);

// --------------------------------------------------
// ------------------------- Headers

int TestClassifyPolygon();
int TestBSP();

// --------------------------------------------------
// ------------------------- Main

int main(int argCount, char** args)
{
    printf("-------------------------\n");
    TestClassifyPolygon();
    
    printf("-------------------------\n");
    
    return 1;
}

int TestClassifyPolygon()
{
    int sum = 0;
    TriangleF4 split;
    TriangleF4 poly;

    printf("Testing Classify Polygon\n");

    split.p0 = (float4) {1.0, 0.0, 0.0, 1.0};
    split.p1 = (float4) {0.0, 0.0, 1.0, 1.0};
    split.p2 = (float4) {0.0, 1.0, 0.0, 1.0};
    
    // ------------------------- Front
    poly.p0 = (float4) {1.5, 0.5, 0.5, 1.0};
    poly.p1 = (float4) {0.5, 0.5, 1.5, 1.0};
    poly.p2 = (float4) {0.5, 1.5, 0.5, 1.0};
    if(classifyPolygon(&split, &poly) != 1)
    {
        sum++;
        printf("Error in classifyPoly: Triangle Should be infront of the plane");
    }

    // ------------------------- Back
    poly.p0 = (float4) {0.5, -0.5, -0.5, 1.0};
    poly.p1 = (float4) {-0.5, -0.5, 0.5, 1.0};
    poly.p2 = (float4) {-0.5, 0.5, -0.5, 1.0};
    if(classifyPolygon(&split, &poly) != 2)
    {
        sum++;
        printf("Error in classifyPoly: Triangle Should be behind the plane");
    }

    // ------------------------- In plane
    poly.p0 = (float4) {1.0,  0.0, 0.0, 1.0};
    poly.p1 = (float4) {0.0, 1.0, 0.0, 1.0};
    poly.p2 = (float4) {0.0, 0.0, 1.0, 1.0};
    if(classifyPolygon(&split, &poly) != 4)
    {
        sum++;
        printf("Error in classifyPoly: Triangle Should be in the plane\n");
    }

    // ------------------------- Divided
    poly.p0 = (float4) {0.0,  0.0, 0.0, 1.0};
    poly.p1 = (float4) {2.0, 2.0, 2.0, 1.0};
    poly.p2 = (float4) {0.0, 1.0, 1.0, 1.0};
    if(classifyPolygon(&split, &poly) != 3)
    {
        sum++;
        printf("Error in classifyPoly: Triangle Should be divided by the plane\n");
    }

    // ------------------------- In and In Front
    poly.p0 = (float4) {1.5, 0.5, 0.5, 1.0};
    poly.p1 = (float4) {0.0, 0.0, 1.0, 1.0};
    poly.p2 = (float4) {0.5, 1.5, 0.5, 1.0};
    if(classifyPolygon(&split, &poly) != 1)
    {
        sum++;
        printf("Error in classifyPoly: Triangle Should be divided by the plane\n");
    }

    // ------------------------- In and Behind
    poly.p0 = (float4) {0.5, -0.5, -0.5, 1.0};
    poly.p1 = (float4) {0.0, 0.0, 1.0, 1.0};
    poly.p2 = (float4) {-0.5, 0.5, -0.5, 1.0};
    if(classifyPolygon(&split, &poly) != 2)
    {
        sum++;
        printf("Error in classifyPoly: Triangle Should be divided by the plane\n");
    }

    return sum;
}

int TestBSP()
{
    int sum = 0;

    printf("Testing BSP Tree\n");

    return sum;
}