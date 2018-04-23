// --------------------------------------------------
// SIMD.performance.c  
// 
// SIMD Performance Routines
//
// Steven Novak
//
// 04/19/2018
//
// --------------------------------------------------

#include <stdio.h>
#include "../Primatives.h"

#define _ITERATIONS 10000000

// --------------------------------------------------
// ------------------------- Error Code

// --------------------------------------------------
// ------------------------- Headers
void TestTime();


int BenchFloat2Addition();
int BenchFloat4Addition();
int BenchFloat4Matrix();

int BenchDouble2Arithmatic();
int BenchDouble4Arithmatic();

// --------------------------------------------------
// ------------------------- Main

int main(int argCount, char** args)
{
    printf("\n");

    //TestTime();
    
    BenchFloat2Addition();
    BenchFloat4Addition();

    BenchDouble2Arithmatic();
    BenchDouble4Arithmatic();
    
    BenchFloat4Matrix();
    
    return 0;
}

// --------------------------------------------------
// ------------------------- Tests

void TestTime()
{
    printf("TestTime\n");

    unsigned long long ticks;
    unsigned long long ticks2;
    unsigned long* upper;
    unsigned long* lower;

    lower = (unsigned long*) &ticks;
    upper =(unsigned long*) lower + 1;
    printf("Before : %llu \n", ticks);
    ticks2 = ticks;

    for(int i=0; i<20; i++)
    {
        asm("RDTSC"
            :"=d" (*upper), "=a"(*lower) );
        printf("Before : %llu \n", ticks);
        printf("Before : %llu \n", ticks - ticks2);
        ticks2 = ticks;
    }
}

int BenchFloat2Addition()
{
    printf("Single2 Precision Arithmetic Tests\n");
    float2 A, B, C;

    A.x = 0.5;
    A.y = 3.0;

    B.x = 1.0;
    B.y = 2.0;

    
    unsigned long long before, after, sum;
    unsigned long* bUpper;
    unsigned long* bLower;
    
    bLower = (unsigned long*) &before;
    bUpper =(unsigned long*) bLower + 1;

    sum = 0;
    for(int i=0; i< _ITERATIONS;  i++)
    {
        asm("RDTSC"
            :"=d" (*bUpper), "=a"(*bLower) );
        after = before;
        add_f2(&A ,&B, &C);
        asm("RDTSC"
            :"=d" (*bUpper), "=a"(*bLower) );
        sum += (before - after);
    }
    printf("    Average Addition: %f cycles\n", (double)sum / _ITERATIONS);
    
    for(int i=0; i< _ITERATIONS;  i++)
    {
        asm("RDTSC"
            :"=d" (*bUpper), "=a"(*bLower) );
        after = before;
        subtract_f2(&A,&B, &C);
        asm("RDTSC"
            :"=d" (*bUpper), "=a"(*bLower) );
        sum += (before - after);
    }
    printf("    Average Subtraction: %f cycles\n", (double)sum / _ITERATIONS);
    
    for(int i=0; i< _ITERATIONS;  i++)
    {
        asm("RDTSC"
            :"=d" (*bUpper), "=a"(*bLower) );
        after = before;
        multiply_f2(&A,&B, &C);
        asm("RDTSC"
            :"=d" (*bUpper), "=a"(*bLower) );
        sum += (before - after);
    }
    printf("    Average Multiplication: %f cycles\n", (double)sum / _ITERATIONS);
    
    for(int i=0; i< _ITERATIONS;  i++)
    {
        asm("RDTSC"
            :"=d" (*bUpper), "=a"(*bLower) );
        after = before;
        divide_f2(&A,&B, &C);
        asm("RDTSC"
            :"=d" (*bUpper), "=a"(*bLower) );
        sum += (before - after);
    }
    printf("    Average Division: %f cycles\n", (double)sum / _ITERATIONS);

    return sum;
}

int BenchFloat4Matrix()
{
    matrix_float4x4 A;
    float4 b, x;
    printf("Single4x4 Matrix Multiplication Tests\n");
    
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
    
    unsigned long long before, after, sum;
    unsigned long* bUpper;
    unsigned long* bLower;
    
    bLower = (unsigned long*) &before;
    bUpper =(unsigned long*) bLower + 1;

    sum = 0;
    for(int i=0; i< _ITERATIONS;  i++)
    {
        asm("RDTSC"
            :"=d" (*bUpper), "=a"(*bLower) );
        after = before;
        matrix_multiply_f4(&A, &x, &b); 
        asm("RDTSC"
            :"=d" (*bUpper), "=a"(*bLower) );
        sum += (before - after);
    }
    printf("    Average 4x4 Multiplication: %f cycles\n", (double)sum / _ITERATIONS);

    return sum;
}

int BenchFloat4Addition()
{
    printf("Single4 Precision Arithmetic Tests\n");
    float4 A, B, C;

    A.x = 0.5;
    A.y = 3.0;
    A.z = -4.0;
    A.w = 1.0;

    B.x = 1.0;
    B.y = 2.0;
    B.z = 1.0;
    B.w = 2.0;

    unsigned long long before, after, sum;
    unsigned long* bUpper;
    unsigned long* bLower;
    
    bLower = (unsigned long*) &before;
    bUpper =(unsigned long*) bLower + 1;

    sum = 0;
    for(int i=0; i< _ITERATIONS;  i++)
    {
        asm("RDTSC"
            :"=d" (*bUpper), "=a"(*bLower) );
        after = before;
        add_f4(&A,&B, &C);
        asm("RDTSC"
            :"=d" (*bUpper), "=a"(*bLower) );
        sum += (before - after);
    }
    printf("    Average Single4 Addition: %f cycles\n", (double)sum / _ITERATIONS);
    
    sum = 0;
    for(int i=0; i< _ITERATIONS;  i++)
    {
        asm("RDTSC"
            :"=d" (*bUpper), "=a"(*bLower) );
        after = before;
        subtract_f4(&A,&B, &C);
        asm("RDTSC"
            :"=d" (*bUpper), "=a"(*bLower) );
        sum += (before - after);
    }
    printf("    Average Single4 Addition: %f cycles\n", (double)sum / _ITERATIONS);
    
    sum = 0;
    for(int i=0; i< _ITERATIONS;  i++)
    {
        asm("RDTSC"
            :"=d" (*bUpper), "=a"(*bLower) );
        after = before;
        multiply_f4(&A,&B, &C);
        asm("RDTSC"
            :"=d" (*bUpper), "=a"(*bLower) );
        sum += (before - after);
    }
    printf("    Average Single4 Addition: %f cycles\n", (double)sum / _ITERATIONS);
    
    sum = 0;
    for(int i=0; i< _ITERATIONS;  i++)
    {
        asm("RDTSC"
            :"=d" (*bUpper), "=a"(*bLower) );
        after = before;
        divide_f4(&A, &B, &C);
        asm("RDTSC"
            :"=d" (*bUpper), "=a"(*bLower) );
        sum += (before - after);
    }
    printf("    Average Single4 Addition: %f cycles\n", (double)sum / _ITERATIONS);
    return sum;
}

int BenchDouble4Arithmatic()
{
    printf("Double4 Arithmatic Tests\n");
    double4 A, B, C;    

    A.x = 20.0;
    A.y = 30.0;
    A.z = 40.0;
    A.w = 50.0;

    B.x = 10.0;
    B.y = 10.0;
    B.z = 10.0;
    B.w = 10.0;

    unsigned long long before, after, sum;
    unsigned long* bUpper;
    unsigned long* bLower;
    
    bLower = (unsigned long*) &before;
    bUpper =(unsigned long*) bLower + 1;

    sum = 0;
    for(int i=0; i< _ITERATIONS;  i++)
    {
        asm("RDTSC"
            :"=d" (*bUpper), "=a"(*bLower) );
        after = before;
        add_d4(&A, &B, &C);
        asm("RDTSC"
            :"=d" (*bUpper), "=a"(*bLower) );
        sum += (before - after);
    }
    printf("    Average Single4 Addition: %f cycles\n", (double)sum / _ITERATIONS);  
    
    bLower = (unsigned long*) &before;
    bUpper =(unsigned long*) bLower + 1;

    sum = 0;
    for(int i=0; i< _ITERATIONS;  i++)
    {
        asm("RDTSC"
            :"=d" (*bUpper), "=a"(*bLower) );
        after = before;
        subtract_d4(&A, &B, &C);
        asm("RDTSC"
            :"=d" (*bUpper), "=a"(*bLower) );
        sum += (before - after);
    }
    printf("    Average Single4 Addition: %f cycles\n", (double)sum / _ITERATIONS);

    bLower = (unsigned long*) &before;
    bUpper =(unsigned long*) bLower + 1;

    sum = 0;
    for(int i=0; i< _ITERATIONS;  i++)
    {
        asm("RDTSC"
            :"=d" (*bUpper), "=a"(*bLower) );
        after = before;
        multiply_d4(&A, &B, &C);
        asm("RDTSC"
            :"=d" (*bUpper), "=a"(*bLower) );
        sum += (before - after);
    }
    printf("    Average Single4 Addition: %f cycles\n", (double)sum / _ITERATIONS);

    bLower = (unsigned long*) &before;
    bUpper =(unsigned long*) bLower + 1;

    sum = 0;
    for(int i=0; i< _ITERATIONS;  i++)
    {
        asm("RDTSC"
            :"=d" (*bUpper), "=a"(*bLower) );
        after = before;
        divide_d4(&A, &B, &C);
        asm("RDTSC"
            :"=d" (*bUpper), "=a"(*bLower) );
        sum += (before - after);
    }
    printf("    Average Single4 Addition: %f cycles\n", (double)sum / _ITERATIONS);
    
    return sum;
}

int BenchDouble2Arithmatic()
{
    printf("Double2 Arithmatic Tests\n");
    double2 A, B, C;

    A.x = 20.0;
    A.y = 30.0;
    
    B.x = 10.0;
    B.y = 10.0;
    
    unsigned long long before, after, sum;
    unsigned long* bUpper;
    unsigned long* bLower;
    
    bLower = (unsigned long*) &before;
    bUpper =(unsigned long*) bLower + 1;

    sum = 0;
    for(int i=0; i< _ITERATIONS;  i++)
    {
        asm("RDTSC"
            :"=d" (*bUpper), "=a"(*bLower) );
        after = before;
        add_d2(&A, &B, &C);
        asm("RDTSC"
            :"=d" (*bUpper), "=a"(*bLower) );
        sum += (before - after);
    }
    printf("    Average Single4 Addition: %f cycles\n", (double)sum / _ITERATIONS);  
 
    sum = 0;
    for(int i=0; i< _ITERATIONS;  i++)
    {
        asm("RDTSC"
            :"=d" (*bUpper), "=a"(*bLower) );
        after = before;
        subtract_d2(&A, &B, &C);
        asm("RDTSC"
            :"=d" (*bUpper), "=a"(*bLower) );
        sum += (before - after);
    }
    printf("    Average Single4 Addition: %f cycles\n", (double)sum / _ITERATIONS);  
 
    sum = 0;
    for(int i=0; i< _ITERATIONS;  i++)
    {
        asm("RDTSC"
            :"=d" (*bUpper), "=a"(*bLower) );
        after = before;
        multiply_d2(&A, &B, &C);
        asm("RDTSC"
            :"=d" (*bUpper), "=a"(*bLower) );
        sum += (before - after);
    }
    printf("    Average Single4 Addition: %f cycles\n", (double)sum / _ITERATIONS);  
    
    sum = 0;
    for(int i=0; i< _ITERATIONS;  i++)
    {
        asm("RDTSC"
            :"=d" (*bUpper), "=a"(*bLower) );
        after = before;
        divide_d2(&A, &B, &C);
        asm("RDTSC"
            :"=d" (*bUpper), "=a"(*bLower) );
        sum += (before - after);
    }
    printf("    Average Single4 Addition: %f cycles\n", (double)sum / _ITERATIONS);  
 
    return sum;
}