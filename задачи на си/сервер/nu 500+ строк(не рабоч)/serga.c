#include <windows.h>
#include <stdio.h>

#define BUFSIZE 512

int main()
{
	int a;
HANDLE hpipe2;
char   szBuff[512];
//int buffer[225]={0};
//int buffer2[225]={0};
//int buffer3[225]={0};
//int buffer4[225]={0};
DWORD vgWrite2 ,vgRead2;

hpipe2 = CreateFile(TEXT("\\\\.\\pipe\\Pipee"),
GENERIC_READ | GENERIC_WRITE,
0,
NULL,
OPEN_EXISTING,
0,
NULL);

if (hpipe2 == INVALID_HANDLE_VALUE)
{
printf("CreateFile failed, GLE=%d.\n", GetLastError());
return 0;
}

printf("Enter a numerator: ");
gets(szBuff);

WriteFile(hpipe2,
szBuff,
strlen(szBuff),
&vgWrite2,
NULL);

CloseHandle(hpipe2);	
return 0;
}