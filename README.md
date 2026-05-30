я люблю рыжих.

<img width="736" height="734" alt="South Park" src="https://github.com/user-attachments/assets/8a41c741-b4d7-41ce-b8f6-e05daf44c111" />




bkv.vvsu.ru/ftp — вай фай ввгу

bkv.net.ru/ftp — не вай фай ввгу


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    printf("|| calculator ||\n");

    //int i;
    int frst = 1;
    int minus = 0;
    double res = 0.0;
    double umn = 0.0;
    double vrem;
    char top = '+';
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

        vrem = 0.0;
        minus = 0;

        if (token[0] == '-')
        {
            minus = 1;
            prop = token + 1;
        }
        else
        {
            prop = token;
        }

        vrem = strtod(prop, NULL);
        if (minus)
        {
            vrem = -vrem;
        }
        if (frst)
        {
            res = vrem;
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
                else if (vremop == '/')
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
            }

        }
        token = strtok(NULL, " ");
    }

    if (umn == '+')
    {
        res += umn;
    }
    else if (umn == '-')
    {
        res -= umn;
    }

    printf("= %lf", res);
    
    return 0;
}
