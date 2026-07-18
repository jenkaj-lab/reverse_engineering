## Purpose
The purpose of the restart manager is to reduce the need for system reboots during software installation. Locked files and processes that are in use by running applications and services may prevent modification; the restart manager can release those locks by terminating processes to allow installations to continue without rebooting.

## Abuse
Malware, especially ransomware, can abuse the restart manager to iterate through files and release locks that would otherwise interfere with encryption.

### Ransomware
Conti ransomware, discussed in reference 2 by Crowdstrike, uses the following function flow to abuse the restart manager:
1. [[RmStartSession]] creates a new restart manager session and iterates through every file in the system using its newly allocated session handle
2. [[RmGetList]] gets the exact number of applications identified as using the file, allocates the required memory, then performs a second call to [[RmGetList]] to retrieve information on each application
3. [[RmShutdown]] is used to request the shutdown of processes and services using the target file

### [[Process Discovery]]
Without knowing anything about a victim’s system, an attacker can iterate over every executable file of the system and register each of them in a Restart Manager session
### [[Debugger Evasion]] or [[Virtualization or Sandbox Evasion]]
Similar to process discovery, the malware can iterate across running processes and compare the user-friendly names against a list of known debuggers, VMs and sandboxes and adjust their behavior accordingly.
### [[Disable or Modify Tools]]
In addition to killing process that would interfere with encryption, it can also target other processes that might be installed to detect its presence i.e. antivirus systems. Similarly with the debugger evasion point, the malware can compare a list of processes gathered using [[RmGetList]] and compare them against a list of user-friendly names of common detection tools. 

## DLLs
- RstrtMgr.dll

## Imports
- [[RmShutdown]]
- [[RmEndSession]]
- [[RmStartSession]]
- [[RmGetList]]
- [[RmRegisterResources]]

## References
- https://learn.microsoft.com/en-us/windows/win32/rstmgr/about-restart-manager
- https://www.crowdstrike.com/en-us/blog/windows-restart-manager-part-1/
- https://www.crowdstrike.com/en-us/blog/windows-restart-manager-part-2/