// --------------------------------------------------
// ObjFile.test.c  
// 
// ObjFile Test Routines
//
// Steven Novak
//
// 04/26/2018
//
// --------------------------------------------------

#include <stdio.h>
#include "../ObjFile.h"

// --------------------------------------------------
// ------------------------- Error Code

// --------------------------------------------------
// ------------------------- Headers

int TestOpenFile();

// --------------------------------------------------
// ------------------------- Main

int main(int argCount, char** args)
{
    TestOpenFile();
    return 0;
}

// --------------------------------------------------
// ------------------------- Test

int TestOpenFile()
{
    int sum = 0;
    printf("Testing Obj File Opening\n");

    EchoFile("cube.obj");

    return sum;
}