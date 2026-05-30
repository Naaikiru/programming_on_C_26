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

    int frst = 1;
    int minus = 0;
    double res = 0.0;       // текущий результат
    double last_value = 0.0; // для отложенного умножения/деления
    double vrem;
    char last_op = '+';      // последняя операция с низким приоритетом (+ или -)
    char current_op = '+';   // текущая операция (из токена)
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
        // Если токен — оператор
        if (strlen(token) == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'))
        {
            current_op = token[0];
            token = strtok(NULL, " ");
            continue;
        }

        // Парсим число
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

        // Первое число
        if (frst)
        {
            res = vrem;
            last_value = vrem;
            frst = 0;
        }
        else
        {
            // Обработка с учётом приоритета
            if (current_op == '*' || current_op == '/')
            {
                // Вычисляем с последним значением
                if (current_op == '*')
                    last_value = last_value * vrem;
                else if (current_op == '/')
                    last_value = last_value / vrem;
            }
            else // + или -
            {
                // Сначала применяем накопленное last_value к res
                if (last_op == '+')
                    res = res + last_value;
                else if (last_op == '-')
                    res = res - last_value;
                
                // Теперь last_value = текущее число
                last_value = vrem;
                last_op = current_op;
            }
        }

        token = strtok(NULL, " ");
    }

    // В конце применяем последнюю накопленную операцию
    if (last_op == '+')
        res = res + last_value;
    else if (last_op == '-')
        res = res - last_value;

    printf("= %lf\n", res);
    
    return 0;
}
