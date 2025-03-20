#include <stdio.h>
#include <windows.h>

HANDLE hevent;//дискриптер  события

DWORD WINAPI MyThreadfap1(LPVOID p){//1 поток дрочьки
	WaitForSingleObject(hevent,INFINITE);
	printf("Thead1");
	getchar();
	return 0;
}

DWORD WINAPI MyThreadfap2(LPVOID p){//2 поток дрочьки
	printf("Thead2");
	SetEvent(hevent);
	return 0;
} 





int main(){
	;
	
HANDLE hThead1,hThead2;
DWORD Theadid1,Theadid2;

hevent=CreateEvent(NULL,FALSE,FALSE,"sbp");//если глобальная переменая(hevent) равна 1 сигнал  запускаеться если 0 выводит ошибку

if(NULL==hevent){printf("CreateEvent fun failed & error no->%d", GetLastError());}
printf("CreateEvent FUN SUCCESS\n");



hThead1=CreateThread(NULL, 0, MyThreadfap1, (LPVOID) &Theadid1, 0, NULL); //если глобальная перееная равна 0 ошибка если равна 1 запуск
if(hThead1==NULL){printf("Thead1 creation failed & error no ->%d", GetLastError());}

hThead2=CreateThread(NULL, 0, MyThreadfap2, (LPVOID) &Theadid2, 0, NULL);
if(hThead2==NULL){printf("Thead2 creation failed & error no ->%d", GetLastError());}




WaitForSingleObject(hThead1, INFINITE);
WaitForSingleObject(hThead2, INFINITE);


CloseHandle(hThead1);//выход из 1 потока
CloseHandle(hThead2);//выход из 2 потока


CloseHandle(hevent);//выход из сигнала и само завершение его после выхода





system("PAUSE");
return 0;
}