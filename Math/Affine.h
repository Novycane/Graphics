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

#ifndef AFFINE_H
#define AFFINE_H

#include <math.h>
#include "Primatives.h"

#define NONOPTIMIZED

void transformF(float x, float y, float z, matrix_F4x4* out);
void transformD(double x, double y, double z, matrix_D4x4* out);

void scaleF(float x, float y, float z, matrix_F4x4* out);
void sclaleD(double x, double y, double z, matrix_D4x4* out);

void roatateF(float angleX, float angleY, float angleZ, matrix_F4x4* out);
void roatateD(double angleX, double angleY, double angleZ, matrix_D4x4* out);

void perspectiveF(float aspect, float field, float far, float near, matrix_F4x4* out);
void perspectiveD(double aspect, double field, double far, double near, matrix_D4x4* out);

#endif