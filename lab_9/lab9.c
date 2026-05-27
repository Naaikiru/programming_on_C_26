#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    printf("|| calculator ||\n");
    int i;
    int chi[100];
    char stroka[256];
    char *token;

    printf("enter primer with probel: ");
    fgets(stroka, sizeof(stroka), stdin);

    token = strtok(stroka, " \t\n");
    
    
    return 0;
}