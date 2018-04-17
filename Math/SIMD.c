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
    asm ("vmovaps (%2), %%xmm0\n\t"
        "vdivps (%1), %%xmm0, %%xmm0\n\t"
        "vmovaps %%xmm0, %0\n\t"
        : "=m" (*C) 
        : "r" (A), "r" (B)
    );
}


void add_d4(double4* A, double4* B, double4* C)
{    
    asm (
        "vmovapd (%2), %%ymm0\n\t"
        "vaddpd (%1), %%ymm0, %%ymm1\n\t"
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
