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

void GetHardware64(long *number)
{
    unsigned char passed;
        
    asm volatile ("rdrand %0\t\n"
                  "setc %1\t\n"
                  : "=r" (*number), "=qm" (passed));
}