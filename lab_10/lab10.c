#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHISLO(chisla, count) ({int per = (chisla)[0]; for(int w = 1; w < (count); w++) {if((chisla)[w] > per) per = (chisla)[w]; } per;})

int main() {
    char stroka[512];
    int numbers[100];
    int i;
    int cunt;

    printf("if you wanna enter a chisla, so you need to give me a count: ");
    scanf("%d", &cunt);
    
    printf("enter chisla with probel: ");
    for (i = 0; i < cunt; i++)
    {
        scanf(" %c", &stroka);
    }

    
    
    return 0;
}