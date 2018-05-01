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
void parseFloat3(char* line, float3* out);
void parseFloat2(char* line, float2* out);

// -------------------------------------------------- Functions

int ReadOBJFile(char* fileName, unsigned int FLAGS, float3** verticies)
{
    FILE *file;
    fpos_t beginning;
    int index = 0;
    int numVerticies = 0, numNormals = 0, numTextureCoordinates = 0;
    char buffer[MAX_BUFFER];
    char c;

    file = fopen(fileName, "r");
    fgetpos(file, &beginning);
    
    if(file == NULL)
    {
        perror ("Couldn't open file:");
        return -1;
    }

    c = getc(file);

    while(c != EOF)
    {
        switch(c)
        {
            case ' ':
                buffer[index++] = '\0';
                //printf("%s\n", buffer);
                index = 0;

                if(strcmp(buffer, "v") == 0)
                    numVerticies++;
                else if(strcmp(buffer, "vn") == 0)
                    numNormals++;
                else if(strcmp(buffer, "vt") == 0)
                    numTextureCoordinates++;

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

    //printf("Verticies: %d\nNormals: %d\nTextureCoordinates: %d\n", numVerticies, numNormals, numTextureCoordinates);

    *verticies = (float3*) malloc(sizeof(float3) * numVerticies);

    fsetpos(file, &beginning);

    while(fgets(buffer, MAX_BUFFER, file) != NULL)
    {
        
        char* ch = buffer;
        while(*ch != ' ')
            ch++;
        *(ch++) = '\0';
        //printf("-%s-\n", buffer);
        if(!strcmp(buffer, "v"))
        {
            parseFloat3(ch, *verticies);
        }        
        else if(!strcmp(buffer, "vn"))
        {
            //parseFloat3(ch, *normals);
        }
        else if(!strcmp(buffer, "vt"))
        {
            //parseFloat2(ch, NULL);
        }
        else if(!strcmp(buffer, "o"))
        {
            // Objects
        }
        else if(!strcmp(buffer, "f"))
        {
            // Faces
        }
    }

    fclose(file);

    return 0;
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
    printf("%s", line);
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