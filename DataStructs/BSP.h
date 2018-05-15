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

#include <stdlib.h>
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
    TriangleF4* faces;
    unsigned int numberOfFaces;
    BSPFlags flags;
};

// -------------------------------------------------- BSP

int createBSPTreeFromVertexBuffer(TriangleF4* vertexBuffer, unsigned int count);

#endif