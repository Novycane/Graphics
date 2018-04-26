// --------------------------------------------------
// Affine.h  
// 
// Affine Transform Routines
//
// Steven Novak
//
// 04/25/2018
//
// --------------------------------------------------

#include "Affine.h"

#ifdef NONOPTIMIZED

void perspectiveF(float aspect, float field, float far, float near, matrix_F4x4* out)
{
    float fn = far - near;
    out->c1 = (column_float4) { 0.0, 1.0 / tan(field / 2), 0.0, 0.0 };
    out->c0 = (column_float4) { out->c1.r1 / aspect, 0.0, 0.0, 0.0 };
    out->c2 = (column_float4) { 0.0, 0.0, -(far + near) / fn, -1.0 };
    out->c3 = (column_float4) { 0.0, 0.0, -2 * (far * near) / fn, 0.0 };
}

void perspectiveD(double aspect, double field, double far, double near, matrix_D4x4* out)
{
    double fn = far - near;
    out->c1 = (column_double4) { 0.0, 1.0 / tan(field / 2), 0.0, 0.0 };
    out->c0 = (column_double4) { out->c1.r1 / aspect, 0.0, 0.0, 0.0 };
    out->c2 = (column_double4) { 0.0, 0.0, -(far + near) / fn, -1.0 };
    out->c3 = (column_double4) { 0.0, 0.0, -2 * (far * near) / fn, 0.0 };
}

#else

#endif