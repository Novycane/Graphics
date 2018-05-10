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

// -------------------------------------------------- Intersections

int LF3IntersectTF3(float3* p0, float3* p1, TriangleF3* T, float3* out)
{
    PlaneF P;
    float3 U, N;
    float Si;

    // Check N * L is not parallel
    planeFromTriF3(T, &P);

    printf("a b c d: {%f, %f, %f %f}\n", P.a, P.b, P.c, P.d);

    // Normalize line U = P1 - P0
    subtract_f3(p1, p0, &U);
    Si = sqrt((U.x * U.x) + (U.y * U.y) + (U.z * U.z)); // Using Si temporarily
    U.x /= Si;
    U.y /= Si;
    U.z /= Si;
    printf("U: X Y Z: {%f, %f, %f}\n", U.x, U.y, U.z);

    // Get Plane Normal N
    normalF3(T, &N);
    Si = sqrt((N.x * N.x) + (N.y * N.y) + (N.z * N.z)); // Using Si temporarily
    N.x /= Si;
    N.y /= Si;
    N.z /= Si;

    printf("N: X Y Z: {%f, %f, %f}\n", N.x, N.y, N.z);

    // Si = -(a*xo + b*y0 + c*z0 + d) / (n * u)
    dotF3(&N, &U, &Si);
    printf("D: %f\n", Si);
    Si = -(P.a * p0->x + P.b * p0->y + P.c * p0->z + P.d) / Si;
    printf("S: %f\n", Si);

    // out = P0 + Si * u
    out->x = p0->x + U.x * Si;
    out->y = p0->y + U.y * Si;
    out->z = p0->z + U.z * Si;

    return 1;
}

// ----- Möller–Trumbore Algorithm
int MTIntersectF3(float3* origin, float3* vector, TriangleF3* T, float3* out)
{
    const float e = 1e-5;

    float3 v0 = T->p0;
    float3 v1 = T->p1;
    float3 v2 = T->p2;

    float3 e1, e2, h, s, q;
    float a, f, u, v;

    subtract_f3(&v1, &v0, &e1);
    subtract_f3(&v2, &v0, &e2);

    crossF3(vector, &e1, &h);
    dotF3(&e1, &h, &a);

    // check a == 0 (or < epsilon)
    if(a > -e || a <  e)
        return 0;
    f = 1.0 / a;
    subtract_f3(origin, &v0, &s);
    dotF3(&s, &h, &u);
    u *= f;
    if(u < 0.0 || u > 1.0)
        return 0;
    crossF3(&s, &e1, &q);
    dotF3(vector, &q, &v);
    v *= f;

    if(v < 0.0 || u + v > 1.0)
        return 0;
    
    float t;
    dotF3(&e2, &q, &t);
    t *= f;

    if (t > e)
    {
        //out = rayOrigin + rayVector * t; 
        out->x = vector->x * t;
        out->y = vector->y * t;
        out->z = vector->z * t;
        add_f3(origin, out, out);
        return 1;
    }
    else 
        return 0;
}

int planeFromTriF3(TriangleF3* T, PlaneF* plane)
{
    float3 v1 = T->p0;
    float3 v2 = T->p1;
    float3 v3 = T->p2;

    plane->a = v1.y*(v2.z-v3.z) + v2.y*(v3.z-v1.z) + v3.y*(v1.z-v2.z);
    plane->b = v1.z*(v2.x-v3.x) + v2.z*(v3.x-v1.x) + v3.z*(v1.x-v2.x);
    plane->c = v1.x*(v2.y-v3.y) + v2.x*(v3.y-v1.y) + v3.x*(v1.y-v2.y);
    plane->d = -( v1.x*( v2.y*v3.z - v3.y*v2.z ) + v2.x*(v3.y*v1.z - v1.y*v3.z) + v3.x*(v1.y*v2.z - v2.y*v1.z) );
    
    return 1;
}

#else

#endif