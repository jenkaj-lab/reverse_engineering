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

!!! TODO: follow RDX in x64dbg
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

!!! TODO: follow RDX in x64dbg
### What does the program do with R8D after the loop?

```
imul    r12d, r8d, 7Bh ; '{'
```
R8D is multiplied with 0x7B (123 in decimal) and stored in R12D.

---

Notes:

ASM flow:
```
r8d = 0

for each byte:
    r8d += byte

r12d = r8d * 123
```

Pseudocode:
```
Input:
    Username

Algorithm:
    sum = 0

    for each character:
        sum += character_value

    expected_serial = sum * 123
```
```