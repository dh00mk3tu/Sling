# Sling

Backdoor/Malware test in C. Uses two segments - Backdoor and Server; Backdoor works on windows machines and Server on Linux. No masking yet.
___
### Components 

#### Backdoor.c
The backdoor file is the one that will be deplyed on the Windows machine. 
The code is written in C; and it can compiled on a Linux machine to have a 32bit application which can be deployed on Windows systems.

#### Server.c
The Server.c file stays on the attacking system to execute commands remotely. The attacking computer must be Linux Machine. Debian based Operating System. Compile normaly as you would using gcc,
___

#### PreFab Files 
Pre Fab folder contains pre made/compiled executable file of the backdoor component of the Malware and the pre compiled file of Server component of the Malware.
Download and run 
___

## How To Set it up 
There are two ways you can set up Sling to perform an attack on a system.
Note: Change the IP address in the source code to your own else it will not work.
#### Method 1
The first method is that you compile your own binary of the backdoor.c & compile the server.s from the source code.
For this you will need a Linux Machine. 
##### Step 1
Clone the repo on your system to an accessible directory location.
##### Step 2
Open the terminal and;
Compile the server.c file using the command
```bash
gcc server.c -o server 
```
---
##### Step 3
Now, in the same terminal window;
Compile a binary file of backdoor.c using the following command 
```bash
i686-w64-mingw32-gcc -o test.exe filename.c 
```
---

You will now have two files;
1. server file 
2. backdoor binary file.

The binary file will be executed on the windows machine.
The server file will be executed on Linux system.
___

#### Method 2
The second method is pretty straight forward and simple. It is recommended for most users and specifically for users who do not have any/ready access to Linux.
You will download a pre compiled version of the Malware; compiled by me.
Note: I update the prefab files rather frequently so they could be a version or two behind from the source. But it'll work as long as the server and the backdoor are of the same version. 
 	
Download the precompiled version of Sling from the link below 
[Pre-Fab](https://github.com/dh00mk3tu/Sling/tree/master/PreFabs")

___

## How-To Use
Once you have the backdoor executable and the server file setup; follow the steps for sucessful execution. 

#### Step - 1
Deploy the backdoor executable on the Target/test windows machine via email, USB Flash Drive etc. adn wait for the user to click on it. 

#### Step - 2 
On the Linux Machine; switch to the active directory of the server file run it using the following command 
```bash
./server
```
#### Step - 3 
Upon clicking the binary file on the Windows machine, a system message will be displayed to the user.
While on the Linux Machine it will show you the IP address of the connected Windows machine. 

From here on, you have established connection with the Target computer. 
You can run all the basic cmd commands like cd, dir and netstat etc.
___
### Custom Shell Commands 
The Malware currently supports two commands, as follows;

##### Once the connection has been established - first thing to do is to run the command 
```bash
persist 
```
This will create persistence in the Windows Registry for the Malware to reconnect to the server.

##### The second command is;
```bash
keylog_start 
```
This will start the keylogger on the target system.

##### The last command is 
```bash
type windows.txt
```
This command will show you the keystrokes captured by the keylogger 
