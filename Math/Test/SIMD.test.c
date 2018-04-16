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
#include <pthread.h>
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
int TestThreading();

// --------------------------------------------------
// ------------------------- Main

int main(int argCount, char** args)
{
    printf("\n");
    //TestVectorAddition();
    TestThreading();
    return 0;
}

// --------------------------------------------------
// ------------------------- Tests

int TestVectorAddition()
{
    printf("Vector Addition Tests\n");
    float4 A, B, C;

    A.x = 0.5;
    A.y = 3.0;
    A.z = -4.0;
    A.w = 1.0;

    B.x = 1.0;
    B.y = 2.0;
    B.z = 1.0;
    B.w = 2.0;

    C = A;
    printf("%f, %f, %f, %f\n", C.x, C.y, C.z, C.w);

    C = add_f4(&A,&B);
    printf("%f, %f, %f, %f\n", C.x, C.y, C.z, C.w);

    C = subtract_f4(&A,&B);
    printf("%f, %f, %f, %f\n", C.x, C.y, C.z, C.w);

    C = multiply_f4(&A,&B);
    printf("%f, %f, %f, %f\n", C.x, C.y, C.z, C.w);

    C = divide_f4(&B,&A);
    printf("%f, %f, %f, %f\n", C.x, C.y, C.z, C.w);

    return 1;
}

int TestThreading()
{

    return 1;
}