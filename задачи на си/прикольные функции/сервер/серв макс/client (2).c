#include <windows.h>
#include <stdio.h>

#define BUFSIZE 256

int main()
{
HANDLE hPipe;
int buffer[256];
int buffer2[256];
int buffer3[256];
int buffer4[256];
int buffer5[225]={0};
//int buffer6[225]={0};

DWORD dwWritten, dwRead;
int a, b, c, d;
BOOL fSuccess;

hPipe = CreateFile(TEXT("\\\\.\\pipe\\Pipe"),
GENERIC_READ | GENERIC_WRITE,
0,
NULL,
OPEN_EXISTING,
0,
NULL);

if (hPipe == INVALID_HANDLE_VALUE)
{
printf("CreateFile failed, GLE=%d.\n", GetLastError());
return 0;
}

printf("Enter a numerator(a): ");
 gets(buffer);
printf("Enter a denominator(b): ");
gets(buffer2);
printf("Enter a numerator(c): ");
 gets(buffer3);
printf("Enter a denominator(f): ");
gets(buffer4);
//printf("Enter a numerator: ");
//scanf("%d", &c);
//printf("Enter a denominator: ");
//scanf("%d", &d);
//buffer3[0] = c;
//buffer4[0] = d;


WriteFile(hPipe,
buffer,
strlen(buffer),
&dwWritten,
NULL);
printf("erorr1");

WriteFile(hPipe,
buffer2,
strlen(buffer2),
&dwWritten,
NULL);
printf("erorr2");

WriteFile(hPipe,
buffer3,
strlen(buffer3),
&dwWritten,
NULL);
printf("erorr3");

WriteFile(hPipe,
buffer4,
strlen(buffer4),
&dwWritten,
NULL);




CloseHandle(hPipe);

return 0;
}