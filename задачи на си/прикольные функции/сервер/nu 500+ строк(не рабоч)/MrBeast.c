#include <windows.h>
#include <stdio.h>

#define BUFSIZE 512

int main()
{
	int a;
HANDLE hpipe3;
char   szBufff[512];
//int buffer[225]={0};
//int buffer2[225]={0};
//int buffer3[225]={0};
//int buffer4[225]={0};
DWORD vgWrite3 ,vgRead3;


hpipe3 = CreateFile(TEXT("\\\\.\\pipe\\Pipeee"),
GENERIC_READ | GENERIC_WRITE,
0,
NULL,
OPEN_EXISTING,
0,
NULL);

if (hpipe3 == INVALID_HANDLE_VALUE)
{
printf("CreateFile failed, GLE=%d.\n", GetLastError());
return 0;
}

printf("Enter a numerator: ");
gets(szBuf3);

WriteFile(hpipe3,
szBufff,
strlen(szBufff),
&vgWrite3,
NULL);

CloseHandle(hpipe3);	
return 0;
}