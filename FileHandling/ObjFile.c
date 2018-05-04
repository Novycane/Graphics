// --------------------------------------------------
// ObjFile.c  
// 
// ObjFile Routines and Data Structures
//
// Steven Novak
//
// 04/26/2018
//
// --------------------------------------------------

#include "ObjFile.h"

// -------------------------------------------------- Constants

#define MAX_BUFFER 50

enum state 
{
    NONE, VERTEX, NORMAL, TEXTURECOORDINATE
};

typedef enum state state_t;

// -------------------------------------------------- Declarations
void countVertices(FILE* file, unsigned int* numVerticies, unsigned int* numNormals, unsigned int* numTextureCoordinates, unsigned int* numIndicies);
void parseFloat3(char* line, float3* out);
void parseFloat2(char* line, float2* out);
void parseFace(char* line, TriangleIndexBuffers* out);

// -------------------------------------------------- Functions

int ReadOBJFile(const char* fileName, unsigned int FLAGS, VertexBuffers* vertexBuffers, TriangleIndexBuffers* indexBuffers)
{
    FILE *file;
    vertexBuffers->numVerticies = 0;
    vertexBuffers->numNormals = 0;
    vertexBuffers->numTextureCoordinates = 0;
    indexBuffers->numIndicies = 0; 

    char buffer[MAX_BUFFER];
     
    file = fopen(fileName, "r");
    
    if(file == NULL)
    {
        perror ("Couldn't open file:");
        return -1;
    }

    countVertices(file, &(vertexBuffers->numVerticies), &(vertexBuffers->numNormals), &(vertexBuffers->numTextureCoordinates), &(indexBuffers->numIndicies));
    
    vertexBuffers->Verticies = (float3*) malloc(sizeof(float3) * vertexBuffers->numVerticies);
    vertexBuffers->Normals = (float3*) malloc(sizeof(float3) * vertexBuffers->numNormals);
    vertexBuffers->Texture = (float2*) malloc(sizeof(float2) * vertexBuffers->numTextureCoordinates);

    indexBuffers->Verticies = (triIndex*) malloc(sizeof(triIndex) * indexBuffers->numIndicies);
    indexBuffers->Normals = (triIndex*) malloc(sizeof(triIndex) * indexBuffers->numIndicies);
    indexBuffers->Texture = (triIndex*) malloc(sizeof(triIndex) * indexBuffers->numIndicies);
    
    
    while(fgets(buffer, MAX_BUFFER, file) != NULL)
    {
        
        char* ch = buffer;
        while(*ch != ' ')
            ch++;
        *(ch++) = '\0';

        if(!strcmp(buffer, "v"))
        {
            parseFloat3(ch, vertexBuffers->Verticies);
            vertexBuffers->Verticies++;
        }        
        else if(!strcmp(buffer, "vn"))
        {
            parseFloat3(ch, vertexBuffers->Normals);
            vertexBuffers->Normals++;
        }
        else if(!strcmp(buffer, "vt"))
        {
            parseFloat2(ch, vertexBuffers->Texture);
            vertexBuffers->Texture++;
        }
        else if(!strcmp(buffer, "o"))
        {
            // Objects
        }
        else if(!strcmp(buffer, "f"))
        {
            parseFace(ch, indexBuffers);
        }
    }

    fclose(file);

    vertexBuffers->Verticies -= vertexBuffers->numVerticies;
    vertexBuffers->Normals -= vertexBuffers->numNormals;
    vertexBuffers->Texture -= vertexBuffers->numTextureCoordinates;

    indexBuffers->Verticies -= indexBuffers->numIndicies;
    indexBuffers->Normals -= indexBuffers->numIndicies;
    indexBuffers->Texture -= indexBuffers->numIndicies;
   
    return 0;
}

void countVertices(FILE* file, unsigned int* numVerticies, unsigned int* numNormals, unsigned int* numTextureCoordinates, unsigned int* numIndicies)
{
    char c = getc(file);
    int index = 0;
    char buffer[MAX_BUFFER];
    fpos_t beginning;
    fgetpos(file, &beginning);

    while(c != EOF)
    {
        switch(c)
        {
            case ' ':
                buffer[index++] = '\0';
                index = 0;
                if(strcmp(buffer, "v") == 0)
                    (*numVerticies)++;
                else if(strcmp(buffer, "vn") == 0)
                    (*numNormals)++;
                else if(strcmp(buffer, "vt") == 0)
                    (*numTextureCoordinates)++;
                else if(strcmp(buffer, "f") == 0)
                    (*numIndicies)++;
                break;
            case '/':
                buffer[index++] = '\0';
                index = 0;
                break;
            case '\n':
                buffer[index++] = '\0';
                index = 0;
                break;
            default:
                buffer[index++] = c;
                break;
        }
        c = getc(file);
    }
    fsetpos(file, &beginning);
}

void parseFloat3(char* line, float3* out)
{
    float* coordinate = (float*)out;
    int index = 0;
    char c[MAX_BUFFER];
    char* cp = line;
    
    while (*cp != '\0')
    {
        if(*cp == ' ' || *cp == '\n')
        {
            c[index] = '\0';
            index = 0;
            *coordinate = atof(c);
            coordinate++;
        }
        else
        {
            c[index++] = *cp;
        }
        cp++;
    }
}

void parseFloat2(char* line, float2* out)
{
    float* coordinate = (float*)out;
    int index = 0;
    char c[MAX_BUFFER];
    char* cp = line;
    
    while (*cp != '\0')
    {
        if(*cp == ' ' || *cp == '\n')
        {
            c[index] = '\0';
            index = 0;
            *coordinate = atof(c);
            coordinate++;
        }
        else
        {
            c[index++] = *cp;
        }

        cp++;
    }
}

void parseFace(char* line, TriangleIndexBuffers* out)
{
    int temp;
    int index = 0;
    char c[MAX_BUFFER];
    char* cp = line;
    int state = 0;

    while (*cp != '\0')
    {
        if(*cp == ' ' || *cp == '\n' || *cp == '/')
        {
            c[index] = '\0';
            index = 0;
            temp = atoi(c) - 1;
            
            switch (state)
            {
                case 0:
                    out->Verticies->p0 = temp;
                    break;
                case 1: 
                    out->Texture->p0 = temp;
                    break;
                case 2:
                    out->Normals->p0 = temp;
                    break;

                case 3:
                    out->Verticies->p1 = temp;
                    break;
                case 4: 
                    out->Texture->p1 = temp;
                    break;
                case 5:
                    out->Normals->p1 = temp;
                    break;

                case 6:
                    out->Verticies->p2 = temp;
                    break;
                case 7: 
                    out->Texture->p2 = temp;
                    break;
                case 8:
                    out->Normals->p2 = temp;
                    out->Normals++;
                    out->Texture++;
                    out->Verticies++;
                    break;
            }
            state++;
            if(state > 8)
                state = 0;
        }
        else
        {
            c[index++] = *cp;
        }

        cp++;
    }
}

int EchoFile(char* fileName)
{

    FILE *file;
    char c;

    file = fopen(fileName, "r");
    
    if(file == NULL)
    {
        printf("Couldn't open file: %s\n", fileName);
        perror ("The following error occurred");
        return -1;
    }

    c = getc(file);

    while(c != EOF)
    {
        printf("%c", c);
        c = getc(file);
    }

    return 0;
}