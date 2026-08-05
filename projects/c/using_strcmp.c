/*
Write a C program that implements a simple password verification system using the strcmp() function. Your program should:

1. Read an integer n representing the number of login attempts to process
2. For each login attempt:
    - Read a username from input
    - Read a password from input
    - Use strcmp() to compare the username with "admin"
    - Use strcmp() to compare the password with "secret123"
    - Print the appropriate message based on the comparison results
3. After processing all attempts, count and display how many successful logins occurred

The login validation logic should be:
    - If both username and password are correct: print "Login successful"
    - If username is correct but password is wrong: print "Invalid password"
    - If username is wrong but password is correct: print "Invalid username"
    - If both username and password are wrong: print "Invalid credentials"

Remember to include the <string.h> header to use the strcmp() function.

Your output should display the results in the following format:
[Login result message]
[Login result message]
...
Total successful logins: [count]

For example, if the input is:
4
admin
secret123
user
password
admin
wrong
guest
secret123

Your output should be:
Login successful
Invalid credentials
Invalid password
Invalid username
Total successful logins: 1

This challenge tests your understanding of using strcmp() to compare strings for equality, implementing conditional logic based on string comparison results, and counting occurrences based on comparison outcomes.
*/

#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    
    char username[100];
    char password[100];
    int successful_logins = 0;
    
    // Process each login attempt using strcmp() function
    for (int i = 0; i < n; i++) {
        scanf("%99s",username);
        scanf("%99s",password);

        if (strcmp(username,"admin") == 0 && strcmp(password,"secret123") == 0) {
            printf("Login successful\n");
            successful_logins++;
        } else if (strcmp(username,"admin") == 0 && strcmp(password,"secret123") != 0) {
            printf("Invalid password\n");
        } else if (strcmp(username,"admin") != 0 && strcmp(password,"secret123") == 0) {
            printf("Invalid username\n");
        } else {
            printf("Invalid credentials\n");
        }
    }
    
    printf("Total successful logins: %d\n", successful_logins);
    
    return 0;
}
