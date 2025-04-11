#include <windows.h>
#include <stdio.h>
#include <tchar.h>

#define BUFSIZE 256

int main()
{
HANDLE hPipe;
int buffer[256]={0};
int buffer2[256]={0};
int buffer3[225]={0};
int buffer4[225]={0};
int buffer5[225]={0};
//int buffer6[225]={0};
char a, b, c, d;
int e, f;
BOOL fSuccess;
DWORD dwRead, dwWritten;

hPipe = CreateNamedPipe(TEXT("\\\\.\\pipe\\Pipe"),
PIPE_ACCESS_DUPLEX,
PIPE_TYPE_BYTE | PIPE_READMODE_BYTE | PIPE_WAIT,
1,
BUFSIZE,
BUFSIZE,
NMPWAIT_USE_DEFAULT_WAIT,
NULL);

if (hPipe == INVALID_HANDLE_VALUE)
{
printf("CreateNamedPipe failed, GLE=%d.\n", GetLastError());
return -1;
}


printf("Waiting for client connection...\n");

if (!ConnectNamedPipe(hPipe, NULL))
{
printf("ConnectNamedPipe failed, GLE=%d.\n", GetLastError());
return 0;
}

printf("rtrett\n");
printf("Client connected, reading request...\n");
ReadFile(hPipe, buffer, BUFSIZE, &dwRead, NULL);
ReadFile(hPipe, buffer2, BUFSIZE, &dwRead, NULL);
ReadFile(hPipe, buffer3, BUFSIZE, &dwRead, NULL);
ReadFile(hPipe, buffer4, BUFSIZE, &dwRead, NULL);

//ReadFile(hPipe, buffer3, BUFSIZE, &dwRead, NULL);
//ReadFile(hPipe, buffer4, BUFSIZE, &dwRead, NULL);
printf("3)%s + %s\n", buffer, buffer2);
printf("3.1)%s + %s\n", buffer3, buffer4);
a = buffer;
b = buffer2;
c = buffer3;
d = buffer4; 

printf("%d %d %d %d\n", a, b, c, d);
e = a + b;
f = b * d;
printf("%d/%d", e, f);
//buffer5 = buffer + buffer2 + buffer3 +buffer4;
//e = buffer[0] * buffer4[0] + buffer3[0] * buffer2[0];
//f = buffer2[0] * buffer4[0];

//WriteFile(hPipe, buffer6, strlen(buffer6), &drWritten, NULL);

system ("pause");


CloseHandle(hPipe);

return 0;
}