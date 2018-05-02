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
    VertexBuffers vertexbuffer;
    TriangleIndexBuffers indexBuffer;
    
    vertexbuffer.Verticies = NULL;
    vertexbuffer.Normals = NULL;
    vertexbuffer.Texture = NULL;
    
    indexBuffer.Verticies = NULL;
    indexBuffer.Normals = NULL;
    indexBuffer.Texture = NULL;

    printf("Testing Obj File Opening\n");

    ReadOBJFile("./Test/cube.obj", 0, &vertexbuffer, &indexBuffer);
    
    // Need to put a test here....
    // 05/01/2018

    free(vertexbuffer.Verticies);
    free(vertexbuffer.Normals);
    free(vertexbuffer.Texture);
    
    free(indexBuffer.Verticies);
    free(indexBuffer.Normals);
    free(indexBuffer.Texture);
    
    return sum;
}