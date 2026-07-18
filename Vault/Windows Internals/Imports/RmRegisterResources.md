Registers resources to a [[Restart Manager]] session. The [[Restart Manager]] uses the list of resources registered with the session to determine which applications and services must be shut down and restarted. Resources can be identified by filenames, service short names, or [RM_UNIQUE_PROCESS](https://learn.microsoft.com/en-us/windows/desktop/api/restartmanager/ns-restartmanager-rm_unique_process) structures that describe running applications.

Reference:
https://learn.microsoft.com/en-us/windows/win32/api/restartmanager/nf-restartmanager-rmregisterresources