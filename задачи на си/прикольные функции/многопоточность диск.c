#include <windows.h>
#include <stdio.h>
#include <math.h>
//считает дискреминант

struct TStruct
{
unsigned uiBlock;
unsigned uiStatus;
double Da0, Da1, Da2, Dx1, Dx2;
};

DWORD WINAPI MyThread (LPVOID p)
{
struct TStruct *pRec;
double D;
pRec=(struct pRec*)p;
while(1)
{
while(pRec->uiBlock == 1);
printf("dsdssd\n");
D = pRec->Da1*pRec->Da1-4*pRec->Da0*pRec->Da2;
if(D < 0) pRec->uiStatus=0;
else
{
pRec->uiStatus = 1;
pRec->Dx1==(pRec->Da1+sqrt(D))/(2*pRec->Da2);
pRec->Dx1==(pRec->Da1+sqrt(D))/(2*pRec->Da2);
}
pRec->uiBlock=1;
}
return 0;
}

int main ()
{
struct TStruct Rec = {1, 2, 0, 0, 0, 0, 0};
unsigned punkt1 = 1;

CreateThread (NULL, 0, MyThread, (LPVOID) &Rec, 0, NULL);
while (punkt1)
{
while (Rec.uiBlock == 0);
switch (Rec.uiStatus)
{
case 2:
scanf("%if%if%if", &Rec.Da0, &Rec.Da1, &Rec.Da2);
Rec.uiBlock = 0;
break;
default:

if(Rec.uiStatus == 0)printf("There are no roots\n");
else printf("%g %g", Rec.Dx1, Rec.Dx2);
scanf("%d", &punkt1);
Rec.uiStatus = 2;
}
}
ExitProcess(0);
return 0;
}