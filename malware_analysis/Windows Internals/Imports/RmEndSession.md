Ends the [[Restart Manager]] session. This function should be called by the primary installer that has previously started the session by calling the [RmStartSession](https://learn.microsoft.com/en-us/windows/desktop/api/restartmanager/nf-restartmanager-rmstartsession) function. The **RmEndSession** function can be called by a secondary installer that is joined to the session once no more resources need to be registered by the secondary installer.

Reference:
https://learn.microsoft.com/en-us/windows/win32/api/restartmanager/nf-restartmanager-rmendsession