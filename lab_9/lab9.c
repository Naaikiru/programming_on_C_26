#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    printf("|| calculator ||\n");

    int frst = 1;
    double res;
    double lstvrem;
    char lastop = '+';
    char vremop = '+';
    char stroka[256];
    char *token;

    printf("enter primer with probel: ");
    fgets(stroka, sizeof(stroka), stdin);

    size_t strlenn = strlen(stroka);
    if (strlenn > 0 && stroka[strlenn-1] == '\n') {
        stroka[strlenn-1] = '\0';
    }

    token = strtok(stroka, " ");
    
    while (token != NULL)
    {
        if (strlen(token) == 1)
        {
            if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')
            {
                vremop = token[0];
                token = strtok(NULL, " ");
                continue;
            }
        }

        double vrem = atof(token);
        if (frst)
        {
            lstvrem = vrem;
            frst = 0;
        }
        else 
        {
            if (vremop == '*' || vremop == '/')
            {
                if (vremop == '*')
                {
                    lstvrem = lstvrem * vrem;
                }
                else
                {
                    lstvrem = lstvrem / vrem;
                }
            }
            else
            {
                if (vremop == '+')
                {
                    res += lstvrem;
                }
                else if (vremop == '-')
                {
                    res -= lstvrem;
                }
                
                lstvrem = vrem;
                lastop = vremop;
            }
        }
        token = strtok(NULL, " ");
    }

    if (lastop == '+')
    {
        res += lstvrem;
    }
    else if (lastop == '-')
    {
        res -= lstvrem;
    }

    printf("= %lf", res);

    return 0;
}