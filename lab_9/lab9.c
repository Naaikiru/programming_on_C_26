#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    printf("|| calculator ||\n");

    int frst = 1;
    double res;
    double umn;
    char top = '+';
    char vremop = '+';
    char stroka[256];
    char token;

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
            umn = vrem;
            frst = 0;
        }
        else 
        {
            if (vremop == '*' || vremop == '/')
            {
                if (vremop == '*')
                {
                    umn = umn * vrem;
                }
                else
                {
                    umn = umn / vrem;
                }
            }
            else
            {
                if (top == '+')
                {
                    res += umn;
                }
                else if (top == '-')
                {
                    res -= umn;
                }
                
                umn = vrem;
                top = vremop;
            }
        }
        token = strtok(NULL, " ");
    }

    if (top == '+')
    {
        res += umn;
    }
    else if (top == '-')
    {
        res -= umn;
    }

    printf("= %lf", res);

    return 0;
}