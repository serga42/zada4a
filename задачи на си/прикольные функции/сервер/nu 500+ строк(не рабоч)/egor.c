#include <windows.h>
#include <stdio.h>

#define BUFSIZE 512

int main()
{
//	int a;
HANDLE hpipe;
char   szBuf[512];
//int buffer[225]={0};
//int buffer2[225]={0};
//int buffer3[225]={0};
//int buffer4[225]={0};
DWORD vgWrite ,vgRead;


hpipe = CreateFile(TEXT("\\\\.\\pipe\\Pipe"),
GENERIC_READ | GENERIC_WRITE,
0,
NULL,
OPEN_EXISTING,
0,
NULL);

if (hpipe == INVALID_HANDLE_VALUE)
{
printf("CreateFile failed, GLE=%d.\n", GetLastError());
return 0;
}

printf("Enter a numerator: ");
//scanf("%d", &a);
gets(szBuf);

WriteFile(hpipe,
szBuf,
strlen(szBuf),
&vgWrite,
NULL);


CloseHandle(hpipe);	
return 0;
}