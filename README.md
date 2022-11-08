# cmpe283-VirtualizationTechnologies-assignment-1
Team Members: 1)Pramatha Nadig
 2)Rishikesh Andhare
Effort Distribution
Pramatha Nadig
•	Created the VM on Google Cloud Platform with the configurations as per the requirement in Assignment-1
•	MSR COMPLETED-
o	IA32_VMX_PINBASED_CTLS  0x481
o	IA32_VMX_ENTRY_CTLS   0x484
o	IA32_VMX_EXIT_CTLS     0x483

Rishikesh Andhare
•	Created the VM on Google Cloud Platform with the configurations as per the requirement in Assignment-1
•	MSR COMPLETED- 
o	IA32_VMX_PROCBASED_CTLS
o	IA32_VMX_PROCBASED_CTLS2
o	IA32_VMX_PROCBASED_CTLS3
TOTAL OUTPUT IS IN THE output.tx file in the Rpository

Steps for completing the assignment:
i.	Create a VM in Google Cloud Platform under the compute engine section with nested virtualization enabled.
ii.	Selected “Intel Haswell” as CPU platform with architecture x86/64.
iii.	Run the VM using SSH
iv.	In the VM terminal we have created a cmpe283.c file which is a source file ,containing the code for Reading Capabilities of MSRs.
v.	Created a Makefile 
vi.	 For installing make tool and gcc compiler on VM
a.	Run sudo apt install gcc make
vii.	There are 6 MSR’s in the assignment for which we have to detect the capabilities on our GCP VM.
a) IA32_VMX_PINBASED_CTLS 0x481
b) IA32_VMX_PROCBASED_CTLS 0x482
c) IA32_VMX_PROCBASED_CTLS2 0x48B
d) IA32_VMX_EXIT_CTLS 0x483
e) IA32_VMX_ENTRY_CTLS 0x484
f) IA32_VMX_PROCBASED_CTLS3 0X92
viii.	Run under the same directory with MakeFile and cmpe283.c file in terminal using the command
make
ix.	Files generated are:-
 
x.	Run the command sudo insmod cmpe283.ko to run the source file
xi.	Run sudo dmesg to detect the capabilities on the VM for the MSR’
xii.	Upon running these command we will be able to see the message outputs for the MSR’s pin-based, primary, secondary and tertiary procbased, exit and entry  control on terminal.
Snapshot :
IA32_VMX_PINBASED_CTLS 0x481  (output )

 [19724.142906] CMPE 283 Assignment 1 Module Start
[19724.147498] Pinbased Controls MSR: 0x3f00000016
[19724.152140]   External Interrupt Exiting: Can set=Yes, Can clear=Yes
[19724.158600]   NMI Exiting: Can set=Yes, Can clear=Yes
[19724.163759]   Virtual NMIs: Can set=Yes, Can clear=Yes
[19724.169439]   Activate VMX Preemption Timer: Can set=No, Can clear=Yes
[19724.176073]   Process Posted Interrupts: Can set=No, Can clear=Yes

IA32_VMX_PROCBASED_CTLS 0x482(output )
 [19724.182362] Processor based Controls MSR: 0xf7b9fffe0401e172
[19724.188241]   Interrupt Window Exiting: Can set=Yes, Can clear=Yes
[19724.194527]   Use TSC Offsetting: Can set=Yes, Can clear=Yes
[19724.200293]   HLT Exiting: Can set=Yes, Can clear=Yes
[19724.205546]   INVLPG Exiting: Can set=Yes, Can clear=Yes
[19724.210965]   MWAIT Exiting: Can set=Yes, Can clear=Yes
[19724.216299]   RDPMC Exiting: Can set=Yes, Can clear=Yes
[19724.221641]   RDTSC Exiting: Can set=Yes, Can clear=Yes
[19724.226973]   CR3 Load Exiting: Can set=Yes, Can clear=No
[19724.232483]   CR3 Store Exiting: Can set=Yes, Can clear=No
[19724.238075]   Activate Tertiary Controls: Can set=No, Can clear=Yes
[19724.244448]   CR8 Load Exiting: Can set=Yes, Can clear=Yes
[19724.250039]   CR8 Store Exiting: Can set=Yes, Can clear=Yes
[19724.255719]   Use TPR Shadow: Can set=Yes, Can clear=Yes
[19724.261136]   NMI Window Exiting: Can set=No, Can clear=Yes
[19724.266900]   MOV-DR Exiting: Can set=Yes, Can clear=Yes
[19724.272320]   Unconditional I/O Exiting: Can set=Yes, Can clear=Yes
[19724.278694]   Use I/O Bitmaps: Can set=Yes, Can clear=Yes
[19724.284199]   Monitor Trap Flag: Can set=No, Can clear=Yes
[19724.289792]   Use MSR Bitmaps: Can set=Yes, Can clear=Yes
[19724.295297]   MONITOR Exiting: Can set=Yes, Can clear=Yes
[19724.300801]   PAUSE Exiting: Can set=Yes, Can clear=Yes
[19724.306134]   Activate Secondary Controls: Can set=Yes, Can clear=Yes
 
 
IA32_VMX_PROCBASED_CTLS2 0x48B(output )
 
[19724.312683] Processor based Secondary Controls MSR: 0x51ff00000000
[19724.318968]   Virtualize APIC accesses: Can set=Yes, Can clear=Yes
[19724.325261]   Enable EPT: Can set=Yes, Can clear=Yes
[19724.330338]   Descriptor Table Exiting: Can set=Yes, Can clear=Yes
[19724.336641]   Enable RDTSCP: Can set=Yes, Can clear=Yes
[19724.341977]   Virtualize x2APIC Mode: Can set=Yes, Can clear=Yes
[19724.348091]   Enable VPID: Can set=Yes, Can clear=Yes
[19724.353254]   WBINVD Exiting: Can set=Yes, Can clear=Yes
[19724.358671]   Unrestricted Guest: Can set=Yes, Can clear=Yes
[19724.364436]   APIC-register Virtualization: Can set=Yes, Can clear=Yes
[19724.371075]   Virtual-interrupt Delivery: Can set=No, Can clear=Yes
[19724.377449]   PAUSE-loop Exiting: Can set=No, Can clear=Yes
[19724.383128]   RDRAND exiting: Can set=No, Can clear=Yes
[19724.388460]   Enable INVPCID: Can set=Yes, Can clear=Yes
[19724.393877]   Enable VM Functions: Can set=No, Can clear=Yes
[19724.399651]   VMCS Shadowing: Can set=Yes, Can clear=Yes
[19724.405075]   Enable ENCLS Exiting: Can set=No, Can clear=Yes
[19724.410925]   RDSEED Exiting: Can set=No, Can clear=Yes
[19724.416256]   Enable PML: Can set=No, Can clear=Yes
[19724.421239]   EPT-violation #VE: Can set=No, Can clear=Yes
[19724.426832]   Conceal VMX from PT: Can set=No, Can clear=Yes
[19724.432604]   Enable XSAVES/XRSTORS: Can set=No, Can clear=Yes
[19724.438542]   Mode-based Execute Control for EPT: Can set=No, Can clear=Yes
[19724.445613]   Sub-page Write Permissions for EPT: Can set=No, Can clear=Yes
[19724.452680]   Intel PT Uses Guest Physical Addresses: Can set=No, Can clear=Yes
[19724.460096]   Use TSC Scaling: Can set=No, Can clear=Yes
[19724.465514]   Enable User Wait and Pause: Can set=No, Can clear=Yes
[19724.471885]   Enable ENCLV Exiting: Can set=No, Can clear=Yes
 
IA32_VMX_EXIT_CTLS 0x483(output )
 
[19724.506393] Exit Controls MSR: 0x3fefff00036dff
[19724.511028]   Save Debug Controls: Can set=Yes, Can clear=No
[19724.516795]   Host Address-Space Size: Can set=Yes, Can clear=Yes
[19724.522994]   Load IA32_PERF_GLOBAL_CTRL: Can set=No, Can clear=Yes
[19724.529366]   Acknowledge Interrupt On Exit: Can set=Yes, Can clear=Yes
[19724.536087]   Save IA32_PAT: Can set=Yes, Can clear=Yes
[19724.541419]   Load IA32_PAT: Can set=Yes, Can clear=Yes
[19724.546748]   Save IA32_EFER: Can set=Yes, Can clear=Yes
[19724.552167]   Load IA32_EFER: Can set=Yes, Can clear=Yes
[19724.557587]   Save VMXpreemption Timer Value: Can set=No, Can clear=Yes
[19724.564309]   Clear IA32_BNDCFGS: Can set=No, Can clear=Yes
[19724.569988]   Conceal VMX from PT: Can set=No, Can clear=Yes
[19724.575755]   Clear IA32_RTIT_CTL: Can set=No, Can clear=Yes
[19724.581519]   Clear IA32_LBR_CTL: Can set=No, Can clear=Yes
[19724.587211]   Load CET state: Can set=No, Can clear=Yes
[19724.592547]   Load PKRS: Can set=No, Can clear=Yes

IA32_VMX_ENTRY_CTLS 0x484(output )
 
 [19724.597454] Entry Controls MSR: 0xd3ff000011ff
[19724.602090]   Load Debug Controls: Can set=Yes, Can clear=No
[19724.607857]   IA-32e Mode Guest: Can set=Yes, Can clear=Yes
[19724.613538]   Entry to SMM: Can set=No, Can clear=Yes
[19724.618696]   Deactivate Dual Monitor Treatment: Can set=No, Can clear=Yes
[19724.625679]   Load IA32_PERF_GLOBAL_CTRL: Can set=No, Can clear=Yes
[19724.632053]   Load IA32_PAT: Can set=Yes, Can clear=Yes
[19724.637471]   Load IA32_EFER: Can set=Yes, Can clear=Yes
[19724.642889]   Load IA32_BNDCFGS: Can set=No, Can clear=Yes
[19724.648479]   Conceal VMX from PT: Can set=No, Can clear=Yes
[19724.654246]   Load IA32_RTIT_CTL: Can set=No, Can clear=Yes
[19724.659926]   Load CET State: Can set=No, Can clear=Yes
[19724.665346]   Load Guest IA32_LBR_CTL: Can set=No, Can clear=Yes
[19724.671458]   Load PKRS: Can set=No, Can clear=Yes
 
IA32_VMX_PROCBASED_CTLS3 0X92(output )
 
[19724.477911] Processor based Tertiary Controls MSR: 0x0
[19724.483242]   LOADIWKEY Exiting: Can set=No, Can clear=Yes
[19724.488832]   Enable HLAT: Can set=No, Can clear=Yes
[19724.493904]   EPT Paging-write Control: Can set=No, Can clear=Yes
[19724.500105]   Guest-paging Verification: Can set=No, Can clear=Yes




Overall Output :-
 
 [19724.142906] CMPE 283 Assignment 1 Module Start
[19724.147498] Pinbased Controls MSR: 0x3f00000016
[19724.152140]   External Interrupt Exiting: Can set=Yes, Can clear=Yes
[19724.158600]   NMI Exiting: Can set=Yes, Can clear=Yes
[19724.163759]   Virtual NMIs: Can set=Yes, Can clear=Yes
[19724.169439]   Activate VMX Preemption Timer: Can set=No, Can clear=Yes
[19724.176073]   Process Posted Interrupts: Can set=No, Can clear=Yes
[19724.182362] Processor based Controls MSR: 0xf7b9fffe0401e172
[19724.188241]   Interrupt Window Exiting: Can set=Yes, Can clear=Yes
[19724.194527]   Use TSC Offsetting: Can set=Yes, Can clear=Yes
[19724.200293]   HLT Exiting: Can set=Yes, Can clear=Yes
[19724.205546]   INVLPG Exiting: Can set=Yes, Can clear=Yes
[19724.210965]   MWAIT Exiting: Can set=Yes, Can clear=Yes
[19724.216299]   RDPMC Exiting: Can set=Yes, Can clear=Yes
[19724.221641]   RDTSC Exiting: Can set=Yes, Can clear=Yes
[19724.226973]   CR3 Load Exiting: Can set=Yes, Can clear=No
[19724.232483]   CR3 Store Exiting: Can set=Yes, Can clear=No
[19724.238075]   Activate Tertiary Controls: Can set=No, Can clear=Yes
[19724.244448]   CR8 Load Exiting: Can set=Yes, Can clear=Yes
[19724.250039]   CR8 Store Exiting: Can set=Yes, Can clear=Yes
[19724.255719]   Use TPR Shadow: Can set=Yes, Can clear=Yes
[19724.261136]   NMI Window Exiting: Can set=No, Can clear=Yes
[19724.266900]   MOV-DR Exiting: Can set=Yes, Can clear=Yes
[19724.272320]   Unconditional I/O Exiting: Can set=Yes, Can clear=Yes
[19724.278694]   Use I/O Bitmaps: Can set=Yes, Can clear=Yes
[19724.284199]   Monitor Trap Flag: Can set=No, Can clear=Yes
[19724.289792]   Use MSR Bitmaps: Can set=Yes, Can clear=Yes
[19724.295297]   MONITOR Exiting: Can set=Yes, Can clear=Yes
[19724.300801]   PAUSE Exiting: Can set=Yes, Can clear=Yes
[19724.306134]   Activate Secondary Controls: Can set=Yes, Can clear=Yes
[19724.312683] Processor based Secondary Controls MSR: 0x51ff00000000
[19724.318968]   Virtualize APIC accesses: Can set=Yes, Can clear=Yes
[19724.325261]   Enable EPT: Can set=Yes, Can clear=Yes
[19724.330338]   Descriptor Table Exiting: Can set=Yes, Can clear=Yes
[19724.336641]   Enable RDTSCP: Can set=Yes, Can clear=Yes
[19724.341977]   Virtualize x2APIC Mode: Can set=Yes, Can clear=Yes
[19724.348091]   Enable VPID: Can set=Yes, Can clear=Yes
[19724.353254]   WBINVD Exiting: Can set=Yes, Can clear=Yes
[19724.358671]   Unrestricted Guest: Can set=Yes, Can clear=Yes
[19724.364436]   APIC-register Virtualization: Can set=Yes, Can clear=Yes
[19724.371075]   Virtual-interrupt Delivery: Can set=No, Can clear=Yes
[19724.377449]   PAUSE-loop Exiting: Can set=No, Can clear=Yes
[19724.383128]   RDRAND exiting: Can set=No, Can clear=Yes
[19724.388460]   Enable INVPCID: Can set=Yes, Can clear=Yes
[19724.393877]   Enable VM Functions: Can set=No, Can clear=Yes
[19724.399651]   VMCS Shadowing: Can set=Yes, Can clear=Yes
[19724.405075]   Enable ENCLS Exiting: Can set=No, Can clear=Yes
[19724.410925]   RDSEED Exiting: Can set=No, Can clear=Yes
[19724.416256]   Enable PML: Can set=No, Can clear=Yes
[19724.421239]   EPT-violation #VE: Can set=No, Can clear=Yes
[19724.426832]   Conceal VMX from PT: Can set=No, Can clear=Yes
[19724.432604]   Enable XSAVES/XRSTORS: Can set=No, Can clear=Yes
[19724.438542]   Mode-based Execute Control for EPT: Can set=No, Can clear=Yes
[19724.445613]   Sub-page Write Permissions for EPT: Can set=No, Can clear=Yes
[19724.452680]   Intel PT Uses Guest Physical Addresses: Can set=No, Can clear=Yes
[19724.460096]   Use TSC Scaling: Can set=No, Can clear=Yes
[19724.465514]   Enable User Wait and Pause: Can set=No, Can clear=Yes
[19724.471885]   Enable ENCLV Exiting: Can set=No, Can clear=Yes
[19724.477911] Processor based Tertiary Controls MSR: 0x0
[19724.483242]   LOADIWKEY Exiting: Can set=No, Can clear=Yes
[19724.488832]   Enable HLAT: Can set=No, Can clear=Yes
[19724.493904]   EPT Paging-write Control: Can set=No, Can clear=Yes
[19724.500105]   Guest-paging Verification: Can set=No, Can clear=Yes
[19724.506393] Exit Controls MSR: 0x3fefff00036dff
[19724.511028]   Save Debug Controls: Can set=Yes, Can clear=No
[19724.516795]   Host Address-Space Size: Can set=Yes, Can clear=Yes
[19724.522994]   Load IA32_PERF_GLOBAL_CTRL: Can set=No, Can clear=Yes
[19724.529366]   Acknowledge Interrupt On Exit: Can set=Yes, Can clear=Yes
[19724.536087]   Save IA32_PAT: Can set=Yes, Can clear=Yes
[19724.541419]   Load IA32_PAT: Can set=Yes, Can clear=Yes
[19724.546748]   Save IA32_EFER: Can set=Yes, Can clear=Yes
[19724.552167]   Load IA32_EFER: Can set=Yes, Can clear=Yes
[19724.557587]   Save VMXpreemption Timer Value: Can set=No, Can clear=Yes
[19724.564309]   Clear IA32_BNDCFGS: Can set=No, Can clear=Yes
[19724.569988]   Conceal VMX from PT: Can set=No, Can clear=Yes
[19724.575755]   Clear IA32_RTIT_CTL: Can set=No, Can clear=Yes
[19724.581519]   Clear IA32_LBR_CTL: Can set=No, Can clear=Yes
[19724.587211]   Load CET state: Can set=No, Can clear=Yes
[19724.592547]   Load PKRS: Can set=No, Can clear=Yes
[19724.597454] Entry Controls MSR: 0xd3ff000011ff
[19724.602090]   Load Debug Controls: Can set=Yes, Can clear=No
[19724.607857]   IA-32e Mode Guest: Can set=Yes, Can clear=Yes
[19724.613538]   Entry to SMM: Can set=No, Can clear=Yes
[19724.618696]   Deactivate Dual Monitor Treatment: Can set=No, Can clear=Yes
[19724.625679]   Load IA32_PERF_GLOBAL_CTRL: Can set=No, Can clear=Yes
[19724.632053]   Load IA32_PAT: Can set=Yes, Can clear=Yes
[19724.637471]   Load IA32_EFER: Can set=Yes, Can clear=Yes
[19724.642889]   Load IA32_BNDCFGS: Can set=No, Can clear=Yes
[19724.648479]   Conceal VMX from PT: Can set=No, Can clear=Yes
[19724.654246]   Load IA32_RTIT_CTL: Can set=No, Can clear=Yes
[19724.659926]   Load CET State: Can set=No, Can clear=Yes
[19724.665346]   Load Guest IA32_LBR_CTL: Can set=No, Can clear=Yes
[19724.671458]   Load PKRS: Can set=No, Can clear=Yes
 


