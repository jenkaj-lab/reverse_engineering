# Guide
Unfortunately I can't save my snapshots to GitHub so the best I can do is provide the specs for all the Virtual Machines (VM) I use for reverse engineering including things like browser favourites exports, list of downloadables, and setup checklists.

# Virtual Machines
## MalWin

Malwin is a custom Windows 10 VM designed for general purpose reverse engineering. This VM got its name before I started doing crackmes and I was only doing malware analysis, so a better name might be "RevWin"... but I'll save that for another day.

| Specifications   | Value      |
| ---------------- | ---------- |
| Operating System | Windows 10 |
| Storage          | 100GB      |
| RAM              | 8GB        |
| Cores            | 2          |

**Tools**
- SysInternals Suite
- PEStudio
- Detect It Easy (DIE)
- FLOSS
- Ghidra (+ Java JDK)
- x64dbg
- Wireshark
- Regshot
- Everything (file searcher)
- 7zip
- Python
- VSCode

**Browser Bookmarks/Favourites**
- Malware Bazaar
- VirusTotal
- ytisf/theZoo (Github)

**Important Extras**
- SPICE Guest Tools (clipboard functionality & dynamic VM resizing)
- Visual Studio Build Tools (Desktop development with C++) with MSVC v143 or above, C++ CMake tools for Windows, and Windows 10 or 11 SDK
