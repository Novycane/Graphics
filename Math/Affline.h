// --------------------------------------------------
// Affline.h  
// 
// Affline Transform Routines
//
// Steven Novak
//
// 04/25/2018
//
// --------------------------------------------------

#ifndef AFFLINE_H
#define AFFLINE_H

#include "Primatives.h"

#define NONOPTIMIZED

void perspectiveF(float aspect, float field, float far, float near, matrix_F4x4* out);


void perspectiveD(double aspect, double field, double far, double near, matrix_D4x4* out);


#endif