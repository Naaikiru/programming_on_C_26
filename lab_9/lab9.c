#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    printf("|| calculator ||\n");

    int i;
    int frst = 1;
    int minus = 0;
    double res = 0.0;
    double vrem;
    char vremop = '=';
    char stroka[256];
    char *token;
    char *prop;

    printf("enter primer with probel: ");
    fgets(stroka, sizeof(stroka), stdin);

    token = strtok(stroka, " \t\n");
    
    
    return 0;
}