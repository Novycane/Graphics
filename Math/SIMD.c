// --------------------------------------------------
// SIMD.c  
// 
// SIMD Routines and Data Structures
//
// Steven Novak
//
// 04/11/2018
//
// --------------------------------------------------

#include "SIMD.h"

// --------------------------------------------------
// ------------------------- Functions

#ifdef NONOPTIMIZED

// ------------------------- Single
void add_f2(float2* A, float2* B, float2* C)
{
    C->x = A->x + B->x;
    C->y = A->y + B->y;
}
void subtract_f2(float2* A, float2* B, float2* C)
{
    C->x = A->x - B->x;
    C->y = A->y - B->y;
}
void multiply_f2(float2* A, float2* B, float2* C)
{
    C->x = A->x * B->x;
    C->y = A->y * B->y;
}
void divide_f2(float2* A, float2* B, float2* C)
{
    C->x = A->x / B->x;
    C->y = A->y / B->y;
}

void add_f3(float3* A, float3* B, float3* C)
{
    C->x = A->x + B->x;
    C->y = A->y + B->y;
    C->z = A->z + B->z;
}
void subtract_f3(float3* A, float3* B, float3* C)
{
    C->x = A->x - B->x;
    C->y = A->y - B->y;
    C->z = A->z - B->z;
}
void multiply_f3(float3* A, float3* B, float3* C)
{
    C->x = A->x * B->x;
    C->y = A->y * B->y;
    C->z = A->z * B->z;
}
void divide_f3(float3* A, float3* B, float3* C)
{
    C->x = A->x / B->x;
    C->y = A->y / B->y;
    C->z = A->z / B->z;
}

void add_f4(float4* A, float4* B, float4* C)
{
    C->x = A->x + B->x;
    C->y = A->y + B->y;
    C->z = A->z + B->z;
    C->w = A->w + B->w;
}
void subtract_f4(float4* A, float4* B, float4* C)
{
    C->x = A->x - B->x;
    C->y = A->y - B->y;
    C->z = A->z - B->z;
    C->w = A->w - B->w;
}
void multiply_f4(float4* A, float4* B, float4* C)
{
    C->x = A->x * B->x;
    C->y = A->y * B->y;
    C->z = A->z * B->z;
    C->w = A->w * B->w;
}
void divide_f4(float4* A, float4* B, float4* C)
{
    C->x = A->x / B->x;
    C->y = A->y / B->y;
    C->z = A->z / B->z;
    C->w = A->w / B->w;
}

void matrix_multiply_f4(matrix_float4x4* A, float4* x, float4* b)
{
    b->x = (A->c0.r0 * x->x) + (A->c1.r0 * x->y) + (A->c2.r0 * x->z) + (A->c3.r0 * x->w);
    b->y = (A->c0.r1 * x->x) + (A->c1.r1 * x->y) + (A->c2.r1 * x->z) + (A->c3.r1 * x->w);
    b->z = (A->c0.r2 * x->x) + (A->c1.r2 * x->y) + (A->c2.r2 * x->z) + (A->c3.r2 * x->w);
    b->w = (A->c0.r3 * x->x) + (A->c1.r3 * x->y) + (A->c2.r3 * x->z) + (A->c3.r3 * x->w);
}

// ------------------------- Double
void add_d2(double2* A, double2* B, double2* C)
{
    C->x = A->x + B->x;
    C->y = A->y + B->y;
}
void subtract_d2(double2* A, double2* B, double2* C)
{
    C->x = A->x - B->x;
    C->y = A->y - B->y;
}
void multiply_d2(double2* A, double2* B, double2* C)
{
    C->x = A->x * B->x;
    C->y = A->y * B->y;
}
void divide_d2(double2* A, double2* B, double2* C)
{
    C->x = A->x / B->x;
    C->y = A->y / B->y;
}

void add_d3(double3* A, double3* B, double3* C)
{
    C->x = A->x + B->x;
    C->y = A->y + B->y;
    C->z = A->z + B->z;
}
void subtract_d3(double3* A, double3* B, double3* C)
{
    C->x = A->x - B->x;
    C->y = A->y - B->y;
    C->z = A->z - B->z;
}
void multiply_d3(double3* A, double3* B, double3* C)
{
    C->x = A->x * B->x;
    C->y = A->y * B->y;
    C->z = A->z * B->z;
}
void divide_d3(double3* A, double3* B, double3* C)
{
    C->x = A->x / B->x;
    C->y = A->y / B->y;
    C->z = A->z / B->z;
}

void add_d4(double4* A, double4* B, double4* C)
{
    C->x = A->x + B->x;
    C->y = A->y + B->y;
    C->z = A->z + B->z;
    C->w = A->w + B->w;
}
void subtract_d4(double4* A, double4* B, double4* C)
{
    C->x = A->x - B->x;
    C->y = A->y - B->y;
    C->z = A->z - B->z;
    C->w = A->w - B->w;
}
void multiply_d4(double4* A, double4* B, double4* C)
{
    C->x = A->x * B->x;
    C->y = A->y * B->y;
    C->z = A->z * B->z;
    C->w = A->w * B->w;
}
void divide_d4(double4* A, double4* B, double4* C)
{
    C->x = A->x / B->x;
    C->y = A->y / B->y;
    C->z = A->z / B->z;
    C->w = A->w / B->w;
}

void matrix_multiply_d4(matrix_double4x4* A, double4* x, double4* b)
{
    b->x = (A->c0.r0 * x->x) + (A->c1.r0 * x->y) + (A->c2.r0 * x->z) + (A->c3.r0 * x->w);
    b->y = (A->c0.r1 * x->x) + (A->c1.r1 * x->y) + (A->c2.r1 * x->z) + (A->c3.r1 * x->w);
    b->z = (A->c0.r2 * x->x) + (A->c1.r2 * x->y) + (A->c2.r2 * x->z) + (A->c3.r2 * x->w);
    b->w = (A->c0.r3 * x->x) + (A->c1.r3 * x->y) + (A->c2.r3 * x->z) + (A->c3.r3 * x->w);
}

// -------------------------------------------------- Vector PRoducts

void dotF2(float2* A,float2* B, float* c)
{
    *c = A->x * B->x + A->y * B->y;
}

void dotF3(float3* A,float3* B, float* c)
{
    *c = A->x * B->x + A->y * B->y + A->z * B->z;
}

void dotF4(float4* A,float4* B, float* c)
{
    *c = A->x * B->x + A->y * B->y + A->z * B->z;
}

void dotD2(double2* A, double2* B, double* c)
{
    *c = A->x * B->x + A->y * B->y;
}

void dotD3(double3* A, double3* B, double* c)
{
    *c = A->x * B->x + A->y * B->y + A->z * B->z;
}

void dotD4(double4* A, double4* B, double* c)
{
    *c = A->x * B->x + A->y * B->y + A->z * B->z;
}

void crossF3(float3* A, float3* B, float3* C)
{
    C->x = (A->y * B->z) - (A->z * B->y);
    C->y = (A->z * B->x) - (A->x * B->z);
    C->z = (A->x * B->y) - (A->y * B->x);
}

void crossF4(float4* A, float4* B, float4* C)
{
    C->x = (A->y * B->z) - (A->z * B->y);
    C->y = (A->z * B->x) - (A->x * B->z);
    C->z = (A->x * B->y) - (A->y * B->x);
}

void crossD3(double3* A, double3* B, double3* C)
{
    C->x = (A->y * B->z) - (A->z * B->y);
    C->y = (A->z * B->x) - (A->x * B->z);
    C->z = (A->x * B->y) - (A->y * B->x);
}

void crossD4(double4* A, double4* B, double4* C)
{
    C->x = (A->y * B->z) - (A->z * B->y);
    C->y = (A->z * B->x) - (A->x * B->z);
    C->z = (A->x * B->y) - (A->y * B->x);
}

// -------------------------------------------------- Polygons

void normalF3(TriangleF3* T, float3* N)
{
    float3 U, V;
    subtract_f3(&(T->p1), &(T->p0), &U);
    subtract_f3(&(T->p2), &(T->p0), &V);

    N->x = (U.y * V.z) - (U.z * V.y);
    N->y = (U.z * V.x) - (U.x * V.z);
    N->z = (U.x * V.y) - (U.y * V.x);
}

void normalF4(TriangleF4* T, float4* N)
{
    float4 U, V;
    subtract_f4(&(T->p1), &(T->p0), &U);
    subtract_f4(&(T->p2), &(T->p0), &V);

    N->x = (U.y * V.z) - (U.z * V.y);
    N->y = (U.z * V.x) - (U.x * V.z);
    N->z = (U.x * V.y) - (U.y * V.x);
    N->w = 1.0;
}

void normalD3(TriangleD3* T, double3* N)
{
    double3 U, V;
    subtract_d3(&(T->p1), &(T->p0), &U);
    subtract_d3(&(T->p2), &(T->p0), &V);

    N->x = (U.y * V.z) - (U.z * V.y);
    N->y = (U.z * V.x) - (U.x * V.z);
    N->z = (U.x * V.y) - (U.y * V.x);
}

void normalD4(TriangleD4* T, double4* N)
{
    double4 U, V;
    subtract_d4(&(T->p1), &(T->p0), &U);
    subtract_d4(&(T->p2), &(T->p0), &V);

    N->x = (U.y * V.z) - (U.z * V.y);
    N->y = (U.z * V.x) - (U.x * V.z);
    N->z = (U.x * V.y) - (U.y * V.x);
    N->w = 1.0;
}


#else

// ------------------------- Single
void add_f2(float2* A, float2* B, float2* C)
{
    asm("movlps (%1), %%xmm0\n\t"
        "movlps (%2), %%xmm1\n\t"
        "addps %%xmm1, %%xmm0\n\t"
        "movlps %%xmm0, %0\n\t"
        : "=m" (*C) 
        : "r" (A), "r" (B)
    );
}

void subtract_f2(float2* A, float2* B, float2* C)
{
    asm("movlps (%1), %%xmm0\n\t"
        "movlps (%2), %%xmm1\n\t"
        "subps %%xmm1, %%xmm0\n\t"
        "movlps %%xmm0, %0\n\t"
        : "=m" (*C) 
        : "r" (A), "r" (B)
    );
}

void multiply_f2(float2* A, float2* B, float2* C)
{
    asm("movlps (%1), %%xmm0\n\t"
        "movlps (%2), %%xmm1\n\t"
        "mulps %%xmm1, %%xmm0\n\t"
        "movlps %%xmm0, %0\n\t"
        : "=m" (*C) 
        : "r" (A), "r" (B)
    );
}

void divide_f2(float2* A, float2* B, float2* C)
{
    asm("movlps (%1), %%xmm0\n\t"
        "movlps (%2), %%xmm1\n\t"
        "divps %%xmm1, %%xmm0\n\t"
        "movlps %%xmm0, %0\n\t"
        : "=m" (*C) 
        : "r" (A), "r" (B)
    );
}

void add_f4(float4* A, float4* B, float4* C)
{
    asm ("vmovaps (%1), %%xmm0\n\t"
        "vaddps (%2), %%xmm0, %%xmm0\n\t"
        "vmovaps %%xmm0, %0\n\t"
        : "=m" (*C) 
        : "r" (A), "r" (B)
    );
}

void subtract_f4(float4* A, float4* B, float4* C)
{
    asm ("vmovaps (%1), %%xmm0\n\t"
        "vsubps (%2), %%xmm0, %%xmm0\n\t"
        "vmovaps %%xmm0, %0\n\t"
        : "=m" (*C) 
        : "r" (A), "r" (B)
    );
}

void multiply_f4(float4* A, float4* B, float4* C)
{
    asm ("vmovaps (%1), %%xmm0\n\t"
        "vmulps (%2), %%xmm0, %%xmm0\n\t"
        "vmovaps %%xmm0, %0\n\t"
        : "=m" (*C) 
        : "r" (A), "r" (B)
    );
}

void divide_f4(float4* A, float4* B, float4* C)
{
    asm ("vmovaps (%1), %%xmm0\n\t"
        "vdivps (%2), %%xmm0, %%xmm0\n\t"
        "vmovaps %%xmm0, %0\n\t"
        : "=m" (*C) 
        : "r" (A), "r" (B)
    );
}

void matrix_multiply_f4(matrix_float4x4* A ,float4* x, float4* b)
{    
    asm ("vmovaps (%1), %%xmm0\n\t"
        "vdivps (%2), %%xmm0, %%xmm0\n\t"
        "vmovaps %%xmm0, %0\n\t"
        : "=m" (*b) 
        : "r" (A), "r" (x)
    );
}

// ------------------------- Double
void add_d2(double2* A, double2* B, double2* C)
{    
    asm (
        "vmovapd (%1), %%xmm0\n\t"
        "vaddpd (%2), %%xmm0, %%xmm0\n\t"
        "vmovapd %%xmm0, %0"
        : "=m" (*C)
        : "r" (A), "r" (B)
    );
}

void subtract_d2(double2* A, double2* B, double2* C)
{
    asm (
        "vmovapd (%1), %%xmm0\n\t"
        "vsubpd (%2), %%xmm0, %%xmm0\n\t"
        "vmovapd %%xmm0, %0"
        : "=m" (*C)
        : "r" (A), "r" (B)
    );
}

void multiply_d2(double2* A, double2* B, double2* C)
{
    asm (
        "vmovapd (%1), %%xmm0\n\t"
        "vmulpd (%2), %%xmm0, %%xmm0\n\t"
        "vmovapd %%xmm0, %0"
        : "=m" (*C)
        : "r" (A), "r" (B)
    );
}

void divide_d2(double2* A, double2* B, double2* C)
{
    asm (
        "vmovapd (%1), %%xmm0\n\t"
        "vdivpd (%2), %%xmm0, %%xmm0\n\t"
        "vmovapd %%xmm0, %0"
        : "=m" (*C)
        : "r" (A), "r" (B)
    );
}

void add_d4(double4* A, double4* B, double4* C)
{    
    asm (
        "vmovapd (%1), %%ymm0\n\t"
        "vaddpd (%2), %%ymm0, %%ymm1\n\t"
        "vmovapd %%ymm1, %0"
        : "=m" (*C)
        : "r" (A), "r" (B)
    );
}

void subtract_d4(double4* A, double4* B, double4* C)
{
    asm (
        "vmovapd (%1), %%ymm0\n\t"
        "vsubpd (%2), %%ymm0, %%ymm1\n\t"
        "vmovapd %%ymm1, %0"
        : "=m" (*C)
        : "r" (A), "r" (B)
    );
}

void multiply_d4(double4* A, double4* B, double4* C)
{
    asm (
        "vmovapd (%1), %%ymm0\n\t"
        "vmulpd (%2), %%ymm0, %%ymm1\n\t"
        "vmovapd %%ymm1, %0"
        : "=m" (*C)
        : "r" (A), "r" (B)
    );
}

void divide_d4(double4* A, double4* B, double4* C)
{
    asm (
        "vmovapd (%1), %%ymm0\n\t"
        "vdivpd (%2), %%ymm0, %%ymm1\n\t"
        "vmovapd %%ymm1, %0"
        : "=m" (*C)
        : "r" (A), "r" (B)
    );
}

// ------------------------- int

#endif