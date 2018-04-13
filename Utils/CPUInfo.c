// --------------------------------------------------
// CPUInfo.c  
// 
// Routines to determine CPU Capabilities
//
// Steven Novak
//
// 04/12/2018
//
// --------------------------------------------------

#include "CPUInfo.h"

// -------------------------------------------------------
// ------------------------- Vendor Info Functions
int GetVendorInfo(CPUInfoData* cacheData)
{
    unsigned int leaf = 0;
    unsigned int subleaf = 0;

    asm volatile("cpuid"
                : "=a" (cacheData->EAX), "=b" (cacheData->EBX), "=c" (cacheData->ECX), "=d" (cacheData->EDX)
                : "a" (leaf), "c" (subleaf)
    );

    return 0;
}

unsigned int GetMaxEAXLeaf(CPUInfoData* cacheData)
{
    return cacheData->EAX;
}

// -------------------------------------------------------
// ------------------------- Processor Info Functions
int GetProcessorInfo(CPUInfoData* cacheData)
{
    unsigned int leaf = 1;
    unsigned int subleaf = 0;

    asm volatile("cpuid"
                : "=a" (cacheData->EAX), "=b" (cacheData->EBX), "=c" (cacheData->ECX), "=d" (cacheData->EDX)
                : "a" (leaf), "c" (subleaf)
    );

    return 0;
}

// -------------------------------------------------------
// ------------------------- Cache Info Functions
int GetCacheInfo(CPUInfoData* cacheData)
{
    unsigned int leaf = 2;
    unsigned int subleaf = 0;

    asm volatile("cpuid"
                : "=a" (cacheData->EAX), "=b" (cacheData->EBX), "=c" (cacheData->ECX), "=d" (cacheData->EDX)
                : "a" (leaf), "c" (subleaf)
    );

    return 0;
}

int DecodeCache(CPUInfoData* cacheData)
{
    return cacheData->EAX & 0x00000001;
}