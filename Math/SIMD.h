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

#define NONOPTIMIZED

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
    float r0;
    float r1;
    float r2;
    float r3;
} column_float4;

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

// -------------------------
// -------------------------

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
    column_float4 c0;
    column_float4 c1;
    column_float4 c2;
    column_float4 c3;
} matrix_float4x4;


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

void matrix_multiply_f4(matrix_float4x4* , float4*, float4*);

// ------------------------- Double
void add_d2(double2*, double2*, double2*);
void subtract_d2(double2*, double2*, double2*);
void multiply_d2(double2*, double2*, double2*);
void divide_d2(double2*, double2*, double2*);

void add_d4(double4*, double4*, double4*);
void subtract_d4(double4*, double4*, double4*);
void multiply_d4(double4*, double4*, double4*);
void divide_d4(double4*, double4*, double4*);

void dotF2(float2*, float2*, float*);
void dotF3(float3*, float3*, float*);
void dotF4(float4*, float4*, float*);

void dotD2(double2*, double2*, double*);
void dotD3(double3*, double3*, double*);
void dotD4(double4*, double4*, double*);

#endif