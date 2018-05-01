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
#include <memory.h>
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
    VertexBuffers buffer;
    buffer.Verticies = NULL;
    buffer.Normals = NULL;
    buffer.Texture = NULL;

    printf("Testing Obj File Opening\n");

    //printf("%lu\n", (unsigned long)verticies);
    ReadOBJFile("./Test/cube.obj", 0, &buffer);
    //printf("%lu\n", (unsigned long)verticies);

    free(buffer.Verticies);
    free(buffer.Normals);
    free(buffer.Texture);
    
    return sum;
}