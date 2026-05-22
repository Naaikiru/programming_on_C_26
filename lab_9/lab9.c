#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    printf("|| calculator ||\n");
    int i, j;
    char stroka[256];
    char *vrem;

    printf("enter primer with probel: ");
    fgets(stroka, sizeof(stroka), stdin);

    vrem = strtok(stroka, " \t\n");
    
    printf("ok");
    return 0;
}