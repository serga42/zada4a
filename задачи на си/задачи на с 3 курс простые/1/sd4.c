#include <stdio.h>
int globalValue = 10;
void ds()
{
    printf("global fynchon = %d\n", globalValue);
}
int main()
{
    ds();
    int localValue = 5;
    printf("global = %d\n", globalValue);
    printf("local = %d\n", localValue);
    getchar();
    return 0;
}