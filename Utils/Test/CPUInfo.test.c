
#include <stdio.h>
#include "../CPUInfo.h"

int main(int argCount, char** args)
{
    unsigned int out[3];
    for(int i=0; i<17; i++)
        out[i] = 0;
    printf("Testing CPUInfo\n\n");
    GetVendorID(out);
    
    char* letter = (char*)out;
    
    for(int i=0; i<12; i++)
        printf("%c", letter[i]);

    printf("\n");
    return 0;
}