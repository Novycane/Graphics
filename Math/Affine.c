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

void transformF(float x, float y, float z, matrix_F4x4* out)
{
    out->c0 = (column_float4) { 1.0, 0.0, 0.0, 0.0 };
    out->c1 = (column_float4) { 0.0, 1.0, 0.0, 0.0 };
    out->c2 = (column_float4) { 0.0, 0.0, 1.0, 0.0 };
    out->c3 = (column_float4) {   x,   y,   z, 1.0 };
}
void transformD(double x, double y, double z, matrix_D4x4* out)
{
    out->c0 = (column_double4) { 1.0, 0.0, 0.0, 0.0 };
    out->c1 = (column_double4) { 0.0, 1.0, 0.0, 0.0 };
    out->c2 = (column_double4) { 0.0, 0.0, 1.0, 0.0 };
    out->c3 = (column_double4) {   x,   y,   z, 1.0 };
}

void scaleF(float x, float y, float z, matrix_F4x4* out)
{
    out->c0 = (column_float4) { x, 0.0, 0.0, 0.0 };
    out->c1 = (column_float4) { 0.0, y, 0.0, 0.0 };
    out->c2 = (column_float4) { 0.0, 0.0, z, 0.0 };
    out->c3 = (column_float4) { 0.0, 0.0, 0.0, 1.0 };
}
void sclaleD(double x, double y, double z, matrix_D4x4* out)
{
    out->c0 = (column_double4) { x, 0.0, 0.0, 0.0 };
    out->c1 = (column_double4) { 0.0, y, 0.0, 0.0 };
    out->c2 = (column_double4) { 0.0, 0.0, z, 0.0 };
    out->c3 = (column_double4) { 0.0, 0.0, 0.0, 1.0 };
}

void rotateF(float angleX, float angleY, float angleZ, matrix_F4x4* out)
{
    float cx = cos(angleX);
    float cy = cos(angleY);
    float cz = cos(angleZ);

    float sx = sin(angleX);
    float sy = sin(angleY);
    float sz = sin(angleZ);

    out->c0 = (column_float4) { cy * cz , sx * sy * cz + cx * sz, -cx * sy * cz + sx * sz, 0.0 };
    out->c1 = (column_float4) { 0.0, -sx * sy * sz + cx * cz, -sx * cy, 0.0 };
    out->c2 = (column_float4) { sy, -sx * cy, cx * cy, 0.0 };
    out->c3 = (column_float4) { 0.0, 0.0, 0.0, 1.0 };
}
void rotateD(double angleX, double angleY, double angleZ, matrix_D4x4* out)
{
    double cx = cos(angleX);
    double cy = cos(angleY);
    double cz = cos(angleZ);

    double sx = sin(angleX);
    double sy = sin(angleY);
    double sz = sin(angleZ);

    out->c0 = (column_double4) { cy * cz , sx * sy * cz + cx * sz, -cx * sy * cz + sx * sz, 0.0 };
    out->c1 = (column_double4) { 0.0, -sx * sy * sz + cx * cz, -sx * cy, 0.0 };
    out->c2 = (column_double4) { sy, -sx * cy, cx * cy, 0.0 };
    out->c3 = (column_double4) { 0.0, 0.0, 0.0, 1.0 };
}

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