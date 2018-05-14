// --------------------------------------------------
// BSP.h  
// 
// Binary Space Partition
//
// Steven Novak
//
// 05/14/2018
//
// --------------------------------------------------

#ifndef BSP_H
#define BSP_H

#include "../Math/Polygon.h"

// -------------------------------------------------- Structs
typedef enum 
{
    isSolid = 1,
    isLeaf = 2
} BSPFlags;

typedef struct  BSPNode  BSPNode;

struct BSPNode
{
    BSPNode* parent;
    BSPNode* front;
    BSPNode* back;
    TriangleF3* faces;
    unsigned int numberOfFaces;
    BSPFlags flags;
};

// -------------------------------------------------- BSP

int createBSPTreeFromVertexBuffer(float4* vertexBuffer, unsigned int count);

#endif