#include <windows.h>
#include <stdio.h>

int main()
{
    char file_name[] = "test.exe";

    HANDLE fileH = CreateFileA(
        file_name,
        GENERIC_READ,
        0,
        NULL,
        OPEN_EXISTING,
        0,
        NULL);

    if (fileH == INVALID_HANDLE_VALUE)
    {
        printf("Failed to open file\n");
        return 1;
    }

    DWORD fileSize = GetFileSize(fileH, &fileSize);

    if (fileSize == INVALID_FILE_SIZE)
    {
        printf("Failed to get file size\n");
        CloseHandle(fileH);
        return 1;
    }

    printf("File size (bytes): %lu\n", fileSize);

    CloseHandle(fileH);

    return 0;
}
