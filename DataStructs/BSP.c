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
    float dot;
    float4 W, norm;
    float4* P;

    // Calculate split normal
    normalF4(split, &norm);

    // Pick a point on the split
    P = &face->p0;
    for(int i=0; i<3; i++)
    {
        // Calculate a vector from the target point to a point on the split
        //printf("x: %f, y: %f, z: %f w: %f---- ", P->x, P->y, P->z, P->w);
        subtract_f4(P, &split->p0, &W);
        //printf("x: %f, y: %f, z: %f  w: %f\n\n", W.x, W.y, W.z, W.w);
        //      Calculate the dot product
                dotF4(&W, &norm, &dot);
                printf("Dot: %f \n",dot); 
        //      if +
        //          in front
        //      if -
        //          behind
        //      if ~0
        //          in plane
        //      endif
        P++;
    }
    // for each point on the target plane
    //      Calculate a vector from the target point to a point on the split
    //      Calculate the dot product
    //      if +
    //          in front
    //      if -
    //          behind
    //      if ~0
    //          in plane
    //      endif
    //  end foreach
    // 
    return 1;
}

int splitPolygon()
{
    return 1;   
}

int isConvexSet(TriangleF4* polySet, unsigned int count)
{


    return 1;
}

