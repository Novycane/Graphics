// --------------------------------------------------
// SIMD.test.c  
// 
// SIMD Test Routines
//
// Steven Novak
//
// 04/13/2018
//
// --------------------------------------------------

#include <stdio.h>

#include "../Polygon.h"

// --------------------------------------------------
// ------------------------- Error Code


// --------------------------------------------------
// ------------------------- Headers

int TestTriangleF3Normal();
int TestTriangleF4Normal();

int TestTriangleD3Normal();
int TestTriangleD4Normal();

int TestMollerTrumboreIntersection();

// --------------------------------------------------
// ------------------------- Main

int main(int argCount, char** args)
{
    TestTriangleF3Normal();
    TestTriangleF4Normal();

    TestTriangleD3Normal();
    TestTriangleD4Normal();

    TestMollerTrumboreIntersection();
}

// -------------------------------------------------- Normals

int TestTriangleF3Normal()
{
    TriangleF3 T;
    float3 N;
    int sum = 0;

    printf("Testing Trianlge Norm F3\n");

    T.p0 = (float3){ 0.0, 0.0, 0.0 };
    T.p1 = (float3){ 0.0, 1.0, 0.0 };
    T.p2 = (float3){ 1.0, 0.0, 0.0 };

    N.x = -1.0;
    N.y = -1.0;
    N.z = -1.0;

    normalF3(&T, &N);
    if(N.x != 0.0 || 
       N.y != 0.0 ||
       N.z != 1.0 )
    {
        printf("TriangleF3 Norm error. Expected: {0,0,1} Actual: {%f, %f, %f}\n", N.x, N.y, N.z);
        sum++;
    }

    T.p0 = (float3){ 0.0, 0.0, 0.0 };
    T.p1 = (float3){ 1.0, 0.0, 0.0 };
    T.p2 = (float3){ 0.0, 0.0, 1.0 };
    normalF3(&T, &N);
    if(N.x != 0.0 || 
       N.y != 1.0 ||
       N.z != 0.0 )
    {
        printf("TriangleF3 Norm error. Expected: {0,1,0} Actual: {%f, %f, %f}\n", N.x, N.y, N.z);
        sum++;
    }

    T.p0 = (float3){ 0.0, 0.0, 0.0 };
    T.p1 = (float3){ 0.0, 0.0, 1.0 };
    T.p2 = (float3){ 0.0, 1.0, 0.0 };
    normalF3(&T, &N);
    if(N.x != 1.0 || 
       N.y != 0.0 ||
       N.z != 0.0 )
    {
        printf("TriangleF3 Norm error. Expected: {1,0,0} Actual: {%f, %f, %f}\n", N.x, N.y, N.z);
        sum++;
    }

    return sum;
}

int TestTriangleF4Normal()
{
    TriangleF4 T;
    float4 N;
    int sum = 0;

    printf("Testing Trianlge Norm F4\n");

    T.p0 = (float4){ 0.0, 0.0, 0.0, 1.0 };
    T.p1 = (float4){ 0.0, 1.0, 0.0, 1.0 };
    T.p2 = (float4){ 1.0, 0.0, 0.0, 1.0 };

    N.x = -1.0;
    N.y = -1.0;
    N.z = -1.0;
    N.w = 1.0;

    normalF4(&T, &N);
    if(N.x != 0.0 || 
       N.y != 0.0 ||
       N.z != 1.0 ||
       N.w != 1.0)
    {
        printf("TriangleF4 Norm error. Expected: {0,0,1,1} Actual: {%f, %f, %f, %f}\n", N.x, N.y, N.z, N.w);
        sum++;
    }

    T.p0 = (float4){ 0.0, 0.0, 0.0, 1.0 };
    T.p1 = (float4){ 1.0, 0.0, 0.0, 1.0 };
    T.p2 = (float4){ 0.0, 0.0, 1.0, 1.0 };
    normalF4(&T, &N);
    if(N.x != 0.0 || 
       N.y != 1.0 ||
       N.z != 0.0 )
    {
        printf("TriangleF4 Norm error. Expected: {0,1,0} Actual: {%f, %f, %f}\n", N.x, N.y, N.z);
        sum++;
    }

    T.p0 = (float4){ 0.0, 0.0, 0.0, 1.0 };
    T.p1 = (float4){ 0.0, 0.0, 1.0, 1.0 };
    T.p2 = (float4){ 0.0, 1.0, 0.0, 1.0 };
    normalF4(&T, &N);
    if(N.x != 1.0 || 
       N.y != 0.0 ||
       N.z != 0.0 )
    {
        printf("TriangleF4 Norm error. Expected: {1,0,0} Actual: {%f, %f, %f}\n", N.x, N.y, N.z);
        sum++;
    }

    return sum;
}

int TestTriangleD3Normal()
{
    TriangleD3 T;
    double3 N;
    int sum = 0;

    printf("Testing Trianlge Norm D3\n");

    T.p0 = (double3){ 0.0, 0.0, 0.0 };
    T.p1 = (double3){ 0.0, 1.0, 0.0 };
    T.p2 = (double3){ 1.0, 0.0, 0.0 };

    N.x = -1.0;
    N.y = -1.0;
    N.z = -1.0;

    normalD3(&T, &N);
    if(N.x != 0.0 || 
       N.y != 0.0 ||
       N.z != 1.0 )
    {
        printf("TriangleD3 Norm error. Expected: {0,0,1} Actual: {%f, %f, %f}\n", N.x, N.y, N.z);
        sum++;
    }

    T.p0 = (double3){ 0.0, 0.0, 0.0 };
    T.p1 = (double3){ 1.0, 0.0, 0.0 };
    T.p2 = (double3){ 0.0, 0.0, 1.0 };
    normalD3(&T, &N);
    if(N.x != 0.0 || 
       N.y != 1.0 ||
       N.z != 0.0 )
    {
        printf("TriangleD3 Norm error. Expected: {0,1,0} Actual: {%f, %f, %f}\n", N.x, N.y, N.z);
        sum++;
    }

    T.p0 = (double3){ 0.0, 0.0, 0.0 };
    T.p1 = (double3){ 0.0, 0.0, 1.0 };
    T.p2 = (double3){ 0.0, 1.0, 0.0 };
    normalD3(&T, &N);
    if(N.x != 1.0 || 
       N.y != 0.0 ||
       N.z != 0.0 )
    {
        printf("TriangleD3 Norm error. Expected: {1,0,0} Actual: {%f, %f, %f}\n", N.x, N.y, N.z);
        sum++;
    }

    return sum;
}

int TestTriangleD4Normal()
{
    TriangleD4 T;
    double4 N;
    int sum = 0;

    printf("Testing Trianlge Norm D4\n");

    T.p0 = (double4){ 0.0, 0.0, 0.0, 1.0 };
    T.p1 = (double4){ 0.0, 1.0, 0.0, 1.0 };
    T.p2 = (double4){ 1.0, 0.0, 0.0, 1.0 };

    N.x = -1.0;
    N.y = -1.0;
    N.z = -1.0;
    N.w = 1.0;

    normalD4(&T, &N);
    if(N.x != 0.0 || 
       N.y != 0.0 ||
       N.z != 1.0 ||
       N.w != 1.0)
    {
        printf("TriangleD4 Norm error. Expected: {0,0,1,1} Actual: {%f, %f, %f, %f}\n", N.x, N.y, N.z, N.w);
        sum++;
    }

    T.p0 = (double4){ 0.0, 0.0, 0.0, 1.0 };
    T.p1 = (double4){ 1.0, 0.0, 0.0, 1.0 };
    T.p2 = (double4){ 0.0, 0.0, 1.0, 1.0 };
    normalD4(&T, &N);
    if(N.x != 0.0 || 
       N.y != 1.0 ||
       N.z != 0.0 )
    {
        printf("TriangleD4 Norm error. Expected: {0,1,0} Actual: {%f, %f, %f}\n", N.x, N.y, N.z);
        sum++;
    }

    T.p0 = (double4){ 0.0, 0.0, 0.0, 1.0 };
    T.p1 = (double4){ 0.0, 0.0, 1.0, 1.0 };
    T.p2 = (double4){ 0.0, 1.0, 0.0, 1.0 };
    normalD4(&T, &N);
    if(N.x != 1.0 || 
       N.y != 0.0 ||
       N.z != 0.0 )
    {
        printf("TriangleD4 Norm error. Expected: {1,0,0} Actual: {%f, %f, %f}\n", N.x, N.y, N.z);
        sum++;
    }
    return sum;
}

// -------------------------------------------------- Intersection tests

int TestMollerTrumboreIntersection()
{
    int sum = 0;

    TriangleF3 T;
    LineF3 L;

    printf("Test MollerTrumbore algorithm\n");

    T.p0 = (float3) {0.0, 0.0, 0.0};
    T.p1 = (float3) {0.0, 0.0, 0.0};
    T.p2 = (float3) {0.0, 0.0, 0.0};

    L.p0 = (float3) {0.0, 0.0, 0.0};
    L.p1 = (float3) {0.0, 0.0, 0.0};

    return sum;
}
