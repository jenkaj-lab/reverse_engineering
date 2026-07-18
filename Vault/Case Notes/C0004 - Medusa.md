---
case: C0004 - Medusa
date: 17-07-2026
source: MalwareBazaar
analyst: Alex
type: ransomware
tags:
  - malware
---
# Analysis
The analysis stage is used to gather information and document findings using static and dynamic analysis techniques.

## Metadata

| Field               | Value                                                                                           |
| ------------------- | ----------------------------------------------------------------------------------------------- |
| SHA256 Hash         | F40FB93230BB13D6116C03F0181F7EE0C613248035BC42F7B7507F73246CFF88                                |
| File Size           | 755200                                                                                          |
| File Type           | executable, 64-bit, console                                                                     |
| Magic Number        | 4D 5A 90 00 03 00 00 00 04 00 00 00 FF FF 00 00 B8 00 00 00 00 00 00 00 40 00 00 00 00 00 00 00 |
| Compile Timestamp   | Sat May 17 11:10:52 2025 (UTC)                                                                  |
| Digital Signature   | None                                                                                            |
| Entropy Value       | 6.595                                                                                           |
| Version Information | N/A                                                                                             |
| Imphash             | 1CC690A422707DB94DD0913CD9980C27                                                                |


## Static Analysis

#### FLOSS (strings)

Interesting strings with minimum length of 10:
```
Input size_t value is too big: size_t value doesn't fit into a DWORD.
RegCreateKeyExW failed.
test [IDENTIFIER] test
support@example.com
Please write me!
TRUMPTRUMPTRUMPTRUMPTRUMPTRUMPTRUMP
PUTLERPUTLER
Can`t decode master public key using base64
Can`t encrypt pc info using base64
Can't release file lock
Can't open file
Can't move file
Can't close handle
PAPADDINGXXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGX
:\$Recycle.Bin\
:\Recovery\
:\System Volume Information\
:\Windows\
:\$WinREAgent\
:\$Windows.~WS\
:\$WINDOWS.~BT\
\Google\Chrome\
requirements.html
SOFTWARE\PAIDMEMES
[-] Initialize PC info
[+] Keys loaded from registry
[!] Can`t decode keys using base64
[!] Error save keys in registry
[!] Can`t encrypt RSA keys using base64
e[+] Encrypted: 
[-] Skipping path: 
[!] Failed to scan directory: 
[-] Skipping file: 
, because read only. Error: 
[!] Skipping file: 
taskkill /f /im explorer.exe
start explorer.exe
[+] Increase threads count
[+] Decrease threads count
Passed: {} min | Circle #{} | CPU: {}% | Threads: {}/{} | Tasks: {}
Passed: {} min | Circle #{} | CPU: {}%
[!] Can`t set console title. Error: 
  -help          Display this help message
  -skip_misc     Skip all misc actions (commands, recycle, background image and etc...)
  -network       Run crypt only network(remote) drives
Usage: program [options, pathes]
[+] Network drives only
-skip_misc
[+] Skip misc
[+] Dropped file: 
[+] Dropped directory: 
, is elevated: 
, network drives: 
[+] Drives: 
 -network -skip_misc
[-] Circle # 
[+] Finished
cipher /w:
\SysWOW64\cmd.exe /c %windir%\sysnative\cmd.exe /c 
[+] Recycle bin cleaned
[!] Recycle bin not cleaned, error 0x
[+] Mounted: 
[!] Not mounted: 
SOFTWARE\Microsoft\Windows\CurrentVersion\Run
BabyLockerKZ
[+] Program added to autostart successfully. Path: 
[-] Get external IP
external_ip
https://api.ipify.org
[!] Failed to get shell window
[!] WNetGetConnection failed. Error: 0x%X
 and type 
[-] Get resource with id 
[!] Failed to get process ID
[!] Failed to open process
[!] Failed to initialize thread attribute list
[!] Failed to update thread attribute
[!] Failed to run non elevated command: %s. Error: %s
output.bmp
[-] Run sync command: %sS
[!] Failed to run async command: %s. Error: %s
[!] Failed to run sync command: %s. Error: %s
```

Persistence
```
SOFTWARE\Microsoft\Windows\CurrentVersion\Run
BabyLockerKZ
[+] Program added to autostart successfully.
```

Network capability
```
[-] Get external IP
external_ip
https://api.ipify.org
```
#### Imports/Exports
| Imports                                                                                                                                                                                                                                                                              | Suspicious reasons                                                                                                                     |
| ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ | -------------------------------------------------------------------------------------------------------------------------------------- |
| [[RmShutdown]]<br>[[RmEndSession]]<br>[[RmStartSession]]<br>[[RmGetList]]<br>[[RmRegisterResources]]<br>                                                                                                                                                                             | All these imports are used to interact with [[Restart Manager]]                                                                        |
| [[CryptStringToBinaryA]]<br>[[CryptStringToBinaryW]]<br>[[CryptBinaryToStringA]]<br>[[CryptBinaryToStringW]]                                                                                                                                                                         | Commonly used for encoding/decoding data (e.g. Base64)                                                                                 |
| [[CryptEncrypt]]<br>[[CryptGetKeyParam]]<br>[[CryptDestroyKey]]<br>[[CryptImportKey]]<br>[[CryptExportKey]]<br>[[CryptGenKey]]<br>[[CryptReleaseContext]]<br>[[CryptGenRandom]]<br>[[CryptAcquireContextW]]                                                                          | Used for cryptographic operations (key handling, encryption/decryption)                                                                |
| [[URLDownloadToFileW]]                                                                                                                                                                                                                                                               | Has the capability to download external content                                                                                        |
| **Enumeration**<br>[[FindFirstFileW]]<br>[[FindNextFileW]]<br>[[FindFirstFileExW]]<br><br>**Modification**<br>[[MoveFileW]]<br>[[WriteFile]]<br>[[DeleteFileW]]<br>[[SetFileAttributesW]]<br><br>**Devices**<br>[[QueryDosDeviceW]]<br><br>**Recycle Bin**<br>[[SHEmptyRecycleBinW]] | File system imports that have the capability to enumerate and modify system files. Can also query devices and empty the recycle bin.   |
| **Process**<br>[[GetCurrentProcess]]<br>[[GetCurrentProcessId]]<br>[[OpenProcess]]<br>[[CreateProcessW]]<br>[[CreatePipe]]<br><br>**Thread**<br>[[GetWindowThreadProcessId]]<br>[[GetCurrentThreadId]]<br>[[SwitchToThread]]<br>[[FreeLibraryAndExitThread]]<br>                     | Used to control processes and threads                                                                                                  |
| [[OpenProcessToken]]<br>[[GetTokenInformation]]                                                                                                                                                                                                                                      | Security functions used to open and gain information on Windows [[Access Token]]s.                                                     |
| [[PathFindExtensionW]]<br>[[PathIsDirectoryW]]                                                                                                                                                                                                                                       | Used to discover and verify file paths                                                                                                 |
| [[GlobalMemoryStatusEx]]<br>[[GetNativeSystemInfo]]<br>                                                                                                                                                                                                                              | Used to query system information                                                                                                       |
| [[RegCreateKeyExW]]<br>[[RegSetValueExW]]                                                                                                                                                                                                                                            | Used to create and set values in the [[Windows Registry]]                                                                              |
| [[FindVolumeClose]]<br>[[FindNextVolumeW]]<br>[[GetVolumePathNamesForVolumeNameW]]<br>[[SetVolumeMountPointW]]<br>[[FindFirstVolumeW]]                                                                                                                                               | Enumerate volumes on a machine                                                                                                         |
| [[GetEnvironmentStringsW]]<br>[[SetEnvironmentVariableW]]<br>                                                                                                                                                                                                                        | Get and set environment variables in a process                                                                                         |
| [[QueryPerformanceFrequency]]                                                                                                                                                                                                                                                        | Used for precise timing checks, can be used to detect slight delays in debuggers                                                       |
| [[RaiseException]]                                                                                                                                                                                                                                                                   | Raises software exceptions. It's commonly used for error handling, but may also be used for control flow obfuscation or anti-analysis. |
| [[RtlPcToFileHeader]]<br>[[GetModuleHandleExW]]                                                                                                                                                                                                                                      | Module inspection and management                                                                                                       |
| [[GetShellWindow]]<br>[[GetForegroundWindow]]<br>                                                                                                                                                                                                                                    | User Interaction                                                                                                                       |
| [[GetAsyncKeyState]]                                                                                                                                                                                                                                                                 | Detects input                                                                                                                          |
| [[SystemParametersInfoW]]                                                                                                                                                                                                                                                            | System configuration                                                                                                                   |
| [[WNetGetConnectionW]]                                                                                                                                                                                                                                                               | Gets the name of the system's network resource                                                                                         |
#### File Structure
**Architecture**
Executable, 64-bit, console

**Entry Point**
0x000423E8 (section[.text])
```
48 83 EC 28 E8 63 06 00 00 48 83 C4 28 E9 72 FE FF FF CC CC 48 83 EC 28 4D 8B 41 38 48 8B CA 49
```

**Sections**
Pretty standard sections overall: .text, .rdata, .data, .pdata, .rsrc, .reloc
	.rsrc has an entropy value of 7.905

**Resources**
SETTINGS: unknown signature

#### Packers / Obfuscation
PE64
    Operation system: Windows (Vista) [AMD64, 64-bit, Console]
    Linker: Microsoft Linker (14.43.34810)
    Compiler: Microsoft Visual C/C++ (19.43.34810) [LTCG/C++]
    Language: C++
    Tool: Microsoft Visual Studio (2022, 17.13)
    (Heur) Packer: Generic [Section #4 (".rsrc") compressed]
    Debug data: Records [codeview, vc_feature, pogo]
    (Heur) Debug data: Contains [Absolute PDB path]

#### Screenshots

Windows detected the sample as soon as it was unzipped
![[Pasted image 20260718001414.png]]

Lots of padding near the end of the file (HxD Hex Editor)
![[Pasted image 20260718155503.png]]

VirusTotal detection ratio
![[Pasted image 20260718160624.png]]
## Dynamic Analysis
### Behavioral Analysis
#### Process Tree
#### File Activity
#### Registry Activity
#### Network Traffic
#### Persistence
#### Dropped Files
| File | Location | Hash |
| ---- | -------- | ---- |
|      |          |      |
|      |          |      |
### Screenshots

Running process in CMD
![[Pasted image 20260718164855.png]]

"How to recover data" HTML file (ransom note)
![[Pasted image 20260718165439.png]]

Downloads folder
![[Pasted image 20260718165613.png]]

Wallpaper
![[Pasted image 20260718165829.png]]
### Deep Analysis
#### IDA Free


# Summary
#### Sample Classification
#### Challenges / Difficulty Level
#### Lessons Learned

