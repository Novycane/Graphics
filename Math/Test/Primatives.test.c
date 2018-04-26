// --------------------------------------------------
// Primatives.test.c  
// 
// Primatives Test Routines
//
// Steven Novak
//
// 04/13/2018
//
// --------------------------------------------------

#include <stdio.h>
#include "../Primatives.h"

// --------------------------------------------------
// ------------------------- Error Code


// --------------------------------------------------
// ------------------------- Headers

int TestFloat2Addition();
int TestFloat4Addition();
int TestFloat4Matrix();

int TestDouble2Arithmatic();
int TestDouble4Arithmatic();
int TestDouble4Matrix();

int TestSingle2DotProduct();
int TestSingle3DotProduct();
int TestSingle4DotProduct();

int TestDouble2DotProduct();
int TestDouble3DotProduct();
int TestDouble4DotProduct();

int TestSingle3CrossProduct();
int TestSingle4CrossProduct();

int TestDouble3CrossProduct();
int TestDouble4CrossProduct();

// --------------------------------------------------
// ------------------------- Main

int main(int argCount, char** args)
{
    printf("\n");

    TestFloat2Addition();
    TestFloat4Addition();

    TestDouble2Arithmatic();
    TestDouble4Arithmatic();
    
    TestFloat4Matrix();
    TestDouble4Matrix();

    TestSingle2DotProduct();
    TestSingle3DotProduct();
    TestSingle4DotProduct();

    TestDouble2DotProduct();
    TestDouble3DotProduct();
    TestDouble4DotProduct();

    TestSingle3CrossProduct();
    TestSingle4CrossProduct();
    TestDouble3CrossProduct();
    TestDouble4CrossProduct();

    return 0;
}

// --------------------------------------------------
// ------------------------- Tests

// -------------------------------------------------- Float

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
        printf("Error In Single2 Precision Multiplication\n");
        printf("A: %f, %f\n", A.x, A.y);
        printf("B: %f, %f\n", B.x, B.y);
        printf("C: %f, %f\n", C.x, C.y);
        sum++;
    }

    divide_f2(&A,&B, &C);
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

int TestFloat4Matrix()
{
    int sum = 0;
    matrix_F4x4 A;
    float4 b, x;
    printf("Single2 Precision Matrix Tests\n");
    
    A.c0.r0 = 1.0;
    A.c0.r1 = 0.0;
    A.c0.r2 = 0.0;
    A.c0.r3 = 0.0;

    A.c1.r0 = 0.0;
    A.c1.r1 = 1.0;
    A.c1.r2 = 0.0;
    A.c1.r3 = 0.0;

    A.c2.r0 = 0.0;
    A.c2.r1 = 0.0;
    A.c2.r2 = 1.0;
    A.c2.r3 = 0.0;

    A.c3.r0 = 0.0;
    A.c3.r1 = 0.0;
    A.c3.r2 = 0.0;
    A.c3.r3 = 1.0;
    
    x.x = -2.0;
    x.y = 2.0;
    x.z = 3.0;
    x.w = 2.0;

    b.x = 2.0;
    b.y = 1.0;
    b.z = 2.0;
    b.w = -9.0;
    
    matrix_multiply_f4(&A, &x, &b); 

    if( b.x != x.x ||
        b.y != x.y ||
        b.z != x.z ||
        b.w != x.w)
    {
        printf("Error In Single 4x4 Multiplication\n");
        printf("b: %f, %f, %f, %f\n", b.x, b.y, b.z, b.w);
        printf("x: %f, %f, %f, %f\n", x.x, x.y, x.z, x.w);
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

    divide_f4(&A, &B, &C);
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

// -------------------------------------------------- Double

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

int TestDouble4Matrix()
{
    int sum = 0;
    matrix_D4x4 A;
    double4 b, x;
    printf("Double2 Precision Matrix Tests\n");
    
    A.c0.r0 = 1.0;
    A.c0.r1 = 0.0;
    A.c0.r2 = 0.0;
    A.c0.r3 = 0.0;

    A.c1.r0 = 0.0;
    A.c1.r1 = 1.0;
    A.c1.r2 = 0.0;
    A.c1.r3 = 0.0;

    A.c2.r0 = 0.0;
    A.c2.r1 = 0.0;
    A.c2.r2 = 1.0;
    A.c2.r3 = 0.0;

    A.c3.r0 = 0.0;
    A.c3.r1 = 0.0;
    A.c3.r2 = 0.0;
    A.c3.r3 = 1.0;
    
    x.x = -2.0;
    x.y = 2.0;
    x.z = 3.0;
    x.w = 2.0;

    b.x = 2.0;
    b.y = 1.0;
    b.z = 2.0;
    b.w = -9.0;
    
    matrix_multiply_d4(&A, &x, &b); 

    if( b.x != x.x ||
        b.y != x.y ||
        b.z != x.z ||
        b.w != x.w)
    {
        printf("Error In Double 4x4 Multiplication\n");
        printf("b: %f, %f, %f, %f\n", b.x, b.y, b.z, b.w);
        printf("x: %f, %f, %f, %f\n", x.x, x.y, x.z, x.w);
        sum++;
    }

    return sum;
}

// -------------------------------------------------- DotProd

int TestSingle2DotProduct()
{
    int sum = 0;
    float2 A, B;
    float c;

    A.x = 1.0;
    A.y = 0.0;
    
    B.x = 1.0;
    B.y = 0.0;
    
    printf("Testing dotF2\n");
    dotF2( &A, &B, &c);
    if(c != 1.0 )
        printf("dotF2 expected: 1 Got: %f\n", c);

    A.x = 1.0;
    A.y = 0.0;
    
    B.x = 0.0;
    B.y = 1.0;        
    dotF2( &A, &B, &c);
    if(c != 0.0 )
        printf("dotF2 expected: 0 Got: %f\n", c);

    A.x = -1.0;
    A.y = 0.0;
    
    B.x = 1.0;
    B.y = 1.0;        
    dotF2( &A, &B, &c);
    if(c != -1.0 )
        printf("dotF2 expected: 0 Got: %f\n", c);

    return sum;
}

int TestSingle3DotProduct()
{
    int sum = 0;
    float3 A, B;
    float c;

    A.x = 1.0;
    A.y = 0.0;
    A.z = 0.0;
    
    B.x = 1.0;
    B.y = 0.0;
    B.z = 0.0;
    
    printf("Testing dotF3\n");
    dotF3( &A, &B, &c);
    if(c != 1.0 )
        printf("dotF3 expected: 1 Got: %f\n", c);
    
    A.x = 1.0;
    A.y = 1.0;
    A.z = -1.0;
    
    B.x = 1.0;
    B.y = 0.0;
    B.z = -1.0;
    
    dotF3( &A, &B, &c);
    if(c != 2.0 )
        printf("dotF3 expected: 0 Got: %f\n", c);
    
    return sum;
}

int TestSingle4DotProduct()
{
    int sum = 0;
    float4 A, B;
    float c;

    A.x = 1.0;
    A.y = 0.0;
    A.z = 0.0;
    A.w = 1.0;
    
    B.x = 1.0;
    B.y = 0.0;
    B.z = 0.0;
    B.w = 1.0;
    
    printf("Testing dotF4\n");
    dotF4( &A, &B, &c);
    if(c != 1.0 )
        printf("dotF4 expected: 1 Got: %f\n", c);
    
    A.x = 1.0;
    A.y = 0.0;
    A.z = 0.0;
    A.w = 1.0;
    
    B.x = 0.0;
    B.y = 1.0;
    B.z = 0.0;
    B.w = 1.0;

    dotF4( &A, &B, &c);
    if(c != 0.0 )
        printf("dotF4 expected: 0 Got: %f\n", c);

    A.x = 1.0;
    A.y = 0.0;
    A.z = 1.0;
    A.w = 1.0;
    
    B.x = 0.0;
    B.y = 1.0;
    B.z = 0.0;
    B.w = 1.0;

    dotF4( &A, &B, &c);
    if(c != 0.0 )
        printf("dotF4 expected: 0 Got: %f\n", c);

    return sum;
}

int TestDouble2DotProduct()
{
    int sum = 0;
    double2 A, B;
    double c;
    
    A.x = 1;
    A.y = 0;

    B.x = 1;
    B.y = 0;
    printf("Testing dotD2\n");
    dotD2(&A, &B, &c);
    if(c != 1.0 )
        printf("dotD2 expected: 1 Got: %f\n", c);

    A.x = 1;
    A.y = 0;
    
    B.x = 0;
    B.y = 1;

    dotD2(&A, &B, &c);
    if(c != 0.0 )
        printf("dotD2 expected: 0 Got: %f\n", c);

    A.x = -1.0;
    A.y = 0;

    B.x = 1.0;
    B.y = 1;

    dotD2(&A, &B, &c);
    if(c != -1.0 )
        printf("dotD2 expected: -1 Got: %f\n", c);

    return sum;
}

int TestDouble3DotProduct()
{
    int sum = 0;
    double3 A, B;
    double c;
    
    A.x = 1;
    A.y = 0;
    A.z = 0;

    B.x = 1;
    B.y = 0;
    B.z = 0;
    printf("Testing dotD3\n");
    dotD3(&A, &B, &c);
    if(c != 1.0 )
        printf("dotD3 expected: 1 Got: %f", c);
    
    A.x = 1;
    A.y = 0;
    A.z = 0;

    B.x = 0;
    B.y = 1;
    B.z = 0;

    dotD3(&A, &B, &c);
    if(c != 0.0 )
        printf("dotD3 expected: 1 Got: %f", c);
    
    A.x = 0;
    A.y = 0;
    A.z = 1;

    B.x = 1;
    B.y = 0;
    B.z = 1;

    dotD3(&A, &B, &c);
    if(c != 1.0 )
        printf("dotD3 expected: 1 Got: %f", c);

    A.x = 0;
    A.y = 1;
    A.z = 0;

    B.x = 1;
    B.y = 0;
    B.z = 1;

    dotD3(&A, &B, &c);
    if(c != 0.0 )
        printf("dotD3 expected: 0 Got: %f", c);

    return sum;
}

int TestDouble4DotProduct()
{
    int sum = 0;
    double4 A, B;
    double c;
    
    A.x = 1;
    A.y = 0;
    A.z = 0;
    A.w = 1.0;

    B.x = 1;
    B.y = 0;
    B.z = 0;
    B.w = 1.0;

    printf("Testing dotD4\n");
    dotD4(&A, &B, &c);
    if(c != 1.0 )
        printf("DotD4 expected: 1 Got: %f", c);

    A.x = 0;
    A.y = 1;
    A.z = 0;
    A.w = 1.0;

    B.x = 1;
    B.y = 0;
    B.z = 0;
    B.w = 1.0;

    dotD4(&A, &B, &c);
    if(c != 0.0 )
        printf("DotD4 expected: 0 Got: %f", c);

    A.x = 0;
    A.y = 1;
    A.z = 0;
    A.w = 1.0;

    B.x = 1;
    B.y = 0;
    B.z = 1;
    B.w = 1.0;

    dotD4(&A, &B, &c);
    if(c != 0.0 )
        printf("DotD4 expected: 0 Got: %f", c);

    return sum;
}

// -------------------------------------------------- Cross-Product

int TestSingle3CrossProduct()
{
    float3 X, Y, Z;
    int sum = 0;

    X.x = 1.0;
    X.y = 0.0;
    X.z = 0.0;

    Y.x = 0.0;
    Y.y = 1.0;
    Y.z = 0.0;

    Z.x = -1.0;
    Z.y = -1.0;
    Z.z = -1.0;

    printf("Testing crossF3\n");
    crossF3(&X, &Y, &Z);
    if(Z.x != 0 || 
       Z.y != 0 ||
       Z.z != 1)
    {
        printf("crossF3 error. Expected: {0,0,1} Actual: {%f, %f, %f}\n", Z.x, Z.y, Z.z);
        sum++;
    }

    X.x = 0.0;
    X.y = 1.0;
    X.z = 0.0;

    Y.x = 0.0;
    Y.y = 0.0;
    Y.z = 1.0;

    crossF3(&X, &Y, &Z);
    if(Z.x != 1 || 
       Z.y != 0 ||
       Z.z != 0)
    {
        printf("crossF3 error. Expected: {1,0,0} Actual: {%f, %f, %f}\n", Z.x, Z.y, Z.z);
        sum++;
    }

    X.x = 0.0;
    X.y = 0.0;
    X.z = 1.0;

    Y.x = 1.0;
    Y.y = 0.0;
    Y.z = 0.0;

    crossF3(&X, &Y, &Z);
    if(Z.x != 0 || 
       Z.y != 1 ||
       Z.z != 0)
    {
        printf("crossF3 error. Expected: {0,1,0} Actual: {%f, %f, %f}\n", Z.x, Z.y, Z.z);
        sum++;
    }

    return sum;
}

int TestSingle4CrossProduct()
{
    float4 X, Y, Z;
    int sum = 0;

    X.x = 1.0;
    X.y = 0.0;
    X.z = 0.0;
    X.w = 1.0;

    Y.x = 0.0;
    Y.y = 1.0;
    Y.z = 0.0;
    Y.w = 1.0;

    Z.x = -1.0;
    Z.y = -1.0;
    Z.z = -1.0;
    Z.w = 1.0;

    printf("Testing crossF4\n");
    crossF4(&X, &Y, &Z);
    if(Z.x != 0 || 
       Z.y != 0 ||
       Z.z != 1 ||
       Z.w != 1)
    {
        printf("crossF4 error. Expected: {0,0,1} Actual: {%f, %f, %f}\n", Z.x, Z.y, Z.z);
        sum++;
    }

    X.x = 0.0;
    X.y = 1.0;
    X.z = 0.0;

    Y.x = 0.0;
    Y.y = 0.0;
    Y.z = 1.0;

    crossF4(&X, &Y, &Z);
    if(Z.x != 1 || 
       Z.y != 0 ||
       Z.z != 0 ||
       Z.w != 1)
    {
        printf("crossF4 error. Expected: {1,0,0} Actual: {%f, %f, %f}\n", Z.x, Z.y, Z.z);
        sum++;
    }

    X.x = 0.0;
    X.y = 0.0;
    X.z = 1.0;

    Y.x = 1.0;
    Y.y = 0.0;
    Y.z = 0.0;

    crossF4(&X, &Y, &Z);
    if(Z.x != 0 || 
       Z.y != 1 ||
       Z.z != 0 ||
       Z.w != 1)
    {
        printf("crossF4 error. Expected: {0,1,0} Actual: {%f, %f, %f}\n", Z.x, Z.y, Z.z);
        sum++;
    }

    return sum;
}

int TestDouble3CrossProduct()
{
    double3 X, Y, Z;
    int sum = 0;

    X.x = 1.0;
    X.y = 0.0;
    X.z = 0.0;

    Y.x = 0.0;
    Y.y = 1.0;
    Y.z = 0.0;

    Z.x = -1.0;
    Z.y = -1.0;
    Z.z = -1.0;

    printf("Testing crossD3\n");
    crossD3(&X, &Y, &Z);
    if(Z.x != 0 || 
       Z.y != 0 ||
       Z.z != 1)
    {
        printf("crossD3 error. Expected: {0,0,1} Actual: {%f, %f, %f}\n", Z.x, Z.y, Z.z);
        sum++;
    }

    X.x = 0.0;
    X.y = 1.0;
    X.z = 0.0;

    Y.x = 0.0;
    Y.y = 0.0;
    Y.z = 1.0;

    crossD3(&X, &Y, &Z);
    if(Z.x != 1 || 
       Z.y != 0 ||
       Z.z != 0)
    {
        printf("crossD3 error. Expected: {1,0,0} Actual: {%f, %f, %f}\n", Z.x, Z.y, Z.z);
        sum++;
    }

    X.x = 0.0;
    X.y = 0.0;
    X.z = 1.0;

    Y.x = 1.0;
    Y.y = 0.0;
    Y.z = 0.0;

    crossD3(&X, &Y, &Z);
    if(Z.x != 0 || 
       Z.y != 1 ||
       Z.z != 0)
    {
        printf("crossD3 error. Expected: {0,1,0} Actual: {%f, %f, %f}\n", Z.x, Z.y, Z.z);
        sum++;
    }

    return sum;
}

int TestDouble4CrossProduct()
{
    double4 X, Y, Z;
    int sum = 0;

    X.x = 1.0;
    X.y = 0.0;
    X.z = 0.0;
    X.w = 1.0;

    Y.x = 0.0;
    Y.y = 1.0;
    Y.z = 0.0;
    Y.w = 1.0;

    Z.x = -1.0;
    Z.y = -1.0;
    Z.z = -1.0;
    Z.w = 1.0;

    printf("Testing crossD4\n");
    crossD4(&X, &Y, &Z);
    if(Z.x != 0 || 
       Z.y != 0 ||
       Z.z != 1 ||
       Z.w != 1)
    {
        printf("crossD4 error. Expected: {0,0,1} Actual: {%f, %f, %f}\n", Z.x, Z.y, Z.z);
        sum++;
    }

    X.x = 0.0;
    X.y = 1.0;
    X.z = 0.0;

    Y.x = 0.0;
    Y.y = 0.0;
    Y.z = 1.0;

    crossD4(&X, &Y, &Z);
    if(Z.x != 1 || 
       Z.y != 0 ||
       Z.z != 0 ||
       Z.w != 1)
    {
        printf("crossD4 error. Expected: {1,0,0} Actual: {%f, %f, %f}\n", Z.x, Z.y, Z.z);
        sum++;
    }

    X.x = 0.0;
    X.y = 0.0;
    X.z = 1.0;

    Y.x = 1.0;
    Y.y = 0.0;
    Y.z = 0.0;

    crossD4(&X, &Y, &Z);
    if(Z.x != 0 || 
       Z.y != 1 ||
       Z.z != 0 ||
       Z.w != 1)
    {
        printf("crossD4 error. Expected: {0,1,0} Actual: {%f, %f, %f}\n", Z.x, Z.y, Z.z);
        sum++;
    }

    return sum;
}