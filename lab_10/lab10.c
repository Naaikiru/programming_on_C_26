#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHISLO(chisla, count) ({int per = (chisla)[0]; for(int w = 1; w < (count); w++) {if((chisla)[w] > per) per = (chisla)[w]; } per;})

int main() {
    char stroka[512];
    int chi[100];
    int i, cunt, maxchi;
    char *vrem;

    printf("if you wanna enter a chisla, so you need to give me a count: ");
    scanf("%d", &cunt);

    getchar();
    
    printf("enter chisla with probel: ");
    fgets(stroka, sizeof(stroka), stdin);

    vrem = strtok(stroka, " \t\n");
    for (i = 0; i < cunt && vrem != NULL; i++)
    {
        chi[i] = atoi(vrem);
        vrem = strtok(NULL, " \t\n");
    }

    maxchi = MAX_CHISLO(chi, cunt);
    printf("max chislo: %d", maxchi);
    
    return 0;
}