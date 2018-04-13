
#include <stdio.h>
#include "../CPUInfo.h"

int TestProcessorID();
int TestCacheInfo();
int TestProcessorInfo();

int main(int argCount, char** args)
{
    printf("\n");
    TestProcessorID();
    TestCacheInfo();
    TestProcessorInfo();
    return 0;
}

int TestProcessorID()
{
    CPUInfoData info;
    GetVendorInfo(&info);
    printf("Max EAX for CPID: %u\n", GetMaxEAXLeaf(&info));
    printf("Processor type: ");
    char* letter = (char*)&(info.EBX);
    for(int i=0; i<4; i++)
        printf("%c", letter[i]);
    letter = (char*)&(info.EDX);
    for(int i=0; i<4; i++)
        printf("%c", letter[i]);
        letter = (char*)&(info.ECX);
    for(int i=0; i<4; i++)  
        printf("%c", letter[i]);
    printf("\n\n");

    return 0;
}

int TestCacheInfo()
{
    CPUInfoData info;
    GetCacheInfo(&info);

    printf("Cache Info\n");
    printf("0x%0xd\n", info.EAX);
    printf("0x%0xd\n", info.EBX);
    printf("0x%0xd\n", info.ECX);
    printf("0x%0xd\n", info.EDX);
    printf("\n");
    
    return 0;
}

int TestProcessorInfo()
{
    CPUInfoData info;
    GetProcessorInfo(&info);

    printf("Processor Info\n");
    printf("0x%0xd\n", info.EAX);
    printf("0x%0xd\n", info.EBX);
    printf("0x%0xd\n", info.ECX);
    printf("0x%0xd\n", info.EDX);
    printf("\n");

    return 0;
}