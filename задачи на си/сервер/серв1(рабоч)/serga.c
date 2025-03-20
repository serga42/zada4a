#include <windows.h>
#include <stdio.h>

#define BUFSIZE 512

int main()
{
	int a;
HANDLE hpipe;
HANDLE hpipe2;
char szBuf[256];
char szBuf2[256];
char szBuf3[256];
//int buffer[225]={0};
//int buffer2[225]={0};
//int buffer3[225]={0};
//int buffer4[225]={0};
DWORD vgWrite ,vgRead;
DWORD vgWrite2 ,vgRead2;

hpipe2 = CreateFile(TEXT("\\\\.\\pipe\\Pipee"),
GENERIC_READ | GENERIC_WRITE,
0,
NULL,
OPEN_EXISTING,
0,
NULL);

printf("\t\t\tSERGA\n");

if (hpipe2 == INVALID_HANDLE_VALUE)
{
printf("CreateFile failed, GLE=%d.\n", GetLastError());
return 0;
}
while(1)
{
	if(ReadFile(hpipe2, szBuf, 512, &vgRead2, NULL))//получение сообщения от egora
    printf("MrBeast:%s\n", szBuf);
    
    if(ReadFile(hpipe2, szBuf3, 512, &vgRead2, NULL))//получение сообщения от MrBeast
    printf("egor%s\n", szBuf3);
    
	printf("enter a message:");
	scanf("%s", &szBuf2);
	
	if(WriteFile(hpipe2, szBuf2, strlen(szBuf2) + 1,
	&vgWrite2, NULL))
	CloseHandle(hpipe2);
}
CloseHandle(hpipe2);	
return 0;
}