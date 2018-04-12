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

void CheckHardwareAvailability()
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
        return;
    }
    //std::cout << "Harware Random Number Generation Supported!\n";
}

void GetHardware64(long *number)
{
    unsigned char passed;
        
    asm volatile ("rdrand %0\t\n"
                  "setc %1\t\n"
                  : "=r" (*number), "=qm" (passed));
}