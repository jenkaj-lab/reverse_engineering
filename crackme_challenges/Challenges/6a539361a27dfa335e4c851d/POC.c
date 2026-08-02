#include <stdio.h>

int main()
{
    char password[10] = "Password\n";
    char input[100];
    printf("Enter the password: ");
    scanf("%99s", input);

    for (int i = 0; i < 10; i++)
    {
        if (input[i] != password[i])
        {
            printf("Wrong password\n");
        }
        else
        {
            printf("That is correct :)\n");
        }

        return 0;
    }
}