// --------------------------------------------------
// ObjFile.h  
// 
// ObjFile Routines and Data Structures
//
// Steven Novak
//
// 04/26/2018
//
// --------------------------------------------------

#ifndef OBJFILE_H
#define OBJFILE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../Math/Primatives.h"


// -------------------------------------------------- Structs

typedef struct 
{
    float3* Verticies;
    float3* Normals;
    float2* Texture;
} VertexBuffers;

// -------------------------------------------------- Functions

int ReadOBJFile(char* fileName, unsigned int FLAGS, VertexBuffers* buffers);

int EchoFile(char* fileName);

#endif