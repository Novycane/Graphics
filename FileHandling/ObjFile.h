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


// -------------------------------------------------- Functions

int ReadOBJFile(char* fileName, unsigned int FLAGS, float3** verticies);

int EchoFile(char* fileName);

#endif