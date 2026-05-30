я люблю рыжих.

<img width="736" height="734" alt="South Park" src="https://github.com/user-attachments/assets/8a41c741-b4d7-41ce-b8f6-e05daf44c111" />




bkv.vvsu.ru/ftp — вай фай ввгу

bkv.net.ru/ftp — не вай фай ввгу

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100

int main()
{
    printf("|| calculator ||\n");

    char stroka[256];
    char *token;
    char *tokens[MAX_TOKENS];
    double values[MAX_TOKENS];
    char ops[MAX_TOKENS];
    int count = 0;
    int i;

    printf("enter primer with probel: ");
    fgets(stroka, sizeof(stroka), stdin);

    size_t len = strlen(stroka);
    if (len > 0 && stroka[len-1] == '\n') {
        stroka[len-1] = '\0';
    }

    // 1. Разбор строки на токены
    token = strtok(stroka, " ");
    while (token != NULL && count < MAX_TOKENS)
    {
        tokens[count++] = token;
        token = strtok(NULL, " ");
    }

    if (count == 0) {
        printf("no input\n");
        return 1;
    }

    // 2. Преобразование чисел и операций
    double nums[MAX_TOKENS];
    char opers[MAX_TOKENS];
    int num_count = 0;
    int op_count = 0;

    for (i = 0; i < count; i++)
    {
        // Проверка, является ли токен операцией
        if (strlen(tokens[i]) == 1 && 
            (tokens[i][0] == '+' || tokens[i][0] == '-' || 
             tokens[i][0] == '*' || tokens[i][0] == '/'))
        {
            opers[op_count++] = tokens[i][0];
        }
        else
        {
            // Иначе это число
            nums[num_count++] = atof(tokens[i]);
        }
    }

    // Должно быть: чисел на 1 больше, чем операций
    if (num_count != op_count + 1) {
        printf("error: wrong expression\n");
        return 1;
    }

    // 3. Первый проход: * и /
    double result = nums[0];
    int used[MAX_TOKENS] = {0}; // для отметки "обработанных" операций
    double new_nums[MAX_TOKENS];
    char new_ops[MAX_TOKENS];
    int new_num_count = 1;
    int new_op_count = 0;
    
    new_nums[0] = nums[0];

    for (i = 0; i < op_count; i++)
    {
        if (opers[i] == '*' || opers[i] == '/')
        {
            double a = new_nums[new_num_count - 1];
            double b = nums[i + 1];
            double c;
            if (opers[i] == '*')
                c = a * b;
            else
                c = a / b;
            new_nums[new_num_count - 1] = c;
        }
        else
        {
            // + или - сохраняем для второго прохода
            new_nums[new_num_count++] = nums[i + 1];
            new_ops[new_op_count++] = opers[i];
        }
    }

    // 4. Второй проход: + и -
    double final_result = new_nums[0];
    for (i = 0; i < new_op_count; i++)
    {
        if (new_ops[i] == '+')
            final_result += new_nums[i + 1];
        else if (new_ops[i] == '-')
            final_result -= new_nums[i + 1];
    }

    printf("= %lf\n", final_result);
    
    return 0;
}
