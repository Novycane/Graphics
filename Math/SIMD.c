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

float4 add_f4(float4* A, float4* B)
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

float4 subtract_f4(float4* A, float4* B)
{
    float4 out;
    asm ("movaps (%1), %%xmm0\n\t"
        "movaps (%2), %%xmm1\n\t"
        "subps %%xmm1, %%xmm0\n\t"
        "movaps %%xmm0, %0\n\t"
        : "=m" (out) 
        : "r" (A), "r" (B)
    );
    return out;
}

float4 multiply_f4(float4* A, float4* B)
{
    float4 out;
    asm ("movaps (%1), %%xmm0\n\t"
        "movaps (%2), %%xmm1\n\t"
        "mulps %%xmm1, %%xmm0\n\t"
        "movaps %%xmm0, %0\n\t"
        : "=m" (out) 
        : "r" (A), "r" (B)
    );
    return out;
}

float4 divide_f4(float4* A, float4* B)
{
    float4 out;
    asm ("movaps (%1), %%xmm0\n\t"
        "movaps (%2), %%xmm1\n\t"
        "divps %%xmm1, %%xmm0\n\t"
        "movaps %%xmm0, %0\n\t"
        : "=m" (out) 
        : "r" (A), "r" (B)
    );
    return out;
}

double4 add_d4(double4* A, double4* B)
{
    double4 out;
    asm ("movapd (%1), %%xmm0\n\t"
        "movapd (%2), %%xmm1\n\t"
        "addpd %%xmm0, %%xmm1\n\t"
        "movapd %%xmm1, %0\n\t"
        : "=m" (out) 
        : "r" (A), "r" (B)
    );
    return out;
}

double4 subtract_d4(double4* A, double4* B)
{
    double4 out;
    asm ("movapd (%1), %%xmm0\n\t"
        "movapd (%2), %%xmm1\n\t"
        //"addpd %%xmm0, %%xmm1\n\t"
        "movapd %%xmm1, %0\n\t"
        : "=m" (out) 
        : "r" (A), "r" (B)
    );
    return out;
}

double4 multiply_d4(double4* A, double4* B)
{
    double4 out;
    asm ("movapd (%1), %%xmm0\n\t"
        "movapd (%2), %%xmm1\n\t"
        //"addpd %%xmm0, %%xmm1\n\t"
        "movapd %%xmm1, %0\n\t"
        : "=m" (out) 
        : "r" (A), "r" (B)
    );
    return out;
}

double4 divide_d4(double4* A, double4* B)
{
    double4 out;
    asm ("movapd (%1), %%xmm0\n\t"
        "movapd (%2), %%xmm1\n\t"
        //"addpd %%xmm0, %%xmm1\n\t"
        "movapd %%xmm1, %0\n\t"
        : "=m" (out) 
        : "r" (A), "r" (B)
    );
    return out;
}