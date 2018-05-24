// --------------------------------------------------
// Polygon.h  
// 
// Polygon Routines and Data Structures
//
// Steven Novak
//
// 04/22/2018
//
// --------------------------------------------------

#ifndef POLYGON_H
#define POLYGON_H

#define NONOPTIMIZED

#include <math.h>
#include "Primatives.h"

// -------------------------------------------------- Polygons

typedef struct 
{
    float2 p0;
    float2 p1;
} LineF2;

typedef struct 
{
    float3 p0;
    float3 p1;
} LineF3;

typedef struct 
{
    float4 p0;
    float4 p1;
} LineF4;

typedef struct 
{
    double2 p0;
    double2 p1;
} LineD2;

typedef struct 
{
    double3 p0;
    double3 p1;
} LineD3;

typedef struct 
{
    double4 p0;
    double4 p1;
} LineD4;

typedef struct 
{
    float2 p0;
    float2 p1;
    float2 p2;
} TriangleF2;

typedef struct 
{
    float3 p0;
    float3 p1;
    float3 p2;
} TriangleF3 ;

typedef struct 
{
    float4 p0;
    float4 p1;
    float4 p2;
} TriangleF4 ;

typedef struct 
{
    double2 p0;
    double2 p1;
    double2 p2;
} TriangleD2;

typedef struct 
{
    double3 p0;
    double3 p1;
    double3 p2;
} TriangleD3 ;

typedef struct 
{
    double4 p0;
    double4 p1;
    double4 p2;
} TriangleD4 ;

typedef struct 
{
    float2 p0;
    float2 p1;
    float2 p2;
    float2 p3;
} QuadF2;

typedef struct 
{
    float3 p0;
    float3 p1;
    float3 p2;
    float3 p3;
} QuadF3 ;

typedef struct 
{
    float4 p0;
    float4 p1;
    float4 p2;
    float4 p3;
} QuadF4 ;

typedef struct 
{
    float a;
    float b;
    float c;
    float d;
} PlaneF ;

// -------------------------------------------------- Functions

void normalF3(TriangleF3*, float3*);
void normalF4(TriangleF4*, float4*);
void normF3(TriangleF3*, float3*);
void normF4(TriangleF4*, float4*);

void normalD3(TriangleD3*, double3*);
void normalD4(TriangleD4*, double4*);
void normD3(TriangleD3*, double3*);
void normD4(TriangleD4*, double4*);

int LF3IntersectTF3(float3* p0, float3* p1, TriangleF3* T, float3* out);

int MTIntersectF3(float3* origin, float3* vector, TriangleF3* T, float3* out);

int planeFromTriF3(TriangleF3* T, PlaneF* plane);

#endif