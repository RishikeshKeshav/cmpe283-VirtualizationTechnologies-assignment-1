/*  
 *  cmpe283-1.c - Kernel module for CMPE283 assignment 1
 */
#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */
#include <asm/msr.h>

#define MAX_MSG 80

/*
 * Model specific registers (MSRs) by the module.
 * See SDM volume 4, section 2.1
 */
#define IA32_VMX_PINBASED_CTLS 0x481
#define IA32_VMX_PROCBASED_CTLS 0x482
#define IA32_VMX_PROCBASED_CTLS2 0x48B
#define IA32_VMX_EXIT_CTLS 0x483
#define IA32_VMX_ENTRY_CTLS 0x484
#define IA32_VMX_PROCBASED_CTLS3 0X92
/*
 * struct vmx_execution_controls
 *
 * Represents a single capability (bit number and description).
 * Used by show_vmx_capabilities to output VMX capabilities.
 */


#define VMX_PINBASED_BIT_COUNT 5
#define VMX_PRIMARY_PROCBASED_BIT_COUNT 22
#define VMX_SECONDARY_PROCBASED_BIT_COUNT 27
#define VMX_EXIT_BIT_COUNT 15
#define VMX_ENTRY_BIT_COUNT 13
#define VMX_TERTIARY_PROCBASED_BIT_COUNT 4


struct capability_info {
	uint8_t bit;
	const char *name;
};


/*
 * Pin-Based VM-Execution Controls
 */
struct capability_info pinbasedvmcontrols[VMX_PINBASED_BIT_COUNT] =
{
	{ 0, "External Interrupt Exiting" },
	{ 3, "NMI Exiting" },
	{ 5, "Virtual NMIs" },
	{ 6, "Activate VMX Preemption Timer" },
	{ 7, "Process Posted Interrupts" }
};

/*
 * Primary Processor-Based VM-Execution Controls
 */
struct capability_info primaryprocessorbasedvmcontrols[VMX_PRIMARY_PROCBASED_BIT_COUNT] =
{
	{ 2, "Interrupt Window Exiting" },
	{ 3, "Use TSC Offsetting" },
	{ 7, "HLT Exiting" },
	{ 9, "INVLPG Exiting" },
	{ 10, "MWAIT Exiting" },
	{ 11, "RDPMC Exiting" },
	{ 12, "RDTSC Exiting" },
	{ 15, "CR3 Load Exiting" },
	{ 16, "CR3 Store Exiting" },
	{ 17, "Activate Tertiary Controls" },
	{ 19, "CR8 Load Exiting" },
	{ 20, "CR8 Store Exiting" },
	{ 21, "Use TPR Shadow" },
	{ 22, "NMI Window Exiting" },
	{ 23, "MOV-DR Exiting" },
	{ 24, "Unconditional I/O Exiting" },
	{ 25, "Use I/O Bitmaps" },	
	{ 27, "Monitor Trap Flag" },
	{ 28, "Use MSR Bitmaps" },
	{ 29, "MONITOR Exiting" },
	{ 30, "PAUSE Exiting" },
	{ 31, "Activate Secondary Controls" }
};
/*
 * Secondary Processor-Based VM-Execution Controls
 */

struct capability_info secondaryprocessorbasedvmcontrols[VMX_SECONDARY_PROCBASED_BIT_COUNT] =
{
    { 0, "Virtualize APIC accesses" },	
    { 1, "Enable EPT" },	
    { 2, "Descriptor Table Exiting" },	
    { 3, "Enable RDTSCP" },	
    { 4, "Virtualize x2APIC Mode" },	
    { 5, "Enable VPID" },	
    { 6, "WBINVD Exiting" },	
    { 7, "Unrestricted Guest" },	
    { 8, "APIC-register Virtualization" },	
    { 9, "Virtual-interrupt Delivery" },	
    { 10, "PAUSE-loop Exiting" },	
    { 11, "RDRAND exiting" },	
    { 12, "Enable INVPCID" },
    { 13, "Enable VM Functions" },
    { 14, "VMCS Shadowing" },
    { 15, "Enable ENCLS Exiting" },
    { 16, "RDSEED Exiting" },
    { 17, "Enable PML" },
    { 18, "EPT-violation #VE" },
    { 19, "Conceal VMX from PT" },
    { 20, "Enable XSAVES/XRSTORS" },
    { 22, "Mode-based Execute Control for EPT" },
    { 23, "Sub-page Write Permissions for EPT" },
    { 24, "Intel PT Uses Guest Physical Addresses" },
    { 25, "Use TSC Scaling" },
    { 26, "Enable User Wait and Pause" },
    { 28, "Enable ENCLV Exiting" }
};
/*
 * Tertiary Processor-Based VM-Execution Controls
 */
struct capability_info tertiaryprocessorbasedvmcontrols[VMX_TERTIARY_PROCBASED_BIT_COUNT] =
{
    { 0, "LOADIWKEY Exiting" },	
    { 1, "Enable HLAT" },
    { 2, "EPT Paging-write Control" },
    { 3, "Guest-paging Verification" }
};
/*
 * Exit Controls
 */
struct capability_info exitcontrols[VMX_EXIT_BIT_COUNT] =
{
    { 2, "Save Debug Controls" },	
    { 9, "Host Address-Space Size" },	
    { 12, "Load IA32_PERF_GLOBAL_CTRL" },	
    { 15, "Acknowledge Interrupt On Exit" },	
    { 18, "Save IA32_PAT" },	
    { 19, "Load IA32_PAT" },	
    { 20, "Save IA32_EFER" },	
    { 21, "Load IA32_EFER" },	
    { 22, "Save VMXpreemption Timer Value" },	
    { 23, "Clear IA32_BNDCFGS" },	
    { 24, "Conceal VMX from PT" },	
    { 25, "Clear IA32_RTIT_CTL" },
    { 26, "Clear IA32_LBR_CTL" },    
    { 28, "Load CET state" },	
    { 29, "Load PKRS" },
};
/*
 * Entry Controls
 */

struct capability_info entrycontrols[VMX_ENTRY_BIT_COUNT] =
{
    { 2, "Load Debug Controls" },	
    { 9, "IA-32e Mode Guest" },	
    { 10, "Entry to SMM" },	
    { 11, "Deactivate Dual Monitor Treatment" },	
    { 13, "Load IA32_PERF_GLOBAL_CTRL" },	
    { 14, "Load IA32_PAT" },	
    { 15, "Load IA32_EFER" },	
    { 16, "Load IA32_BNDCFGS" },	
    { 17, "Conceal VMX from PT" },	
    { 18, "Load IA32_RTIT_CTL" },	
    { 20, "Load CET State" },	
    { 21, "Load Guest IA32_LBR_CTL" },
    { 22, "Load PKRS" }  
};

/*
 *show_vmx_capabilities
 *
 * Shows capabilities present in 'capability' using the corresponding MSR values
 * provided in 'low' and 'high'.
 *
 * Parameters:
 *  caps: vmx_execution_controls structure for this features
 *  size: number of entries in 'capability'
 *  low: low 32 bits of capability MSR value describing this features
 *  high: high 32 bits of capability MSR value describing this features
 */

void
report_capability(struct capability_info *cap, uint8_t length, uint32_t low,
    uint32_t high)
{
        uint8_t count;
        struct capability_info *c;
        char message[MAX_MSG];

        memset(message, 0, sizeof(message));
        count = 0;
        while (count < length) {
 c = &cap[count];
                snprintf(message, 79, "  %s: Can set=%s, Can clear=%s\n",
                    c->name,
                    (high & (1 << c->bit)) ? "Yes" : "No",
                    !(low & (1 << c->bit)) ? "Yes" : "No");
                printk(message);
                count++;
        }
}

/*
 * vmx_execution_features
 *
 * Finds and prints VMX capabilities of this host's CPU.
 */

void
detect_vmx_features(void)
{
	uint32_t low, high;

	/* Pinbased controls */
	rdmsr(IA32_VMX_PINBASED_CTLS, low, high);
	pr_info("Pinbased Controls MSR: 0x%llx\n",
		(uint64_t)(low | (uint64_t)high << 32));
	report_capability(pinbasedvmcontrols, VMX_PINBASED_BIT_COUNT, low, high);
	
	/* Procbased controls */
	rdmsr(IA32_VMX_PROCBASED_CTLS, low, high);
	pr_info("Processor based Controls MSR: 0x%llx\n",
		(uint64_t)(low | (uint64_t)high << 32));
	report_capability(primaryprocessorbasedvmcontrols, VMX_PRIMARY_PROCBASED_BIT_COUNT, low, high);

	
	/* Procbased secondary controls */
	rdmsr(IA32_VMX_PROCBASED_CTLS2, low, high);
	pr_info("Processor based Secondary Controls MSR: 0x%llx\n",
		(uint64_t)(low | (uint64_t)high << 32));
	report_capability(secondaryprocessorbasedvmcontrols, VMX_SECONDARY_PROCBASED_BIT_COUNT, low, high);

     /* Procbased Teriary controls */
      rdmsr(IA32_VMX_PROCBASED_CTLS3, low, high);
	pr_info("Processor based Tertiary Controls MSR: 0x%llx\n",
		(uint64_t)(low | (uint64_t)high << 32));
	report_capability(tertiaryprocessorbasedvmcontrols, VMX_TERTIARY_PROCBASED_BIT_COUNT, low, high);


	
	/* Exit controls */
	rdmsr(IA32_VMX_EXIT_CTLS, low, high);
	pr_info("Exit Controls MSR: 0x%llx\n",
		(uint64_t)(low | (uint64_t)high << 32));
	report_capability(exitcontrols, VMX_EXIT_BIT_COUNT, low, high);

	
	/* Entry controls */
	rdmsr(IA32_VMX_ENTRY_CTLS, low, high);
	pr_info("Entry Controls MSR: 0x%llx\n",
		(uint64_t)(low | (uint64_t)high << 32));
	report_capability(entrycontrols, VMX_ENTRY_BIT_COUNT, low, high);


}

/*
 * init_module
 *
 * Module entry point
 *
 * Return Values:
 *  Always 0
 */

int
init_module(void)
{
	printk(KERN_INFO "CMPE 283 Assignment 1 Module Start\n");

	detect_vmx_features();

	/* 
	 * A non 0 return means init_module failed; module can't be loaded.  
	 */
	return 0;
}

/*
 * cleanup_module
 *
 * Function called on module unload
 */
void
cleanup_module(void)
{
	printk(KERN_INFO "CMPE 283 Assignment 1 Module Exits\n");
}
MODULE_LICENSE("GPL");
