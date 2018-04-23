// --------------------------------------------------
// Polygon.h  
// 
// Polygot Routines and Data Structures
//
// Steven Novak
//
// 04/22/2018
//
// --------------------------------------------------

#include "Polygon.h"

#ifdef NONOPTIMIZED

// -------------------------------------------------- Polygons

void normalF3(TriangleF3* T, float3* N)
{
    float3 U, V;
    subtract_f3(&(T->p2), &(T->p0), &U);
    subtract_f3(&(T->p1), &(T->p0), &V);

    N->x = (U.y * V.z) - (U.z * V.y);
    N->y = (U.z * V.x) - (U.x * V.z);
    N->z = (U.x * V.y) - (U.y * V.x);
}

void normalF4(TriangleF4* T, float4* N)
{
    float4 U, V;
    subtract_f4(&(T->p2), &(T->p0), &U);
    subtract_f4(&(T->p1), &(T->p0), &V);

    N->x = (U.y * V.z) - (U.z * V.y);
    N->y = (U.z * V.x) - (U.x * V.z);
    N->z = (U.x * V.y) - (U.y * V.x);
}

void normalD3(TriangleD3* T, double3* N)
{
    double3 U, V;
    subtract_d3(&(T->p2), &(T->p0), &U);
    subtract_d3(&(T->p1), &(T->p0), &V);

    N->x = (U.y * V.z) - (U.z * V.y);
    N->y = (U.z * V.x) - (U.x * V.z);
    N->z = (U.x * V.y) - (U.y * V.x);
}

void normalD4(TriangleD4* T, double4* N)
{
    double4 U, V;
    subtract_d4(&(T->p2), &(T->p0), &U);
    subtract_d4(&(T->p1), &(T->p0), &V);

    N->x = (U.y * V.z) - (U.z * V.y);
    N->y = (U.z * V.x) - (U.x * V.z);
    N->z = (U.x * V.y) - (U.y * V.x);
}

#else

#endif