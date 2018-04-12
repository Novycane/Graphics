
#include <stdio.h>
#include "../CPUInfo.h"

int main(int argCount, char** args)
{
    char out[17];
    for(int i=0; i<17; i++)
        out[i] = 0;
    printf("Testing CPUInfo\n\n");

    GetVendorID(out);
    printf("Got Something\n");
    for(int i=0; i<17; i++)
        printf("%d: %0x\n", i, out[i]);

    printf("%s\n",out);
    return 0;
}