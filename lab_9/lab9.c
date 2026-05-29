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
    char vremop = '+';
    char stroka[256];
    char *token;
    char *prop;

    printf("enter primer with probel: ");
    fgets(stroka, sizeof(stroka), stdin);

    size_t strlenn = strlen(stroka);
    if (strlenn > 0 && stroka[strlenn-1] == '\n') {
        stroka[strlenn-1] = '\0';
    }

    token = strtok(stroka, " \t\n");
    
    while (token != NULL)
    {
        if (strlen(token) == 1)
        {
            if (token[0] == '+' || token[0] == '-')
            {
                vremop = token[0];
                token = strtok(NULL, " ");
                continue;
            }
        }

        vrem = 0.0;
        i = 0;
        minus = 0;

        if (token[0] = '-')
        {
            minus = 1;
            prop = token + 1;
        }
        else
        {
            prop = token;
        }

        wrem = 
    }
    
    return 0;
}