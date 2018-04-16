// --------------------------------------------------
// SIMD.h  
// 
// SIMD Routines and Data Structures
//
// Steven Novak
//
// 04/11/2018
//
// --------------------------------------------------

#ifndef SIMD_H
#define SIMD_H

// --------------------------------------------------
// ------------------------- Structs

typedef struct
{
    float x;
    float y;
} float2;

typedef struct
{
    float x;
    float y;
    float z;
} float3;

typedef struct
{
    float x;
    float y;
    float z;
    float w;
} float4;

typedef struct
{
    double x;
    double y;
} double2;

typedef struct
{
    double x;
    double y;
    double z;
} double3;

typedef struct
{
    double x;
    double y;
    double z;
    double w;
} double4;

typedef struct
{
    int x;
    int y;
} int2;

typedef struct
{
    int x;
    int y;
    int z;
} int3;

typedef struct
{
    int x;
    int y;
    int z;
    int w;
} int4;


// --------------------------------------------------
// ------------------------- Functions

float4 add_f4(float4*, float4*);
float4 subtract_f4(float4*, float4*);
float4 multiply_f4(float4*, float4*);
float4 divide_f4(float4*, float4*);

double4 add_d4(double4*, double4*);
double4 subtract_d4(double4*, double4*);
double4 multiply_d4(double4*, double4*);
double4 divide_d4(double4*, double4*);

#endif