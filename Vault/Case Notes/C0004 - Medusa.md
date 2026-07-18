---
case: C0004 - Medusa
date: 17-07-2026
source: MalwareBazaar
analyst: Alex
type: ransomware
tags:
  - malware
---

## Notes
Windows detected the sample as soon as it was unzipped
![[Pasted image 20260718001414.png]]

# Analysis
The analysis stage is used to gather information and document findings using static and dynamic analysis techniques.

## Metadata

| Field                 | Value                                                                                           |
| --------------------- | ----------------------------------------------------------------------------------------------- |
| SHA256 Hash           | F40FB93230BB13D6116C03F0181F7EE0C613248035BC42F7B7507F73246CFF88                                |
| File Size             | 755200                                                                                          |
| File Type             | executable, 64-bit, console                                                                     |
| Magic Number          | 4D 5A 90 00 03 00 00 00 04 00 00 00 FF FF 00 00 B8 00 00 00 00 00 00 00 40 00 00 00 00 00 00 00 |
| Compile Timestamp     | Sat May 17 11:10:52 2025 (UTC)                                                                  |
| Digital Signature     | Microsoft Linker 14.43                                                                          |
| Entropy Value         | 6.595                                                                                           |
| Version Information   | N/A                                                                                             |


## Static Analysis

#### FLOSS (strings)
Interesting strings:
```

```

#### Libraries
Suspicious libraries:
- RstrtMgr.DLL - Restart manager library
- urlmon.dll - OLE32 Extensions for Win32
- CRYPT32.dll - Windows crypto library
- MPR.dll - Multiple Provider Router library

#### Imports/Exports
| Import                                                                                                                                                                                                      | Suspicious                                                              |
| ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------- |
| [[RmShutdown]]<br>[[RmEndSession]]<br>[[RmStartSession]]<br>[[RmGetList]]<br>[[RmRegisterResources]]<br>                                                                                                    | All these imports are used to interact with [[Windows Restart Manager]] |
| [[CryptStringToBinaryA]]<br>[[CryptStringToBinaryW]]<br>[[CryptBinaryToStringA]]<br>[[CryptBinaryToStringW]]                                                                                                | Commonly used for encoding/decoding data (e.g. Base64)                  |
| [[CryptEncrypt]]<br>[[CryptGetKeyParam]]<br>[[CryptDestroyKey]]<br>[[CryptImportKey]]<br>[[CryptExportKey]]<br>[[CryptGenKey]]<br>[[CryptReleaseContext]]<br>[[CryptGenRandom]]<br>[[CryptAcquireContextW]] | Used for cryptographic operations (key handling, encryption/decryption) |
| [[URLDownloadToFileW]]                                                                                                                                                                                      | Has the capability to download content from URLs                        |
|                                                                                                                                                                                                             |                                                                         |
|                                                                                                                                                                                                             |                                                                         |
| [[PathFindExtensionW]]                                                                                                                                                                                      |                                                                         |
| [[PathIsDirectoryW]]                                                                                                                                                                                        |                                                                         |
|                                                                                                                                                                                                             |                                                                         |
|                                                                                                                                                                                                             |                                                                         |
|                                                                                                                                                                                                             |                                                                         |
|                                                                                                                                                                                                             |                                                                         |
| [[GlobalMemoryStatusEx]]                                                                                                                                                                                    |                                                                         |
| [[OpenProcess]]                                                                                                                                                                                             |                                                                         |
| [[FindNextFileW]]                                                                                                                                                                                           |                                                                         |
| [[CreateProcessW]]                                                                                                                                                                                          |                                                                         |
| [[GetCurrentProcess]]                                                                                                                                                                                       |                                                                         |
| [[FindNextVolumeW]]                                                                                                                                                                                         |                                                                         |
| [[CreatePipe]]                                                                                                                                                                                              |                                                                         |
| [[GetVolumePathNamesForVolumeNameW]]                                                                                                                                                                        |                                                                         |
| [[FindVolumeClose]]                                                                                                                                                                                         |                                                                         |
| [[SetVolumeMountPointW]]                                                                                                                                                                                    |                                                                         |
| [[FindFirstVolumeW]]                                                                                                                                                                                        |                                                                         |
| [[QueryDosDeviceW]]                                                                                                                                                                                         |                                                                         |
| [[SetConsoleTitleW]]                                                                                                                                                                                        |                                                                         |
| [[GetCurrentProcessId]]                                                                                                                                                                                     |                                                                         |
| [[MoveFileW]]                                                                                                                                                                                               |                                                                         |
| [[SetFileAttributesW]]                                                                                                                                                                                      |                                                                         |
| [[FindFirstFileW]]                                                                                                                                                                                          |                                                                         |
| [[WriteFile]]                                                                                                                                                                                               |                                                                         |
| [[GetEnvironmentStringsW]]                                                                                                                                                                                  |                                                                         |
| [[SetEnvironmentVariableW]]                                                                                                                                                                                 |                                                                         |
| [[GetCurrentThreadId]]                                                                                                                                                                                      |                                                                         |
| [[SwitchToThread]]                                                                                                                                                                                          |                                                                         |
| [[GetNativeSystemInfo]]                                                                                                                                                                                     |                                                                         |
| [[FindFirstFileExW]]                                                                                                                                                                                        |                                                                         |
| [[QueryPerformanceFrequency]]                                                                                                                                                                               |                                                                         |
| [[RtlPcToFileHeader]]                                                                                                                                                                                       |                                                                         |
| [[RaiseException]]                                                                                                                                                                                          |                                                                         |
| [[FreeLibraryAndExitThread]]                                                                                                                                                                                |                                                                         |
| [[GetModuleHandleExW]]                                                                                                                                                                                      |                                                                         |
| [[DeleteFileW]]                                                                                                                                                                                             |                                                                         |
| [[GetAsyncKeyState]]                                                                                                                                                                                        |                                                                         |
| [[GetWindowThreadProcessId]]                                                                                                                                                                                |                                                                         |
| [[SystemParametersInfoW]]                                                                                                                                                                                   |                                                                         |
| [[GetShellWindow]]                                                                                                                                                                                          |                                                                         |
| [[GetForegroundWindow]]                                                                                                                                                                                     |                                                                         |
|                                                                                                                                                                                                             |                                                                         |
|                                                                                                                                                                                                             |                                                                         |
|                                                                                                                                                                                                             |                                                                         |
|                                                                                                                                                                                                             |                                                                         |
|                                                                                                                                                                                                             |                                                                         |
|                                                                                                                                                                                                             |                                                                         |
|                                                                                                                                                                                                             |                                                                         |
|                                                                                                                                                                                                             |                                                                         |
|                                                                                                                                                                                                             |                                                                         |
| [[GetTokenInformation]]                                                                                                                                                                                     |                                                                         |
| [[OpenProcessToken]]                                                                                                                                                                                        |                                                                         |
| [[RegCreateKeyExW]]                                                                                                                                                                                         |                                                                         |
| [[RegSetValueExW]]                                                                                                                                                                                          |                                                                         |
| [[SHEmptyRecycleBinW]]                                                                                                                                                                                      |                                                                         |
| [[WNetGetConnectionW]]                                                                                                                                                                                      |                                                                         |



#### File Structure
- Architecture:
- Entry Point:
- Sections:
	- .rsrc has an entropy value of 7.905
- Resources:
#### Packers / Obfuscation
- Packed:
- Protector:
- Indicators:


## Dynamic Analysis
### Behavioral Analysis
#### Process Tree
#### File Activity
#### Registry Activity
#### Network Traffic
#### Persistence
#### Dropped Files
|File|Location|Hash|
|---|---|---|
||||

### Deep Analysis
#### Disassembly
#### Decompilation
#### Memory Analysis
#### Reverse Engineering
#### Configuration Extraction
#### Capability Mapping (MITRE ATT&CK)
|Technique|ID|Evidence|
|---|---|---|
||||

# Summary
#### Sample Classification
#### Challenges / Difficulty Level
#### Lessons Learned

