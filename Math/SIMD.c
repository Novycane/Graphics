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

float4 add(float4* A, float4* B)
{
    float4 out;
    asm ("movaps (%1), %%xmm0\n\t"
        "movaps (%2), %%xmm1\n\t"
        "addps %%xmm0, %%xmm1\n\t"
        "movaps %%xmm1, %0\n\t"
        : "=m" (out) 
        : "r" (A), "r" (B)
    );
    return out;
}

float4 subtract(float4* A, float4* B)
{
    float4 out;
    asm ("movaps (%1), %%xmm0\n\t"
        "movaps (%2), %%xmm1\n\t"
        "subps %%xmm0, %%xmm1\n\t"
        "movaps %%xmm1, %0\n\t"
        : "=m" (out) 
        : "r" (A), "r" (B)
    );
    return out;
}