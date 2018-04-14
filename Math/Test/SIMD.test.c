// --------------------------------------------------
// SIMD.test.c  
// 
// SIMD Test Routines
//
// Steven Novak
//
// 04/13/2018
//
// --------------------------------------------------

#include <stdio.h>
#include "../SIMD.h"

// --------------------------------------------------
// ------------------------- Error Code

/*
typedef enum errorcode
{
    AdditionError = 1,
    SubtractionError
} ErrorCode;
*/

// --------------------------------------------------
// ------------------------- Headers

int TestVectorAddition();

// --------------------------------------------------
// ------------------------- Main

int main(int argCount, char** args)
{
    printf("\n");
    TestVectorAddition();

    return 0;
}

// --------------------------------------------------
// ------------------------- Tests

int TestVectorAddition()
{
    printf("Vector Addition Tests\n");
    float4 A, B;
    float sum = 0.0;

    A.x = 0.0;
    A.y = 3.0;
    A.z = -4.0;
    A.w = 1.0;

    B.x = 1.0;
    B.y = 1.0;
    B.z = 1.0;
    B.w = 1.0;

    B = add(&A,&B);
    
    sum = A.x + 1 - B.x;
    sum += A.y + 1 - B.y;
    sum += A.z + 1 - B.z;
    sum += A.w + 1 - B.w;

    printf("%f, %f, %f, %f\n", A.x, A.y, A.z, A.w);

    return 1;
}