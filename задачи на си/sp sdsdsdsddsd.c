#include <stdio.h>
#include <windows.h>						
struct Tl	{
	unsigned uiBlock;
	unsigned uiStatus; 
	unsigned int maxCount;
	unsigned int prevDigit;
	unsigned int currDigit;
	unsigned int count;
	unsigned int N;
};
DWORD WINAPI MyThread(LPVOID p)
{
	struct Tl *pRec;
	pRec = (struct Tl*)p;
	
	unsigned int prevDigit1, maxCount1 = 0, currDigit1, N1, count1;
	while(1)
	{
		while (pRec->uiBlock == 1); 
		{
int prevDigit = N1 % 10;
N1 /= 10;
int count1 = 0;
int maxCount1 = 0;

while (N1 > 0) {
int currDigit1 = N1 % 10;
if (currDigit1 > prevDigit1) {
count1++;
if (count1 > maxCount1) {
maxCount1 = count1;
}
} else {
count1 = 0;
}
prevDigit1 = currDigit1;
N1 /= 10;

}
maxCount1++;
printf("Наибольшее количество цифр, идущих от большего к меньшему: %d\n", maxCount1);
		}
		pRec->uiBlock=1;

	}
	return 0;
}

int main(int argc, char** argv) 
{
	struct Tl Rec = {1,2,0,0,0,0,0}; 
	unsigned g = 1;
	
	CreateThread(NULL, 0, MyThread, (LPVOID) &Rec, 0, NULL);
while(g)
{
	switch (Rec.uiStatus)
	{
		case 2:
			Sleep(1);
			printf("Введите число N: ");
			scanf("%d", &Rec.N);
		    Rec.uiBlock = 0;
		    Sleep(1);
		    ExitProcess(0);
		break;
	}
}
		
	ExitProcess(0);
}