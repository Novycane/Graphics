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
int splitPolygon(TriangleF4* split, TriangleF4* face, TriangleF4* out1, TriangleF4* out2, TriangleF4* out3);
void normalF4(TriangleF4*, float4*);
int isConvexSet(TriangleF4* vertexBuffer, unsigned int count);

// --------------------------------------------------
// ------------------------- Headers

int TestClassifyPolygon();
int TestSplitPolygon();
int TestConvexSet();
int TestBSP();

// --------------------------------------------------
// ------------------------- Main

int main(int argCount, char** args)
{
    printf("-------------------------\n");
    TestClassifyPolygon();
    
    TestSplitPolygon();

    TestConvexSet();
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

int TestSplitPolygon()
{
    int sum = 0;
    TriangleF4 split;
    TriangleF4 poly, out1, out2, out3;

    printf("Testing Split Polygon\n");

    split.p0 = (float4) {1.0, 0.0, 0.0, 1.0};
    split.p1 = (float4) {0.0, 0.0, 1.0, 1.0};
    split.p2 = (float4) {0.0, 1.0, 0.0, 1.0};
    
    // ------------------------- Front
    poly.p0 = (float4) {1.5, 0.5, 0.5, 1.0};
    poly.p1 = (float4) {0.5, 0.5, 1.5, 1.0};
    poly.p2 = (float4) {0.5, 1.5, 0.5, 1.0};
    splitPolygon(&split, &poly, &out1, &out2, &out3);
    if( out1.p0.x != 1.0)
    {
        sum++;
        printf("Error in splitPolygon: Triangle Should be infront of the plane");
    }

    return sum;
}

int TestBSP()
{
    int sum = 0;

    printf("Testing BSP Tree\n");

    return sum;
}

int TestConvexSet()
{
    int sum = 0;
    int i;
    int triangleCount = 4;
    TriangleF4* triangles = malloc(sizeof(TriangleF4) * triangleCount);
    
    printf("Testing isConvex set\n");

    i=0;
    triangles[i].p0 =   (float4){0.0, 0.0, 0.0, 1.0};
    triangles[i].p1 =   (float4){1.0, 0.0, 0.0, 1.0};
    triangles[i++].p2 = (float4){1.0, 1.0, 0.0, 1.0};

    triangles[i].p0 =   (float4){1.0, 1.0, 0.0, 1.0};
    triangles[i].p1 =   (float4){0.0, 1.0, 0.0, 1.0};
    triangles[i++].p2 = (float4){0.0, 0.0, 0.0, 1.0};

    triangles[i].p0 =   (float4){0.0, 0.0, 0.0, 1.0};
    triangles[i].p1 =   (float4){0.0, -1.0, 0.0, 1.0};
    triangles[i++].p2 = (float4){1.0, 0.0, 0.0, 1.0};

    triangles[i].p0 =   (float4){1.0, 0.0, 0.0, 1.0};
    triangles[i].p1 =   (float4){0.0, -1.0, 0.0, 1.0};
    triangles[i++].p2 = (float4){1.0, -1.0, 0.0, 1.0};
    
    if(!isConvexSet(triangles, triangleCount))
    {
        printf("Error testing convex set. Case 1 should be convex!\n");
        sum ++;
    }

    i=0;
    triangles[i].p0 =   (float4){0.0, 0.0, 0.0, 1.0};
    triangles[i].p1 =   (float4){1.0, 0.0, 0.0, 1.0};
    triangles[i++].p2 = (float4){1.0, 1.0, 1.0, 1.0};

    triangles[i].p0 =   (float4){1.0, 1.0, 1.0, 1.0};
    triangles[i].p1 =   (float4){1.0, 0.0, 1.0, 1.0};
    triangles[i++].p2 = (float4){0.0, 0.0, 1.0, 1.0};

    triangles[i].p0 =   (float4){0.0, 0.0, 1.5, 1.0};
    triangles[i].p1 =   (float4){1.0, 0.0, 1.5, 1.0};
    triangles[i++].p2 = (float4){1.0, 1.0, 2.5, 1.0};

    triangles[i].p0 =   (float4){1.0, 1.0, 2.5, 1.0};
    triangles[i].p1 =   (float4){1.0, 0.0, 2.5, 1.0};
    triangles[i++].p2 = (float4){0.0, 0.0, 3.3, 1.0};
    
    if(isConvexSet(triangles, triangleCount))
    {
        printf("Error testing convex set. Case 2 should be concave!\n");
        sum ++;
    }

    return sum;
}