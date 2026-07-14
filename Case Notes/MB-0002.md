# Acquisition
Source: Malware Bazaar
SHA256 hash: f8cd736a531c65cce00a01fab875cb2cc350b4561e6eaa643fb46d1b62cb3ba7
SHA3-384 hash: 0b61b27ed952f0dac1d2c3e39e9325a57f796dc55d28c2fd4d56b3d59ceab62084a4a2838e11288d79c3d3f64072e36c
SHA1 hash: 69d1d2ed3ab3519d348748d141dbc12e9c819215
MD5 hash: baf37d8f887d4c5a8d2da49feabd08f2
humanhash: skylark-eight-south-six
File name: f8cd736a531c65cce00a01fab875cb2cc350b4561e6eaa643fb46d1b62cb3ba7
Signature: ConnectWise 

# Static Analysis
## Properties
File type: Application (.exe)
Description: Installer
Size: 27MB (28,343,776 bytes)

## Detect it easy
PE32
    Operation system: Windows (95) [I386, 32-bit, GUI]
    (Heur) Linker: Microsoft Linker (2.37)
    (Heur) Compiler: Microsoft Visual C/C++
    (Heur) Language: C/C++
    Sign tool: Windows Authenticode (2.0) [PKCS #7, after overlay]
    (Heur) Protection: Generic [IAT directory empty]
    (Heur) Packer: Generic [Sections like Nullsoft Installer]
    Installer: Nullsoft Scriptable Install System (3.08-2)
    Overlay: Binary [Offset = 0x00015600, Size = 0x01af27e0]
        Unknown: Unknown

## PEView
file > sha256,F8CD736A531C65CCE00A01FAB875CB2CC350B4561E6EAA643FB46D1B62CB3BA7
file > first 32 bytes (hex),4D 5A 90 00 03 00 00 00 04 00 00 00 FF FF 00 00 B8 00 00 00 00 00 00 00 40 00 00 00 00 00 00 00 
file > info,size: 28343776 bytes, entropy: 7.998
file > type,executable, 32-bit, GUI
file > description,Installer

## Imports
### Flagged
AdjustTokenPrivileges,x,implicit,-,0x00040600,0x00040600,ADVAPI32.dll
LookupPrivilegeValueW,x,implicit,-,0x00040618,0x00040618,ADVAPI32.dll
OpenProcessToken,x,implicit,-,0x00040630,0x00040630,ADVAPI32.dll
RegCreateKeyExW,x,implicit,-,0x00040652,0x00040652,ADVAPI32.dll
RegDeleteKeyW,x,implicit,-,0x00040664,0x00040664,ADVAPI32.dll
RegDeleteValueW,x,implicit,-,0x00040674,0x00040674,ADVAPI32.dll
RegEnumKeyW,x,implicit,-,0x00040686,0x00040686,ADVAPI32.dll
RegSetValueExW,x,implicit,-,0x000406C8,0x000406C8,ADVAPI32.dll
SetFileSecurityW,x,implicit,-,0x000406DA,0x000406DA,ADVAPI32.dll
CopyFileW,x,implicit,-,0x000407E8,0x000407E8,KERNEL32.dll
CreateDirectoryW,x,implicit,-,0x000407F4,0x000407F4,KERNEL32.dll
CreateProcessW,x,implicit,-,0x00040816,0x00040816,KERNEL32.dll
DeleteFileW,x,implicit,-,0x00040838,0x00040838,KERNEL32.dll
FindFirstFileW,x,implicit,-,0x0004087C,0x0004087C,KERNEL32.dll
FindNextFileW,x,implicit,-,0x0004088E,0x0004088E,KERNEL32.dll
GetCurrentProcess,x,implicit,-,0x000408BE,0x000408BE,KERNEL32.dll
MoveFileExW,x,implicit,-,0x00040A82,0x00040A82,KERNEL32.dll
MoveFileW,x,implicit,-,0x00040A90,0x00040A90,KERNEL32.dll
RemoveDirectoryW,x,implicit,-,0x00040AC8,0x00040AC8,KERNEL32.dll
SearchPathW,x,implicit,-,0x00040ADC,0x00040ADC,KERNEL32.dll
SetEnvironmentVariableW,x,implicit,-,0x00040B02,0x00040B02,KERNEL32.dll
SetFileAttributesW,x,implicit,-,0x00040B2C,0x00040B2C,KERNEL32.dll
WriteFile,x,implicit,-,0x00040B96,0x00040B96,KERNEL32.dll
WritePrivateProfileStringW,x,implicit,-,0x00040BA2,0x00040BA2,KERNEL32.dll
SHBrowseForFolderW,x,implicit,-,0x00040C76,0x00040C76,SHELL32.dll
SHFileOperationW,x,implicit,-,0x00040C8C,0x00040C8C,SHELL32.dll
SHGetFileInfoW,x,implicit,-,0x00040CA0,0x00040CA0,SHELL32.dll
SHGetPathFromIDListW,x,implicit,-,0x00040CB2,0x00040CB2,SHELL32.dll
SHGetSpecialFolderLocation,x,implicit,-,0x00040CCA,0x00040CCA,SHELL32.dll
ShellExecuteExW,x,implicit,-,0x00040CE8,0x00040CE8,SHELL32.dll
CloseClipboard,x,implicit,-,0x00040D5E,0x00040D5E,USER32.dll
EmptyClipboard,x,implicit,-,0x00040DFE,0x00040DFE,USER32.dll
OpenClipboard,x,implicit,-,0x00040F96,0x00040F96,USER32.dll
SetClipboardData,x,implicit,-,0x0004102E,0x0004102E,USER32.dll
SystemParametersInfoW,x,implicit,-,0x000410C4,0x000410C4,USER32.dll

### Categorised

**Clipboard**
CloseClipboard,x,implicit,-,0x00040D5E,0x00040D5E,USER32.dll
EmptyClipboard,x,implicit,-,0x00040DFE,0x00040DFE,USER32.dll
OpenClipboard,x,implicit,-,0x00040F96,0x00040F96,USER32.dll
SetClipboardData,x,implicit,-,0x0004102E,0x0004102E,USER32.dll

**File/Folder/Directory Modification**
DeleteFileW,x,implicit,-,0x00040838,0x00040838,KERNEL32.dll
MoveFileExW,x,implicit,-,0x00040A82,0x00040A82,KERNEL32.dll
MoveFileW,x,implicit,-,0x00040A90,0x00040A90,KERNEL32.dll
RemoveDirectoryW,x,implicit,-,0x00040AC8,0x00040AC8,KERNEL32.dll
SHBrowseForFolderW,x,implicit,-,0x00040C76,0x00040C76,SHELL32.dll
SHFileOperationW,x,implicit,-,0x00040C8C,0x00040C8C,SHELL32.dll
CopyFileW,x,implicit,-,0x000407E8,0x000407E8,KERNEL32.dll
CreateDirectoryW,x,implicit,-,0x000407F4,0x000407F4,KERNEL32.dll
SetFileAttributesW,x,implicit,-,0x00040B2C,0x00040B2C,KERNEL32.dll
WriteFile,x,implicit,-,0x00040B96,0x00040B96,KERNEL32.dll

**Enumeration**
FindFirstFileW,x,implicit,-,0x0004087C,0x0004087C,KERNEL32.dll
FindNextFileW,x,implicit,-,0x0004088E,0x0004088E,KERNEL32.dll
SHGetPathFromIDListW,x,implicit,-,0x00040CB2,0x00040CB2,SHELL32.dll
SHGetSpecialFolderLocation,x,implicit,-,0x00040CCA,0x00040CCA,SHELL32.dll
SearchPathW,x,implicit,-,0x00040ADC,0x00040ADC,KERNEL32.dll
SHGetFileInfoW,x,implicit,-,0x00040CA0,0x00040CA0,SHELL32.dll
LookupPrivilegeValueW,x,implicit,-,0x00040618,0x00040618,ADVAPI32.dll
SetFileSecurityW,x,implicit,-,0x000406DA,0x000406DA,ADVAPI32.dll
SystemParametersInfoW,x,implicit,-,0x000410C4,0x000410C4,USER32.dll

**Registry Modification**
RegCreateKeyExW,x,implicit,-,0x00040652,0x00040652,ADVAPI32.dll
RegDeleteKeyW,x,implicit,-,0x00040664,0x00040664,ADVAPI32.dll
RegDeleteValueW,x,implicit,-,0x00040674,0x00040674,ADVAPI32.dll
RegEnumKeyW,x,implicit,-,0x00040686,0x00040686,ADVAPI32.dll
RegSetValueExW,x,implicit,-,0x000406C8,0x000406C8,ADVAPI32.dll

**Process Manipulation**
OpenProcessToken,x,implicit,-,0x00040630,0x00040630,ADVAPI32.dll
CreateProcessW,x,implicit,-,0x00040816,0x00040816,KERNEL32.dll
GetCurrentProcess,x,implicit,-,0x000408BE,0x000408BE,KERNEL32.dll
ShellExecuteExW,x,implicit,-,0x00040CE8,0x00040CE8,SHELL32.dll

**Other/Privileged Operations**
AdjustTokenPrivileges,x,implicit,-,0x00040600,0x00040600,ADVAPI32.dll
SetEnvironmentVariableW,x,implicit,-,0x00040B02,0x00040B02,KERNEL32.dll
WritePrivateProfileStringW,x,implicit,-,0x00040BA2,0x00040BA2,KERNEL32.dll

### Certificate Info
name,Edgar Palacios
signature-info,A certificate was explicitly revoked by its issuer.
issued-by,Microsoft ID Verified CS EOC CA 04
stamp > signing,Sat Jun 27 01:13:06 2026
valid-from,Fri Jun 26 22:21:20 2026
valid-to,Mon Jun 29 22:21:20 2026
serial-number,3300026891D9C3E0B25E0D64DE000000026891

## FLOSS
[[Strings]]

No suspicious strings identified. Strings searched for:
- http
- dll
- .exe
- powershell
- cmd
- reg add
- taskkill

# Dynamic Analysis

I tried to run the sample and was blocked by [[User Account Control]]. To bypass this I had to use registry editor to disable UAC via "EnableLUA" and restart the VM:
![[Pasted image 20260714164432.png]]

The above fix worked and I was now able to run the sample.

The sample attempted to install C++
![[Pasted image 20260714165142.png]]

## Regshot
[[Regshot]]

46207 changes
## ProcMon
### Filter for f8cd736a531c65cce00a01fab875cb2cc350b4561e6eaa643fb46d1b62cb3ba7.exe

#### File system activity

| Timestamp                   | Operation  | Value                                                                                                                    |
| --------------------------- | ---------- | ------------------------------------------------------------------------------------------------------------------------ |
| 14/07/2026 16:49:14.0960700 | CreateFile | C:\Users\jenkaj\AppData\Local\Microsoft\Windows\Caches\{AFBF9F1A-8EE8-4C77-AF34-C647E37CA0D9}.1.ver0x0000000000000002.db |
| 14/07/2026 16:49:14.2539758 | CreateFile | C:\Users\jenkaj\AppData\Local\Temp\BundleTemp\InstallerDesk.msi                                                          |
| 14/07/2026 16:49:14.2541209 | ReadFile   | C:\Users\jenkaj\Downloads\f8cd736a531c65cce00a01fab875cb2cc350b4561e6eaa643fb46d1b62cb3ba7.exe                           |
| 14/07/2026 16:49:14.2545261 | WriteFile  | C:\Users\jenkaj\AppData\Local\Temp\BundleTemp\InstallerDesk.msi                                                          |
These read and write operations repeat continuously before a CloseFile operation occurs at 14/07/2026 16:49:14.2541209

| Timestamp                   | Operation  | Value                                                                                          |
| --------------------------- | ---------- | ---------------------------------------------------------------------------------------------- |
| 14/07/2026 16:49:14.2867973 | CreateFile | C:\Users\jenkaj\AppData\Local\Temp\BundleTemp\vc_redist.x64.exe                                |
| 14/07/2026 16:49:14.2873174 | ReadFile   | C:\Users\jenkaj\Downloads\f8cd736a531c65cce00a01fab875cb2cc350b4561e6eaa643fb46d1b62cb3ba7.exe |
| 14/07/2026 16:49:14.2878164 | WriteFile  | C:\Users\jenkaj\AppData\Local\Temp\BundleTemp\vc_redist.x64.exe                                |
As in the figure above, these operations repeat, reading different offsets from the sample and writing them to the new file until the target file is closed at 14/07/2026 16:49:14.5341977

#### Process and thread activity
- Loaded a series of DLLs
- Created process C:\Users\jenkaj\AppData\Local\Temp\BundleTemp\vc_redist.x64.exe

#### Network activity
none

#### Registry activity
No registry keys created

### Filter for vc_redist.x64.exe
#### Process and thread activity
- Created process C:\Windows\Temp\{80C92D3B-CAB9-431A-8274-2C0F3B8CFABB}\.cr\vc_redist.x64.exe
#### File system activity
C:\Users\jenkaj\AppData\Local\Temp\BundleTemp\vc_redist.x64.exe created and is writing to file C:\Windows\Temp\{80C92D3B-CAB9-431A-8274-2C0F3B8CFABB}\.cr\vc_redist.x64.exe

File created C:\Windows\Temp\{B865C48A-03A9-42C0-900D-F93D5EC11825}\.ba\wixstdba.dll is being written to from C:\Windows\Temp\{80C92D3B-CAB9-431A-8274-2C0F3B8CFABB}\.cr\vc_redist.x64.exe

C:\Windows\Temp\{80C92D3B-CAB9-431A-8274-2C0F3B8CFABB}\.cr\vc_redist.x64.exe wrote to file C:\Windows\Temp\{B865C48A-03A9-42C0-900D-F93D5EC11825}\.ba\thm.wxl

There are many more file writes. From here I navigated to the location of the file writes and found the following:

![[Pasted image 20260714173320.png]]

Each folder has a license and thm file.

## ProcExp

Parent: explorer.exe(4168)
Path: C:\Users\jenkaj\Downloads\f8cd736a531c65cce00a01fab875cb2cc350b4561e6eaa643fb46d1b62cb3ba7.exe
Command line: "C:\Users\jenkaj\Downloads\f8cd736a531c65cce00a01fab875cb2cc350b4561e6eaa643fb46d1b62cb3ba7.exe" 

Parent: f8cd736a531c65cce00a01fab875cb2cc350b4561e6eaa643fb46d1b62cb3ba7.exe(3468)
Path: C:\Users\jenkaj\AppData\Local\Temp\BundleTemp\vc_redist.x64.exe
Command line: "C:\Users\jenkaj\AppData\Local\Temp\BundleTemp\vc_redist.x64.exe"

Parent: vc_redist.x64.exe(1540)
Path: C:\Windows\Temp\{80C92D3B-CAB9-431A-8274-2C0F3B8CFABB}\.cr\vc_redist.x64.exe
Command line: "C:\Windows\Temp\{80C92D3B-CAB9-431A-8274-2C0F3B8CFABB}\.cr\vc_redist.x64.exe" -burn.clean.room="C:\Users\jenkaj\AppData\Local\Temp\BundleTemp\vc_redist.x64.exe" -burn.filehandle.attached=724 -burn.filehandle.self=720

# Ghidra
## Import f8cd736a531c65cce00a01fab875cb2cc350b4561e6eaa643fb46d1b62cb3ba7.exe

From Ghidra I have identified that this is an NSIS installer from the following string:
```
DEFINED	0040c192	u_Installer_integrity_check_has_fa_0040c192	unicode u"Installer integrity check has failed. Common causes include\nincomplete download and damaged media. Contact the\ninstaller's author to obtain a new copy.\n\nMore information at:\nhttp://nsis.sf.net/NSIS_Error"	u"Installer integrity check has failed. Common causes include\nincomplete download and damaged media. Contact the\ninstaller's author to obtain a new copy.\n\nMore information at:\nhttp://nsis.sf.net/NSIS_Error"	unicode	408	true
```

"NSIS (Nullsoft Scriptable Install System) is a **free, open-source** tool for creating Windows installers that is designed to be **small, fast, and efficient**, with a minimal overhead of only **34 KB**. It uses a **script-based** approach (.nsi files) compiled via `makensis.exe`, allowing for full control over installation logic, including file extraction, registry editing, and shortcut creation."

Also
```
DEFINED	00452a10	Rsrc_Manifest_1_409	ds "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?><assembly xmlns=\"urn:schemas-microsoft-com:asm.v1\" manifestVersion=\"1.0\"><assemblyIdentity version=\"1.0.0.0\" processorArchitecture=\"*\" name=\"Nullsoft.NSIS.exehead\" type=\"win32\"/><description>Nullsoft Install System v3.08-2</description><trustInfo xmlns=\"urn:schemas-microsoft-com:asm.v3\"><security><requestedPrivileges><requestedExecutionLevel level=\"requireAdministrator\" uiAccess=\"false\"/></requestedPrivileges></security></trustInfo><compatibility xmlns=\"urn:schemas-microsoft-com:compatibility.v1\"><application><supportedOS Id=\"{8e0f7a12-bfb3-4fe8-b9a5-48fd50a15a9a}\"/><supportedOS Id=\"{1f676c76-80e1-4239-95bb-83d0f6d0da78}\"/><supportedOS Id=\"{4a2f28e3-53b9-4441-ba9c-d69d4a4a6e38}\"/><supportedOS Id=\"{35138b9a-5d96-4fbd-8e2d-a2440225f93a}\"/></application></compatibility></assembly>"	"<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?><assembly xmlns=\"urn:schemas-microsoft-com:asm.v1\" manifestVersion=\"1.0\"><assemblyIdentity version=\"1.0.0.0\" processorArchitecture=\"*\" name=\"Nullsoft.NSIS.exehead\" type=\"win32\"/><description>Nullsoft Install System v3.08-2</description><trustInfo xmlns=\"urn:schemas-microsoft-com:asm.v3\"><security><requestedPrivileges><requestedExecutionLevel level=\"requireAdministrator\" uiAccess=\"false\"/></requestedPrivileges></security></trustInfo><compatibility xmlns=\"urn:schemas-microsoft-com:compatibility.v1\"><application><supportedOS Id=\"{8e0f7a12-bfb3-4fe8-b9a5-48fd50a15a9a}\"/><supportedOS Id=\"{1f676c76-80e1-4239-95bb-83d0f6d0da78}\"/><supportedOS Id=\"{4a2f28e3-53b9-4441-ba9c-d69d4a4a6e38}\"/><supportedOS Id=\"{35138b9a-5d96-4fbd-8e2d-a2440225f93a}\"/></application></compatibility></assembly>"	string	844	true
```

From the string above we can see the installer requires elevated privileges when executed from the "requireAdministrator" level.

---

This wasn't working so I had to remove the C++ already installed on my machine using add/remove programs. I let the installer extract the necessary packages.

## Autoruns
From autoruns I was able to find a new registry key for ScreenConnect:

Key: Computer\HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Lsa\Authentication Packages
Value: C:\Program Files (x86)\ScreenConnect Client (6d833e57e5a31c6a)\ScreenConnect.WindowsAuthenticationPackage.dll		(Verified) ConnectWise, LLC	C:\Program Files (x86)\ScreenConnect Client (6d833e57e5a31c6a)\ScreenConnect.WindowsAuthenticationPackage.dll	Thu Jun  5 21:44:32 2025	

---

Correlating this with sandbox info online and VirusTotal
![[Pasted image 20260714184357.png]]

This looks like a legitimate ScreenConnect tool which is marked as malicious because it is an admin tool. For example:

![[Pasted image 20260714184457.png]]

Dr. Web vxCube thinks its malicious because it enables autoruns, creates temp files, etc. It does do this, but from my own analysis it seems to do this to install C++.

I think this is more of a potentially unwanted program which could be misused by threat actors. It's possible this could have been distributed during a social engineering attack, but overall this does seem to be a legitimate tool with a bad reputation.
