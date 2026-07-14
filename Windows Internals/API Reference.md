



-AddVectoredExceptionHandler
	- Allows handling of exceptions in debugging or anti-analysis
- CreateProcessA
	- Creates a process
- GetCurrentProcess
	- Gets a handle to a process
- GetCurrentProcessId
	- Gets the ID of a process
- GetCurrentThread
	- Gets a handle of a thread
- GetCurrentThreadId
	- Gets a thread ID
- GetThreadContext
	- Gets the **CPU state** of a thread
- GetThreadPriority
	- Get the priority level of a thread
- OpenProcess
	- Open a process e.g. explorer.exe
- OutputDebugStringA
	- Send debugging messages
- QueryPerformanceFrequency
	- Get resolution of Windows' high precision timer - performance measurements and timers sometimes used in sandbox detection
- RaiseException
	- Manually create an exception
- RemoveVectoredExceptionHandler
	- Remove exception handler
- SetProcessAffinityMask
	- Controls what CPU cores a process can run on
- SetThreadContext
	- Change a thead's CPU state - often used in thread hijacking, process injection, execution redirection
- SuspendThread
	- Pauses a thread
- VirtualProtect
		- Change memory permissions - can be used in unpacking, shellcode execution, memory injection
- VirtualQuery
	- Gets information about memory regions