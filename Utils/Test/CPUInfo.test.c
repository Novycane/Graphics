
#include <stdio.h>
#include "../CPUInfo.h"

int main(int argCount, char** args)
{
    printf("Testing CPUInfo\n\n");

    printf("%d \n", CheckHardwareAvailability());
    return 0;
}