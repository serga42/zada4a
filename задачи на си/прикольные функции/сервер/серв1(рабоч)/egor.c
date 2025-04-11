#include <windows.h>
#include <stdio.h>

#define BUFSIZE 512

int main()
{
//	int a;
HANDLE hpipe;
char szBuf[256];
char szBuf2[256];
char szBuf3[256];
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
printf("\t\t\tEGOR\n");
if (hpipe == INVALID_HANDLE_VALUE)
{
printf("CreateFile failed, GLE=%d.\n", GetLastError());
return 0;
}
printf("Connected\n");
while(1)
{
	if(ReadFile(hpipe, szBuf2, 512, &vgRead, NULL))//получение сообщения от serga
    printf("serga:%s\n", szBuf2);
    
    if(ReadFile(hpipe, szBuf3, 512, &vgRead, NULL))//получение сообщения от MrBeast
    printf("MrBeast:%s\n", szBuf3);
	
	printf("enter a message:");
	scanf("%s", &szBuf);
	
	if(!WriteFile(hpipe, szBuf, strlen(szBuf) + 1,
	&vgWrite, NULL))
    break;
    
}



CloseHandle(hpipe);	
return 0;
}