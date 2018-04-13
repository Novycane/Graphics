
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
    info.EBX = 0x00000000;
    GetCacheInfo(&info);

    printf("Cache Info\n");
    printf("EAX: 0x%08x\n", info.EAX);
    printf("EBX: 0x%08x\n", info.EBX);
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
    {
        DecodeCacheBlock(&byte[i]);
    }
    
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
            printf("3rd-level cache: 4MB, 16-way set associative, 64-byte line size (Intel Xeon processor MP, Family 0FH, Model 06H); 2nd-level cache: 4 MByte, 16-way set associative, 64 byte line size\n");
            break;
        case 0x4A:
            printf("3rd-level cache: 6MByte, 12-way set associative, 64 byte line size\n");
            break;
        case 0x4B:
            printf("3rd-level cache: 8MByte, 16-way set associative, 64 byte line size\n");
            break;
        case 0x4C:
            printf("3rd-level cache: 12MByte, 12-way set associative, 64 byte line size\n");
            break;
        case 0x4D:
            printf("3rd-level cache: 16MByte, 16-way set associative, 64 byte line size\n");
            break;
        case 0x4E:
            printf("2nd-level cache: 6MByte, 24-way set associative, 64 byte line size\n");
            break;
        case 0x4F:
            printf("Instruction TLB: 4 KByte pages, 32 entries\n");
            break;
        case 0x50:
            printf("Instruction TLB: 4 KByte and 2-MByte or 4-MByte pages, 64 entries\n");
            break;
        case 0x51:
            printf("Instruction TLB: 4 KByte and 2-MByte or 4-MByte pages, 128 entries\n");
            break;
        case 0x52:
            printf("Instruction TLB: 4 KByte and 2-MByte or 4-MByte pages, 256 entries\n");
            break;
        case 0x55:
            printf("Instruction TLB: 2-MByte or 4-MByte pages, fully associative, 7 entries\n");
            break;
        case 0x56:
            printf("Data TLB0: 4 MByte pages, 4-way set associative, 16 entries\n");
            break;
        case 0x57:
            printf("Data TLB0: 4 KByte pages, 4-way associative, 16 entries\n");
            break;
        case 0x59:
            printf("Data TLB0: 4 KByte pages, fully associative, 16 entries\n");
            break;
        case 0x5A:
            printf("Data TLB0: 2 MByte or 4 MByte pages, 4-way set associative, 32 entries\n");
            break;
        case 0x5B:
            printf("Data TLB: 4 KByte and 4 MByte pages, 64 entries\n");
            break;
        case 0x5C:
            printf("Data TLB: 4 KByte and 4 MByte pages,128 entries\n");
            break;
        case 0x5D:
            printf("Data TLB: 4 KByte and 4 MByte pages,256 entries\n");
            break;
        case 0x60:
            printf("1st-level data cache: 16 KByte, 8-way set associative, 64 byte line size\n");
            break;
        case 0x61:
            printf("Instruction TLB: 4 KByte pages, fully associative, 48 entries\n");
            break;
        case 0x63:
            printf("Data TLB: 2 MByte or 4 MByte pages, 4-way set associative, 32 entries and a separate array with 1 GByte pages, 4-way set associative, 4 entries\n");
            break;
        case 0x64:
            printf("Data TLB: 4 KByte pages, 4-way set associative, 512 entries\n");
            break;
        case 0x66:
            printf("1st-level data cache: 8 KByte, 4-way set associative, 64 byte line size\n");
            break;
        case 0x67:
            printf("1st-level data cache: 16 KByte, 4-way set associative, 64 byte line size\n");
            break;
        case 0x68:
            printf("1st-level data cache: 32 KByte, 4-way set associative, 64 byte line size\n");
            break;
        case 0x6A:
            printf("uTLB: 4 KByte pages, 8-way set associative, 64 entries\n");
            break;
        case 0x6B:
            printf("DTLB: 4 KByte pages, 8-way set associative, 256 entries\n");
            break;
        case 0x6C:
            printf("DTLB: 2M/4M pages, 8-way set associative, 128 entries\n");
            break;
        case 0x6D:
            printf("DTLB: 1 GByte pages, fully associative, 16 entries\n");
            break;
        case 0x70:
            printf("Trace cache: 12 K-μop, 8-way set associative\n");
            break;
        case 0x71:
            printf("Trace cache: 16 K-μop, 8-way set associative\n");
            break;
        case 0x72:
            printf("Trace cache: 32 K-μop, 8-way set associative\n");
            break;
        case 0x76:
            printf("Instruction TLB: 2M/4M pages, fully associative, 8 entries\n");
            break;
        case 0x78:
            printf("2nd-level cache: 1 MByte, 4-way set associative, 64byte line size\n");
            break;
        case 0x79:
            printf("2nd-level cache: 128 KByte, 8-way set associative, 64 byte line size, 2 lines per sector\n");
            break;
        case 0x7A:
            printf("2nd-level cache: 256 KByte, 8-way set associative, 64 byte line size, 2 lines per sector\n");
            break;
        case 0x7B:
            printf("2nd-level cache: 512 KByte, 8-way set associative, 64 byte line size, 2 lines per sector\n");
            break;
        case 0x7C:
            printf("2nd-level cache: 1 MByte, 8-way set associative, 64 byte line size, 2 lines per sector\n");
            break;
        case 0x7D:
            printf("2nd-level cache: 2 MByte, 8-way set associative, 64byte line size\n");
            break;
        case 0x7F:
            printf("2nd-level cache: 512 KByte, 2-way set associative, 64-byte line size\n");
            break;
        case 0x80:
            printf("2nd-level cache: 512 KByte, 8-way set associative, 64-byte line size\n");
            break;
        case 0x82:
            printf("2nd-level cache: 256 KByte, 8-way set associative, 32 byte line size\n");
            break;
        case 0x83:
            printf("2nd-level cache: 512 KByte, 8-way set associative, 32 byte line size\n");
            break;
        case 0x84:
            printf("2nd-level cache: 1 MByte, 8-way set associative, 32 byte line size\n");
            break;
        case 0x85:
            printf("2nd-level cache: 2 MByte, 8-way set associative, 32 byte line size\n");
            break;
        case 0x86:
            printf("2nd-level cache: 512 KByte, 4-way set associative, 64 byte line size\n");
            break;
        case 0x87:
            printf("2nd-level cache: 1 MByte, 8-way set associative, 64 byte line size\n");
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