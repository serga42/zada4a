#include <windows.h>
#include <stdio.h>

#define BUFSIZE 512

int main()
{
	int a;
HANDLE hpipe3;
HANDLE hpipe2;
HANDLE hpipe;
char szBuf[256];
char szBuf2[256];
char szBuf3[256];
//int buffer[225]={0};
//int buffer2[225]={0};
//int buffer3[225]={0};
//int buffer4[225]={0};
DWORD vgWrite3 ,vgRead3;
DWORD vgWrite2 ,vgRead2;
DWORD vgWrite ,vgRead;

hpipe3 = CreateFile(TEXT("\\\\.\\pipe\\Pipeee"),
GENERIC_READ | GENERIC_WRITE,
0,
NULL,
OPEN_EXISTING,
0,
NULL);

printf("\t\t\tMRBEAST\n");

if (hpipe3 == INVALID_HANDLE_VALUE)
{
printf("CreateFile failed, GLE=%d.\n", GetLastError());
return 0;
}

while(1)
{
	if(ReadFile(hpipe3, szBuf, 512, &vgRead3, NULL))//получение сообщений от egora
    printf("egor:%s\n", szBuf);
    
	if(ReadFile(hpipe3, szBuf2, 512, &vgRead3, NULL))//получение сообщений от serga
    printf("egor:%s\n", szBuf2);
    
	printf("enter a message:");
	scanf("%s", &szBuf3);
	
	if(!WriteFile(hpipe3, szBuf3, strlen(szBuf3) + 1,
	&vgWrite3, NULL))
    break;
    
}
CloseHandle(hpipe3);	
return 0;
}