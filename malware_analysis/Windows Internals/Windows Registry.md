## Purpose
The Registry contains information that Windows continually references during operation, such as profiles for each user, the applications installed on the computer and the types of documents that each can create, property sheet settings for folders and application icons, what hardware exists on the system, and the ports that are being used.

### Registry Hives
A _hive_ is a logical group of keys, subkeys, and values in the registry that has a set of supporting files loaded into memory when the operating system is started or a user logs in.

|Registry hive|Supporting files|
|---|---|
|**HKEY_CURRENT_CONFIG**|System, System.alt, System.log, System.sav|
|**HKEY_CURRENT_USER**|Ntuser.dat, Ntuser.dat.log|
|**HKEY_LOCAL_MACHINE\SAM**|Sam, Sam.log, Sam.sav|
|**HKEY_LOCAL_MACHINE\Security**|Security, Security.log, Security.sav|
|**HKEY_LOCAL_MACHINE\Software**|Software, Software.log, Software.sav|
|**HKEY_LOCAL_MACHINE\System**|System, System.alt, System.log, System.sav|
|**HKEY_USERS\.DEFAULT**|Default, Default.log, Default.sav

## Abuse
### [[Persistence]]

The following Registry keys can be used to set startup folder items for persistence:
- `HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\User Shell Folders`
- `HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders`
- `HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders`
- `HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\User Shell Folders`

The following Registry keys can control automatic startup of services during boot:
- `HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\RunServicesOnce`
- `HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\RunServicesOnce`
- `HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\RunServices`
- `HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\RunServices`

Using policy settings to specify startup programs creates corresponding values in either of two Registry keys:
- `HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer\Run`
- `HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer\Run`
## References
- https://learn.microsoft.com/en-us/troubleshoot/windows-server/performance/windows-registry-advanced-users
- https://learn.microsoft.com/en-us/windows/win32/sysinfo/registry-hives
- https://attack.mitre.org/techniques/T1547/001/