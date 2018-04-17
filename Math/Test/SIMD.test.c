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


// --------------------------------------------------
// ------------------------- Headers

int TestFloat2Addition();
int TestFloat4Addition();

int TestDouble2Arithmatic();
int TestDouble4Arithmatic();

// --------------------------------------------------
// ------------------------- Main

int main(int argCount, char** args)
{
    printf("\n");

    //TestFloat2Addition();
    TestFloat4Addition();
    
    TestDouble2Arithmatic();
    TestDouble4Arithmatic();

    return 0;
}

// --------------------------------------------------
// ------------------------- Tests

int TestFloat2Addition()
{
    printf("Single2 Precision Arithmetic Tests\n");
    float2 A, B, C;

    int sum = 0;

    A.x = 0.5;
    A.y = 3.0;

    B.x = 1.0;
    B.y = 2.0;

    add_f2(&A,&B, &C);
    if( A.x + B.x != C.x ||
        A.y + B.y != C.y )
    {
        printf("Error In Single2 Precision Addition\n");
        printf("A: %f, %f\n", A.x, A.y);
        printf("B: %f, %f\n", B.x, B.y);
        printf("C: %f, %f\n", C.x, C.y);
        sum++;
    }

    subtract_f2(&A,&B, &C);
    if( A.x - B.x != C.x ||
        A.y - B.y != C.y )
    {
        printf("Error In Single2 Precision Subtraction\n");
        printf("A: %f, %f\n", A.x, A.y);
        printf("B: %f, %f\n", B.x, B.y);
        printf("C: %f, %f\n", C.x, C.y);
        sum++;
    }

    multiply_f2(&A,&B, &C);
    if( A.x * B.x != C.x ||
        A.y * B.y != C.y )
    {
        printf("Error In Single2 Precision Addition\n");
        printf("A: %f, %f\n", A.x, A.y);
        printf("B: %f, %f\n", B.x, B.y);
        printf("C: %f, %f\n", C.x, C.y);
        sum++;
    }

    divide_f2(&B,&A, &C);
    if( A.x / B.x != C.x ||
        A.y / B.y != C.y )
    {
        printf("Error In Single2 Precision Division\n");
        printf("A: %f, %f\n", A.x, A.y);
        printf("B: %f, %f\n", B.x, B.y);
        printf("C: %f, %f\n", C.x, C.y);
        sum++;
    }

    return sum;
}

int TestFloat4Addition()
{
    printf("Single4 Precision Arithmetic Tests\n");
    float4 A, B, C;

    int sum = 0;

    A.x = 0.5;
    A.y = 3.0;
    A.z = -4.0;
    A.w = 1.0;

    B.x = 1.0;
    B.y = 2.0;
    B.z = 1.0;
    B.w = 2.0;

    add_f4(&A,&B, &C);
    if( A.x + B.x != C.x ||
        A.y + B.y != C.y ||
        A.z + B.z != C.z ||
        A.w + B.w != C.w)
    {
        printf("Error In Single Precision Addition\n");
        printf("A: %f, %f, %f, %f\n", A.x, A.y, A.z, A.w);
        printf("B: %f, %f, %f, %f\n", B.x, B.y, B.z, B.w);
        printf("C: %f, %f, %f, %f\n", C.x, C.y, C.z, C.w);
        sum++;
    }

    subtract_f4(&A,&B, &C);
    if( A.x - B.x != C.x ||
        A.y - B.y != C.y ||
        A.z - B.z != C.z ||
        A.w - B.w != C.w)
    {
        printf("Error In Single Precision Subtraction\n");
        printf("A: %f, %f, %f, %f\n", A.x, A.y, A.z, A.w);
        printf("B: %f, %f, %f, %f\n", B.x, B.y, B.z, B.w);
        printf("C: %f, %f, %f, %f\n", C.x, C.y, C.z, C.w);
        sum++;
    }

    multiply_f4(&A,&B, &C);
    if( A.x * B.x != C.x ||
        A.y * B.y != C.y ||
        A.z * B.z != C.z ||
        A.w * B.w != C.w)
    {
        printf("Error In Single Precision Multiplication\n");
        printf("A: %f, %f, %f, %f\n", A.x, A.y, A.z, A.w);
        printf("B: %f, %f, %f, %f\n", B.x, B.y, B.z, B.w);
        printf("C: %f, %f, %f, %f\n", C.x, C.y, C.z, C.w);
        sum++;
    }

    divide_f4(&B,&A, &C);
    if( A.x / B.x != C.x ||
        A.y / B.y != C.y ||
        A.z / B.z != C.z ||
        A.w / B.w != C.w)
    {
        printf("Error In Single Precision Division\n");
        printf("A: %f, %f, %f, %f\n", A.x, A.y, A.z, A.w);
        printf("B: %f, %f, %f, %f\n", B.x, B.y, B.z, B.w);
        printf("C: %f, %f, %f, %f\n", C.x, C.y, C.z, C.w);
        sum++;
    }

    return sum;
}

int TestDouble4Arithmatic()
{
    printf("Double4 Arithmatic Tests\n");
    double4 A, B, C;
    int sum = 0;

    A.x = 20.0;
    A.y = 30.0;
    A.z = 40.0;
    A.w = 50.0;

    B.x = 10.0;
    B.y = 10.0;
    B.z = 10.0;
    B.w = 10.0;

    add_d4(&A, &B, &C);
    if( A.x + B.x != C.x ||
        A.y + B.y != C.y ||
        A.z + B.z != C.z ||
        A.w + B.w != C.w)
    {
        printf("Error In Double Precision Addition\n");
        printf("A: %f, %f, %f, %f\n", A.x, A.y, A.z, A.w);
        printf("B: %f, %f, %f, %f\n", B.x, B.y, B.z, B.w);
        printf("C: %f, %f, %f, %f\n", C.x, C.y, C.z, C.w);
        sum++;
    }    

    subtract_d4(&A, &B, &C);
    if( A.x - B.x != C.x ||
        A.y - B.y != C.y ||
        A.z - B.z != C.z ||
        A.w - B.w != C.w)
    {
        printf("Error In Double Precision Subtraction\n");
        printf("A: %f, %f, %f, %f\n", A.x, A.y, A.z, A.w);
        printf("B: %f, %f, %f, %f\n", B.x, B.y, B.z, B.w);
        printf("C: %f, %f, %f, %f\n", C.x, C.y, C.z, C.w);
        sum++;
    }    

    multiply_d4(&A, &B, &C);
    if( A.x * B.x != C.x ||
        A.y * B.y != C.y ||
        A.z * B.z != C.z ||
        A.w * B.w != C.w)
    {
        printf("Error In Double Precision Multiplication\n");
        printf("A: %f, %f, %f, %f\n", A.x, A.y, A.z, A.w);
        printf("B: %f, %f, %f, %f\n", B.x, B.y, B.z, B.w);
        printf("C: %f, %f, %f, %f\n", C.x, C.y, C.z, C.w);
        sum++;
    }    

    divide_d4(&A, &B, &C);
    if( A.x / B.x != C.x ||
        A.y / B.y != C.y ||
        A.z / B.z != C.z ||
        A.w / B.w != C.w)
    {
        printf("Error In Double Precision Divsion\n");
        printf("A: %f, %f, %f, %f\n", A.x, A.y, A.z, A.w);
        printf("B: %f, %f, %f, %f\n", B.x, B.y, B.z, B.w);
        printf("C: %f, %f, %f, %f\n", C.x, C.y, C.z, C.w);
        sum++;
    }    
    return sum;
}

int TestDouble2Arithmatic()
{
    printf("Double2 Arithmatic Tests\n");
    double2 A, B, C;
    int sum = 0;

    A.x = 20.0;
    A.y = 30.0;
    
    B.x = 10.0;
    B.y = 10.0;
    
    add_d2(&A, &B, &C);
    if( A.x + B.x != C.x ||
        A.y + B.y != C.y)
    {
        printf("Error In Double Precision Addition\n");
        printf("A: %f, %f\n", A.x, A.y);
        printf("B: %f, %f\n", B.x, B.y);
        printf("C: %f, %f\n", C.x, C.y);
        sum++;
    }    

    subtract_d2(&A, &B, &C);
    if( A.x - B.x != C.x ||
        A.y - B.y != C.y)
    {
        printf("Error In Double Precision Subtraction\n");
        printf("A: %f, %f\n", A.x, A.y);
        printf("B: %f, %f\n", B.x, B.y);
        printf("C: %f, %f\n", C.x, C.y);
        sum++;
    }

    multiply_d2(&A, &B, &C);
    if( A.x * B.x != C.x ||
        A.y * B.y != C.y)
    {
        printf("Error In Double Precision Multiplication\n");
        printf("A: %f, %f\n", A.x, A.y);
        printf("B: %f, %f\n", B.x, B.y);
        printf("C: %f, %f\n", C.x, C.y);
        sum++;
    }

    divide_d2(&A, &B, &C);
    if( A.x / B.x != C.x ||
        A.y / B.y != C.y)
    {
        printf("Error In Double Precision Addition\n");
        printf("A: %f, %f\n", A.x, A.y);
        printf("B: %f, %f\n", B.x, B.y);
        printf("C: %f, %f\n", C.x, C.y);
        sum++;
    }
    return sum;
}