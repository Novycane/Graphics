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

// -------------------------------------------------- Declarations

BSPNode* createNode(BSPNode* parent);
int freeBSPTree(BSPNode* root);

int isInFront(float3* normal, TriangleF4* face);
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

    return 1;
}

// -------------------------------------------------- Helper Functions

int isInFront(float3* normal, TriangleF4* face)
{
    float dot;
    float4 U, V;
    subtract_f4(&face->p0, &face->p2, &U);
    subtract_f4(&face->p1, &face->p2, &U);
    dotF4(&U, &V, &dot);

    // Is poly inline?
    // in front?
    // behind?
    // intersecting
}

int isConvexSet(TriangleF4* polySet, unsigned int count)
{

    return 1;
}

