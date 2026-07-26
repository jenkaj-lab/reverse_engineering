Author: RR7
Sample: https://crackmes.one/crackme/6a46f20c8a86e4c2c5525631

---

Fairly easy challenge. Disassembling the file in IDA gives the answer straight away:

![[Pasted image 20260726171247.png]]

Two scanf functions, both of which are using the %i format specifier used to receive decimal, octal and hexadecimal input. After each function call the return value is stored in eax and compared against a hexadecimal value - in theory, reconstructing the code in C would look something like this:

![[Pasted image 20260726173008.png]]

The only thing to remember is the challenge will be accepting hexadecimal, whereas the input we give is decimal so we need to convert the values:


| Comparand | Hex Value | Decimal Value |
| --------- | --------- | ------------- |
| 21h       | 21        | 33            |
| 66h       | 66        | 102           |
