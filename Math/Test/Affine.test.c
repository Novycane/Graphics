// --------------------------------------------------
// Affine.test.c  
// 
// Affine Test Routines
//
// Steven Novak
//
// 04/13/2018
//
// --------------------------------------------------

#include <stdio.h>

#include "../Affine.h"

// --------------------------------------------------
// ------------------------- Error Code


// --------------------------------------------------
// ------------------------- Headers

int TestPerspectiveF();
int TestPerspectiveD();

// --------------------------------------------------
// ------------------------- Main

int main(int argCount, char** args)
{
    TestPerspectiveF();
    TestPerspectiveD();
}

// -------------------------------------------------- Tests

int TestPerspectiveF()
{
    int sum = 0;
    matrix_F4x4 A;

    printf("Testing PerspectiveF Matrix\n");

    perspectiveF(1, 3.14/4.0, 100, 1, &A);

    return sum;
}

int TestPerspectiveD()
{
    int sum = 0;
    matrix_D4x4 A;

    printf("Testing PerspectiveD Matrix\n");

    perspectiveD(1, 3.14/4.0, 100, 1, &A);
    
    return sum;
}