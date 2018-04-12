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

unsigned int CheckHardwareAvailability()
{
    unsigned int ecx;
    unsigned int leaf = 1;
    unsigned int subleaf = 0;
    
    asm volatile("cpuid"
                 : "=c" (ecx)
                 : "a" (leaf), "c" (subleaf));
    
    
    // Check for RDRAND Support
    if((ecx & 0x40000000) !=  0x40000000)
    {
        return 0;
    }
    return 1;
}

unsigned int GetVendorID(unsigned int* id)
{
    unsigned int leaf = 0;
    unsigned int subleaf = 0;
    
    asm volatile("cpuid"
                 : "=b" (id[0]),"=c" (id[2]), "=d" (id[1])
                 : "a" (leaf), "c" (subleaf));
    return 0;
}

void GetHardware64(long *number)
{
    unsigned char passed;
        
    asm volatile ("rdrand %0\t\n"
                  "setc %1\t\n"
                  : "=r" (*number), "=qm" (passed));
}