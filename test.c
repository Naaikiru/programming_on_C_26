#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

double calculate(const char *expression) {
    char *str = malloc(strlen(expression) + 2);
    if (!str) {
        printf("Ошибка выделения памяти\n");
        return 0;
    }
    strcpy(str, expression);
    
    double result = 0.0;
    double current_number;
    char *token;
    char last_operator = '+';
    int is_first = 1;
    int unary_mode = 0;
    
    // Разделители: пробел, табуляция и т.д.
    token = strtok(str, " \t\n");
    
    while (token != NULL) {
        char *endptr;
        
        // Проверяем, является ли токен оператором
        if (strlen(token) == 1 && (token[0] == '+' || token[0] == '-')) {
            last_operator = token[0];
            unary_mode = 0;
        }
        else {
            // Пытаемся преобразовать токен в число
            current_number = strtod(token, &endptr);
            
            // Если преобразование не удалось
            if (*endptr != '\0') {
                // Проверка на унарный оператор в начале токена
                if ((token[0] == '+' || token[0] == '-') && strlen(token) > 1) {
                    char *num_str = token + 1;
                    current_number = strtod(num_str, &endptr);
                    
                    if (*endptr != '\0') {
                        printf("Ошибка: некорректное число '%s'\n", token);
                        free(str);
                        return 0;
                    }
                    
                    // Применяем унарный оператор
                    if (token[0] == '-') {
                        current_number = -current_number;
                    }
                    
                    // Определяем операцию для этого числа
                    if (is_first) {
                        result = current_number;
                        is_first = 0;
                    } else {
                        if (last_operator == '+')
                            result += current_number;
                        else if (last_operator == '-')
                            result -= current_number;
                    }
                    last_operator = '+';
                }
                else {
                    printf("Ошибка: некорректный токен '%s'\n", token);
                    free(str);
                    return 0;
                }
            }
            else {
                // Обычное число
                if (is_first) {
                    result = current_number;
                    is_first = 0;
                } else {
                    if (last_operator == '+')
                        result += current_number;
                    else if (last_operator == '-')
                        result -= current_number;
                }
                last_operator = '+';
            }
        }
        
        token = strtok(NULL, " \t\n");
    }
    
    free(str);
    return result;
}

int main() {
    char expression[1024];
    
    printf("Калькулятор (поддерживает + и -, унарные операторы)\n");
    printf("Примеры: \"-123.5 + 4 - 456+56\" или \"5+-3\"\n");
    printf("Введите 'exit' для выхода\n\n");
    
    while (1) {
        printf("Введите выражение: ");
        fgets(expression, sizeof(expression), stdin);
        
        // Удаляем символ новой строки
        expression[strcspn(expression, "\n")] = '\0';
        
        if (strcmp(expression, "exit") == 0) {
            printf("До свидания!\n");
            break;
        }
        
        if (strlen(expression) == 0) {
            continue;
        }
        
        double result = calculate(expression);
        printf("Результат: %g\n\n", result);
    }
    
    return 0;
}