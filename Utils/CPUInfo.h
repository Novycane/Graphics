// --------------------------------------------------
// CPUInfo.h  
// 
// Routines to determine CPU Capabilities
//
// Steven Novak
//
// 04/12/2018
//
// --------------------------------------------------

#ifndef CPUINFO_H
#define CPUINFO_H

// --------------------------------------------------
// ------------------------- Structs

typedef struct 
{
    unsigned int EAX;
    unsigned int EBX;
    unsigned int ECX;
    unsigned int EDX;
} CPUInfoData;

// --------------------------------------------------
// ------------------------- Functions


// ------------------------- Vendor Info Functions
int GetVendorInfo(CPUInfoData* cacheData);
unsigned int GetMaxEAXLeaf(CPUInfoData* cacheData);

// ------------------------- Processor Info Functions
int GetProcessorInfo(CPUInfoData* cacheData);
int DecodeProcessorVersionInfo(CPUInfoData* cacheData);


// ------------------------- Cache Info Functions
int GetCacheInfo(CPUInfoData* cacheData);

#endif