Author: #RodrigoTeixeira
Source: https://crackmes.one/crackme/6a539361a27dfa335e4c851d
Language: C/C++
Platform: Windows
Difficulty: 2.0
Description: This crackme was made just to explore the possibilities of encrypting text and recovering in runtime. It's not too hard

---

# Investigation Notes

## Strings
Gather strings with FLOSS (min length 10)
```
PS C:\Users\jenkaj\Downloads\6a539361a27dfa335e4c851d> floss -n 10 .\crackmes.exe > strings
```

```
__imp__scanf

Enter the password: 
Password\0
Wrong password
That is correct :)

Enter the password: 
Password\0
Wrong password
```

Can probably safely assume scanf is used to read user input

## IDA
There is a call to scanf
![[Pasted image 20260726213630.png]]

But I can also see there is an argc and argv
![[Pasted image 20260726213705.png]]

so this might expect some values from the terminal

## Powershell
Not much to gather here except proof that user input is required
![[Pasted image 20260726213945.png]]

## IDA
I notice a loop occurs before the user is asked for input
![[Pasted image 20260726214207.png]]

I'm not sure how much of this is relevant to the parts of the program I'm interested in so I'm going to take a look in x64dbg

## x32dbg
x64dbg actually terminated and asked me to use x32dbg to debug this file

First step is run to user code and analyse the symbols for this sample

There are some potentially interesting imports to look at here
![[Pasted image 20260726215708.png]]

right now I think the most valuable one is scanf so I'll put a breakpoint on that

then I step through the code with F9 until I hit my breakpoint
![[Pasted image 20260726215845.png]]

and use the call stack to take me to the start of the user code
![[Pasted image 20260726215926.png]]

This hasnt given me an awful lot to work with, the only thing that stands out to me is "sword: "
![[Pasted image 20260726220253.png]]

so I decided to press Ctrl + F9 to execute until return, entering "test" as the password when prompted, which has been stored in EBX
![[Pasted image 20260726221001.png]]

I actually noticed when stepping through with F8 that there were a couple of areas that were looping like below
![[Pasted image 20260726221314.png]]

the program exited shortly after that so I assume that's the wrong password, but I want to try and see what values are being stored in the registers in those loops

I retrace my steps and get to the point where it loops
![[Pasted image 20260726221525.png]]

to try and understand what's going on here I'm gonna make a table to define these opcodes

| opcode | definition                                                                                                              |
| ------ | ----------------------------------------------------------------------------------------------------------------------- |
| or     | Bitwise inclusive OR operation<br>If either of the bits are 1 the result is 1, otherwise the result is 0                |
| add    | Adds the source operand to the destination operand                                                                      |
| imul   | A signed integer multiplication                                                                                         |
| mov    | Copy the source operand to the destination operand                                                                      |
| movzx  | Move with Zero-Extend - moves a smaller source operand to a larger destination operand and fills the upper bits with 0s |
| test   | Performs a bitwise logical AND operations<br>It sets the zero flag to 1 if the AND result is zero, and 0 otherwise      |
| jne    | Jump if not equal - a conditional jump comparing the source and destination operand                                     |
or eax, 1: EAX was 50, this became 51
EDX became 60FE7A
ECX is currently 11
Multiplying EAX by ECX makes EAX 561
Not sure what happens when the lower bits of EAX get copied to the address of EDX
ECX becomes 53
53 in decimal is 83

Because the lower bits of ECX are being tested I'll try and reconstruct the hex

Hex: 53,01,ED,C9,AE,0C,2C,F0,00

When I reached the end of the hex calculation I noticed it was 0, and the jump if not equal condition was not reached. I know that the end of a string is always 00, so this was likely looping and testing to see if the end of the string was reached before continuing

The same thing happens here but with EBX instead of ECX so I repeat the process
![[Pasted image 20260726223608.png]]

Hex: 15,72,89,E0,70,F1,53,01,ED,C9,AE,0C,00

At this point EDX already has "wrong password" in it, so there's definitely some validation happening here

The hex to ASCII conversion is gibberish so I need to figure out what's going on here

I run it again and set some breakpoints on the loops

EAX is 50 again, which becomes 51
EDX is 60FE79, which becomes 60FE7A
ECX is 11, ECX * EAX makes EAX 561
ECX becomes 53

There is no randomness here, it is the same very time

I look at the address of EDX, which is what's giving ECX its value and see
![[Pasted image 20260726225140.png]]

I notice only AL is written into [EDX] during the loop. Since AL is the lower byte (8 bits) of EAX and two hexadecimal characters make up a byte maybe we can use this to figure out what EDX before it gets encrypted

Hex: 50,61,73,73,77,6F,72,64,5C,30
ASCII: Password\0

![[Pasted image 20260726225953.png]]

Not quite right...

There's another loop that seems to compare DL to CL
![[Pasted image 20260726230634.png]]
![[Pasted image 20260726230649.png]]

That iterates through the characters in my string

![[Pasted image 20260726230757.png]]

but then it looks like I missed a backslash

Before I get into that lets figure out what the second loop does

Hex: 57,72,6F,6E,67,20,70,61,73,73,77,6F,72,64
ASCII: Wrong password

Right.. so the second loop is just spelling out wrong password and the first loops is the encryption.

I went back and re watched the loop, substituting missing characters and it spelled out `Password\0` which finally gave me the correct flag
![[Pasted image 20260726231634.png]]

so based on what we observed this is likely what the program looks like in C
![[Pasted image 20260726233117.png]]

I'm basing this on the following observations
- No evidence of strcpy imports
- Multiple references to %99s - leading me to believe the input string is 100 characters with one reserved for the terminating `\0`

This program isnt finished because it doesn't do any encryption yet, but I'm going to leave it there for today.