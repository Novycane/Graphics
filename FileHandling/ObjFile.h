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
    unsigned int numVerticies;
    unsigned int numNormals;
    unsigned int numTextureCoordinates;
    float3* Verticies;
    float3* Normals;
    float2* Texture;
} VertexBuffers;

typedef struct 
{
    unsigned int numIndicies;
    triIndex* Verticies;
    triIndex* Normals;
    triIndex* Texture;
} TriangleIndexBuffers;

// -------------------------------------------------- Functions

int ReadOBJFile(const char* fileName, unsigned int FLAGS, VertexBuffers* vertexBuffers, TriangleIndexBuffers* indexBuffers);

int EchoFile(char* fileName);

#endif