Source: https://crackmes.one/crackme/6a512a5e71ee08cad748dcb2
Author: #Lacks
Language: C/C++
Difficulty: 3.0
Platform: Windows
Description: This is level 4 im uploading 1 - 10 crack mes

---
## Information gathering

Launching the program:
![[Pasted image 20260731223533.png]]

Possibly useful strings from FLOSS:
floss .\level4.exe -n 10 > strings
```
Enter Username: 
Enter Serial Key (numbers only): 
Invalid input.
[+] Success! Your decrypted flag is: 
 (Gibberish!)
[-] Access Denied. Decrypted output: 
Press Enter to exit...
C:\Users\knze2\source\repos\crackmetest\x64\Release\crackmetest.pdb
```

Detect it easy results:
```
PE64
    Operation system: Windows (Vista) [AMD64, 64-bit, Console]
    Linker: Microsoft Linker (14.51.36248)
    Compiler: Microsoft Visual C/C++ (19.51.36248) [LTCG/C++]
    Language: C++
    Library: Microsoft C/C++ Runtime [dynamic]
    Tool: Microsoft Visual Studio (2026, 18.4)
    Debug data: Records [codeview, vc_feature, pogo]
    (Heur) Debug data: Contains [Absolute PDB path]
```

---
## Finding the starting point in IDA

View -> Open Subviews -> Strings:
![[Pasted image 20260801182513.png]]

Double click aEnterSerialKey then press `X` to identify cross references:
![[Pasted image 20260801182607.png]]

Then we are in, or are at least close to, the main function:
![[Pasted image 20260801182708.png]]

---

## IDA findings

These two code blocks decide whether the input is correct or not:
![[Pasted image 20260801195139.png]]

Based on the wording of this, we can assume the flag is encrypted. Encryptions usually happen in loops. The closest loop to this decision split is:
```
loc_1400014B0:
movsx   ecx, byte ptr [rax]
add     r8d, ecx
inc     rax
cmp     rax, r9
jnz     short loc_1400014B0
```

### What is happening in the assembly above?

1. Read one byte from the memory location pointed to by RAX, then put that value into ECX. `movsx` sign-extends the 8-bit value into a 32-bit value.
2. The value of ECX is added to R8D. The existing value of `r8d` is preserved and accumulated.
3. The value inside RAX is incremented, moving the pointer to the next byte.
4. `cmp` performs a subtraction internally (`RAX - R9`) and updates the CPU flags without storing the result. `jnz` checks the Zero Flag (ZF). If ZF is not set, meaning RAX != R9, execution jumps back to the start of the loop.

So with that information we need to answer some questions:

Before the loop...
-  ...what value is stored inside RAX?
- ...what value is inside R8D before the loop?
- ...what value is stored inside R9?

And also...
- What does the program do with R8D after the loop?

To answer those questions we need to trace back the assembly
### ...what value is stored inside RAX?

All opcodes involving RAX before the loop:
```
mov     rax, cs:__security_cookie
xor     rax, rsp
lea     rax, [rbp+Block]
nop     dword ptr [rax+00h]
nop     dword ptr [rax+rax+00000000h]
```
The earlier RAX operations are compiler-generated stack protection. The relevant assignment is `lea rax,[rbp+Block]`, which gives RAX the address of the string object/local buffer.

While trying to identify what was stored inside RAX, I noticed the value in RAX is compared against R9 before the loop is reached. If this is not true it will bypass the loop entirely:
```
loc_14000149F:
cmp     rax, r9
jz      short loc_1400014BE
```

Following in x64dbg:
```
00007FF6B30E14B0 | 0FBE08                   | movsx ecx,byte ptr ds:[rax]       
00007FF6B30E14B3 | 44:03C1                  | add r8d,ecx                       
00007FF6B30E14B6 | 48:FFC0                  | inc rax                           
00007FF6B30E14B9 | 49:3BC1                  | cmp rax,r9                        
00007FF6B30E14BC | 75 F2                    | jne level4.7FF6B30E14B0
```

RAX = 1234

### ...what value is stored inside R8D?

All opcodes involving R8D before the loop:
```
xor     r8d, r8d
```
Simply put, R8D is zero.

### ...what value is stored inside R9?

All opcodes involving R9 before the loop:
```
mov     r9, [rbp+var_18]
add     r9, rdx
```

R9 is directly affected by variable 18 and RDX

What is var_18 before it is added to R9?
```
var_18= qword ptr -18h
mov     [rbp+var_18], 0
```

What is RDX before it is added to R9?
```
lea     rdx, asc_1400043D8 ; "=============================\n"
lea     rdx, aCrackmeLevel4 ; "       CRACKME LEVEL 4       \n"
lea     rdx, asc_140004418 ; "=============================\n\n"
lea     rdx, aEnterUsername ; "Enter Username: "
lea     rdx, [rbp+Block]
lea     rdx, aEnterSerialKey ; "Enter Serial Key (numbers only): "
lea     rdx, [rbp+var_50]
lea     rdx, [rbp+Block]
mov     rdx, r9
sub     rdx, rax
cmova   rdx, rcx
cmova   rdx, rdi
```

in x64dbg inside the loop 
r9=0000007DEC4FF91C
### What does the program do with R8D after the loop?

```
imul    r12d, r8d, 7Bh ; '{'
```
R8D is multiplied with 0x7B (123 in decimal) and stored in R12D.

---

I have identified from x64dbg that this loop is actually iterating through the username

This second loop iterates over the serial key to ensure it matches. 
![[Pasted image 20260802151823.png]]

It iterates over the memory address of RBX and compares it against the memory address stored in R14. If they are the same, it exits the loop.

When that loop exits the value at RBP-50 is moved into EAX
```
00007FF6B30E1547 | 8B45 B0                  | mov eax,dword ptr ss:[rbp-50]     
```
At that point the value is:
```
000000B04D3CF800  D2 04 00 00 00 00 00 00 D2 EE 00 00 00 00 00 00
```
Which in little endian format (because we are looking at the bytes in memory) is 0x04D2, or 1234 in decimal. Our input serial number:
![[Pasted image 20260802152514.png]]

Then EAX is compared against R12D
```
00007FF6B30E1551 | 41:3BC4                  | cmp eax,r12d                      
```
R12D at this point is `D740`, which is 55104 in decimal.

---

We know from earlier in the program that the username is processed byte-by-byte in the first loop. Each byte is added to `R8D`, making `R8D` the sum of the username's character values. After the loop, `R8D` is multiplied by `0x7B` (123 decimal) and stored in `R12D`.

The entered serial key is then loaded into `EAX`:

```
mov eax,dword ptr [rbp-50]
```

and compared against `R12D`:

```
cmp eax,r12d
```

Therefore, `R12D` represents the expected serial value generated from the username. The program succeeds only when the user-provided serial (`EAX`) matches this calculated value.

---

So basically the username is used in a calculation to match the value of the serial key. If this value does not match the serial key, and the serial key is not correct, the program will fail.

We know the serial key is 55104 so we just need the sum of the username to add up to 55104 to retrieve the flag. To work this out we can divide 55104 by 123, which gives us 448. Then we need to figure out what combination of ASCII characters gives us 448. `BBBBBB4` works here.

B + B + B + B + B + B + 4 is the same as 66 + 66 + 66 + 66 + 66 + 66 + 52 which is equal to 448
448 * 123 = 55104

![[Pasted image 20260802154653.png]]

---

Reconstructing the code would look something like this:

``` C
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
```

![[Pasted image 20260802163851.png]]

