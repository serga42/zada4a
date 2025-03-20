#include <stdio.h>
#include <windows.h>

struct jk
{ //создание структуры
	HANDLE DisBlock;
	unsigned int x1;
	int a;
	int b;
	int c;
	double D;
	double x;

};

//HANDLE DisBlock;
HANDLE event, event2, event3, event4;
//int a, b, c;
//double D;
//double x;

DWORD WINAPI MyThreadfap1(LPVOID p)//ввод даных
{
	struct jk* pRec;
	pRec = (struct jk*)p;

	//	int s = 0;
	//	while(s!=1)
	//	{
	SetEvent(event);
	//	}
	return 0;
}



DWORD WINAPI MyThreadfap2(LPVOID p)//D
{
	struct jk* pRec;
	pRec = (struct jk*)p;
	int D1 = pRec->D;
	printf("potok2(1)\n");
	WaitForSingleObject(event, INFINITE);
	printf("potok2(2)\n");
	// while(pRec->c != 0)
 //	{
	printf("potok2(3)\n");
	pRec->D = pRec->b * pRec->b - 4 * pRec->a * pRec->c;
	printf("potok2(4)\n");
	printf("fd%d\n", pRec->D);
	printf("potok2(5)\n");
	return 0;
	//	}
	printf("potok2(6)\n");
	//WaitForSingleObject(event2,INFINITE);
	SetEvent(event2);
	return 0;
}







DWORD WINAPI MyThreadfap3(LPVOID p)//x1-x2
{
	WaitForSingleObject(event2, INFINITE);
	//	SetEvent(event2);
	printf("fdfgdfgdfg");
}

DWORD WINAPI MyThreadfap5(LPVOID p)//выввод
{
	//	WaitForSingleObject(event,INFINITE);
}





int main() {
	struct jk Rec = { 1,0,0,0,0,0,0 };
	printf("enter nembers descremenants\n");
	printf("A:");
	scanf("%d", &Rec.a);

	printf("B:");
	scanf("%d", &Rec.b);

	printf("C:");
	scanf("%d", &Rec.c);

	HANDLE hevent1, hevent2, hevent3;
	DWORD Theadid1, Theadid2, Theadid3;

	event = CreateEvent(NULL, FALSE, FALSE, "sbp");
	event2 = CreateEvent(NULL, FALSE, FALSE, "sbp2");
	event3 = CreateEvent(NULL, FALSE, FALSE, "sbp3");

	hevent1 = CreateThread(NULL, 0, MyThreadfap1, (LPVOID)&Theadid1, 0, NULL);
	hevent2 = CreateThread(NULL, 0, MyThreadfap2, (LPVOID)&Theadid2, 0, NULL);
	hevent3 = CreateThread(NULL, 0, MyThreadfap3, (LPVOID)&Theadid3, 0, NULL);

	printf("funcsi(1)\n");


	WaitForSingleObject(hevent1, INFINITE);
	WaitForSingleObject(hevent2, INFINITE);
	WaitForSingleObject(hevent3, INFINITE);

	CloseHandle(event);
	CloseHandle(event2);
	CloseHandle(event3);
	CloseHandle(event4);




	CloseHandle(event);
	return 0;
}