// --------------------------------------------------
// BSP.c
// 
// Binary Space Partition
//
// Steven Novak
//
// 05/14/2018
//
// --------------------------------------------------

#include "BSP.h"

#include <stdio.h>

// -------------------------------------------------- Declarations

#define INFRONT 1
#define SPLIT 3
#define INBACK 2
#define INPLANE 4

BSPNode* createNode(BSPNode* parent);
int freeBSPTree(BSPNode* root);

int classifyPolygon(TriangleF4* split, TriangleF4* face);
int splitPolygon();
int isConvexSet(TriangleF4* vertexBuffer, unsigned int count);

// -------------------------------------------------- BSP

int createBSPTreeFromVertexBuffer(TriangleF4* polyBuffer, unsigned int count)
{
    // Are the remaining polygons a convex set?
    // - Yes -> isLeaf, null Pointers return
    // - No -> Create two new nodes

    // Find Center Of Poly Set
    // Create Node
    // Assign center to node

    // Count and mark front and back
    // Allocate buffers
    // Copy verticies
    // Clean up buffers
    // ---- Divide Poly it needed

    // Recurse Front
    // Recurse Back

    return 1;
}

int freeBSPTree(BSPNode* root)
{
    if(root->front != NULL)
        freeBSPTree(root->front);
    free(root->front);

    if(root->back != NULL)
        freeBSPTree(root->back);
    free(root->back);

    free(root->faces);

    return 1;
}

// -------------------------------------------------- Helper Functions

int classifyPolygon(TriangleF4* split, TriangleF4* face)
{
    int flags = 0;
    float dot, threshold = 0.0001;
    float4 W, norm;
    float4* P;

    // Calculate split normal
    normalF4(split, &norm);
    
    // Pick a point on the split
    P = &face->p0;
    for(int i=0; i<3; i++)
    {
        subtract_f4(P, &split->p0, &W);
        dotF4(&W, &norm, &dot);
        
        if(dot > threshold)
        {
            // Front
            flags |= INFRONT;
        }
        else if(dot < -threshold)
        {
            // Back
            flags |= INBACK;
        }
        else
        {
            // In Plane
            flags |= INPLANE;
        }
        P++;
    }

    switch (flags)
    {
        case 1:
            return INFRONT;
            break;

        case 2:
            return INBACK;
            break;
        case 3: 
            return SPLIT;
            break;
        case 4:
            return INPLANE;
            break;
        default:
            return flags & ~INPLANE;
        
    }


    return 0;
}

int splitPolygon()
{
    return 1;   
}

int isConvexSet(TriangleF4* polySet, unsigned int count)
{


    return 1;
}

