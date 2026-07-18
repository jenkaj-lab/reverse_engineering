Decrements the reference count of a loaded dynamic-link library (DLL) by one, then calls [ExitThread](https://learn.microsoft.com/en-us/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitthread) to terminate the calling thread. The function does not return.

Reference:
https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-freelibraryandexitthread