#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int sum = 0;
    char username[100];
    char actual_serial_key[] = "55104";
    char user_serial_key[100];
    printf("Enter Username: ");
    scanf("%99s", username);
    printf("Enter Serial Key (numbers only): ");
    scanf("%99s", user_serial_key);

    for (int i = 0; i < strlen(username); i++)
    {
        sum += username[i];
    }

    sum = sum*123;

    if (strcmp(user_serial_key, actual_serial_key) == 0 && sum == 55104)
    {
       printf("[+] Success! Your decrypted flag is: ");

        char encrypted_flag[] = {0x34, 0x08, 0x0B, 0x11, 0x02, 0x03, 0x46, 0x00};

        char key = atoi(user_serial_key) ^ 0x34;

        for (int i = 0; i < sizeof(encrypted_flag) - 1; i++)
        {
            encrypted_flag[i] ^= key;
        }

        printf("%s\n", encrypted_flag);
    }
    else
    {
        printf("[-] Access Denied. Decrypted output: %d\n", sum);
    }
}