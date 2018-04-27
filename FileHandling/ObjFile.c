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

// -------------------------------------------------- Functions

int EchoFile(char* fileName)
{

    FILE *file;
    char c;

    file = fopen(fileName, "r");

    if(file == NULL)
    {
        printf("Couldn't open file: %s\n", fileName);
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