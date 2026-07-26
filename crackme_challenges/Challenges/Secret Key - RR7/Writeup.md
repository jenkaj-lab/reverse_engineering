Author: RR7
Sample: https://crackmes.one/crackme/6a46f20c8a86e4c2c5525631

---

Fairly easy challenge. Disassembling the file in IDA gives the answer straight away:

![[Pasted image 20260726171247.png]]

Two scanf functions, both of which are using the `%i` format specifier used to receive decimal, octal or hexadecimal input. During each function call the user input is stored in its respective variable, then moved into EAX and compared against a hexadecimal value. In theory, reconstructing the code in C would look something like this:

![[Pasted image 20260726174154.png]]

The comparison constant in IDA is showing a hex value, so that's what I've written in code. Input will be decimal so convert the values and then enter the values:

| Comparand | Hex Value | Decimal Value |
| --------- | --------- | ------------- |
| 21h       | 21        | 33            |
| 66h       | 66        | 102           |

![[Pasted image 20260726174314.png]]

That code probably doesn't look exactly how the developer's code did, but it will have the same outcome. This can be proven using x64dbg with the following steps:

- Run to user code (Alt + F9)
- Look at the symbols for code.exe (the challenge file)
![[Pasted image 20260726174857.png]]
- Toggle a breakpoint on scanf
- Press F9 to run the code until we hit the breakpoint on scanf
- Look at the call stack
![[Pasted image 20260726180533.png]]
- Double click on the user code with the highest memory value (ending in 4CC in this case). This looks more like the IDA findings
![[Pasted image 20260726181352.png]]
- Set some breakpoints at the beginning of the call code, on the comparison operators, and on the congratulations statement
![[Pasted image 20260726181625.png]]
- Now to test this both ways I used the value 56 when asked to enter a number and the instruction pointer stopped at the comparison breakpoint. In the next screenshot the RAX register holds 0x38 (56 decimal) and is being compared against 0x21
![[Pasted image 20260726182204.png]]
- This made the instruction pointer follow the JNE condition, because the comparison wasn't true
![[Pasted image 20260726182344.png]]
- If I do the same thing with the correct value; entering 33 into the terminal window the RAX register holds 0x21 and compares it against 0x21
![[Pasted image 20260726182551.png]]
- The zero flag is set to 1, skipping the jump condition, and asking for the secret key
![[Pasted image 20260726182653.png]]
- Continue with the steps above for the secret key and the program prints the congratulations message
![[Pasted image 20260726182957.png]]