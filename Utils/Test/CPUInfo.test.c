
#include <stdio.h>
#include "../CPUInfo.h"

int TestProcessorID();
int TestCacheInfo();
int DecodeCacheBlock(unsigned char* byte);
int TestProcessorInfo();

int main(int argCount, char** args)
{
    printf("\n");
    TestProcessorID();
    TestCacheInfo();
    //TestProcessorInfo();
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
    printf("EAX: 0x%08x\n", info.EAX);
    printf("EBX: 0x%08d\n", info.EBX);
    printf("ECX: 0x%08x\n", info.ECX);
    printf("EDX: 0x%08x\n", info.EDX);
    printf("\n");
    
    printf("LSB: 0x%08x\n", DecodeCache(&info));
    printf("msb: 0x%08x\n", info.EAX & 0x80000000);
    printf("msb: 0x%08x\n", info.EBX & 0x80000000);
    printf("msb: 0x%08x\n", info.EBX & 0x80000000);
    printf("msb: 0x%08x\n", info.EBX & 0x80000000);

    unsigned char* byte = (unsigned char*)&(info.EAX);
    
    for(int i=0; i<16; i++)
        DecodeCacheBlock(&byte[i]);
    
    return 0;
}

int DecodeCacheBlock(unsigned char* byte)
{

    switch(*byte)
    {
        case 0x01:
            printf("Instruction TLB: 4 KByte pages, 4-way set associative, 32 entries\n");
            break;
        case 0x02:
            printf("Instruction TLB: 4 MByte pages, fully associative, 2 entries\n");
            break;
        case 0x03:
            printf("Data TLB: 4 KByte pages, 4-way set associative, 64 entries\n");
            break;
        case 0x04:
            printf("Data TLB: 4 MByte pages, 4-way set associative, 8 entries\n");
            break;
        case 0x05:
            printf("Data TLB1: 4 MByte pages, 4-way set associative, 32 entries\n");
            break;
        case 0x06:
            printf("1st-level instruction cache: 8 KBytes, 4-way set associative, 32 byte line size\n");
            break;
        case 0x08:
            printf("1st-level instruction cache: 16 KBytes, 4-way set associative, 32 byte line size\n");
            break;
        case 0x09:
            printf("1st-level instruction cache: 32KBytes, 4-way set associative, 64 byte line size\n");
            break;
        case 0x0A:
            printf("1st-level data cache: 8 KBytes, 2-way set associative, 32 byte line size\n");
            break;
        case 0x0B:
            printf("Instruction TLB: 4 MByte pages, 4-way set associative, 4 entries\n");
            break;
        case 0x0C:
            printf("1st-level data cache: 16 KBytes, 4-way set associative, 32 byte line size\n");
            break;
        case 0x0D:
            printf("1st-level data cache: 16 KBytes, 4-way set associative, 64 byte line size\n");
            break;
        case 0x0E:
            printf("1st-level data cache: 24 KBytes, 6-way set associative, 64 byte line size\n");
            break;
        case 0x1D:
            printf("2nd-level cache: 128 KBytes, 2-way set associative, 64 byte line size\n");
            break;
        case 0x21:
            printf("2nd-level cache: 256 KBytes, 8-way set associative, 64 byte line size\n");
            break;
        case 0x22:
            printf("3rd-level cache: 512 KBytes, 4-way set associative, 64 byte line size, 2 lines per sector\n");
            break;
        case 0x23:
            printf("3rd-level cache: 1 MBytes, 8-way set associative, 64 byte line size, 2 lines per sector\n");
            break;
        case 0x24:
            printf("2nd-level cache: 1 MBytes, 16-way set associative, 64 byte line size\n");
            break;
        case 0x25:
            printf("3rd-level cache: 2 MBytes, 8-way set associative, 64 byte line size, 2 lines per sector\n");
            break;
        case 0x29:
            printf("3rd-level cache: 4 MBytes, 8-way set associative, 64 byte line size, 2 lines per sector\n");
            break;
        case 0x2C:
            printf("1st-level data cache: 32 KBytes, 8-way set associative, 64 byte line size\n");
            break;
        case 0x30:
            printf("1st-level instruction cache: 32 KBytes, 8-way set associative, 64 byte line size\n");
            break;
        case 0x40:
            printf("No 2nd-level cache or, if processor contains a valid 2nd-level cache, no 3rd-level cache\n");
            break;
        case 0x41:
            printf("2nd-level cache: 128 KBytes, 4-way set associative, 32 byte line size\n");
            break;
        case 0x42:
            printf("2nd-level cache: 256 KBytes, 4-way set associative, 32 byte line size\n");
            break;
        case 0x43:
            printf("2nd-level cache: 512 KBytes, 4-way set associative, 32 byte line size\n");
            break;
        case 0x44:
            printf("2nd-level cache: 1 MByte, 4-way set associative, 32 byte line size\n");
            break;
        case 0x45:
            printf("2nd-level cache: 2 MByte, 4-way set associative, 32 byte line size\n");
            break;
        case 0x46:
            printf("3rd-level cache: 4 MByte, 4-way set associative, 64 byte line size\n");
            break;
        case 0x47:
            printf("3rd-level cache: 8 MByte, 8-way set associative, 64 byte line size\n");
            break;
        case 0x48:
            printf("2nd-level cache: 3MByte, 12-way set associative, 64 byte line size\n");
            break;
        case 0x49:
            printf("\n");
            break;
    }
    return 1;
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