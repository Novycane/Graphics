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

// ------------------------- Single
void add_f2(float2*, float2*, float2*);
void subtract_f2(float2*, float2*, float2*);
void multiply_f2(float2*, float2*, float2*);
void divide_f2(float2*, float2*, float2*);

void add_f4(float4*, float4*, float4*);
void subtract_f4(float4*, float4*, float4*);
void multiply_f4(float4*, float4*, float4*);
void divide_f4(float4*, float4*, float4*);

// ------------------------- Double
void add_d2(double2*, double2*, double2*);
void subtract_d2(double2*, double2*, double2*);
void multiply_d2(double2*, double2*, double2*);
void divide_d2(double2*, double2*, double2*);

void add_d4(double4*, double4*, double4*);
void subtract_d4(double4*, double4*, double4*);
void multiply_d4(double4*, double4*, double4*);
void divide_d4(double4*, double4*, double4*);

#endif