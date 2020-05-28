# Sling

Backdoor/Malware test in C. Uses two segments - Backdoor and Server; Backdoor works on windows machines and Server on Linux. No masking yet.
___
### Components 

#### Backdoor.c
The backdoor file is the one that will be deplyed on the Windows machine. 
The code is written in C; and it should be Compiled  using the following command on a Linux machine to have a 32bit application 
which can be deployed on Windows systems.

```bash
i686-w64-mingw32-gcc -o test.exe filename.c 
```
---

#### Server.c
The Server.c file stays on the attacking system to execute commands remotely. The attacking computer must be Linux Machine. Debian ##### based Operating System. Compile normaly as you would using gcc,
___

#### PreFab Files 
Pre Fab folder contains pre made/compiled executable file of the backdoor component of the Malware and the pre compiled file of Server component of the Malware.
Download and run 
