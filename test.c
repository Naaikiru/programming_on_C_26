#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    char input[256];
    char *token;
    double result = 0.0;
    double current_number;
    char current_operator = '+';
    int first_number = 1;
    int unary_minus = 0;
    char *ptr;
    int i;
    
    printf("Введите арифметическое выражение (например, -123.5 + 4 - 456+56): ");
    fgets(input, sizeof(input), stdin);
    
    // Удаляем символ новой строки, если он есть
    size_t len = strlen(input);
    if (len > 0 && input[len-1] == '\n') {
        input[len-1] = '\0';
    }
    
    // Разбиваем строку на токены
    token = strtok(input, " ");
    
    while (token != NULL) {
        // Проверяем, является ли токен оператором
        if (strlen(token) == 1 && (token[0] == '+' || token[0] == '-')) {
            current_operator = token[0];
            token = strtok(NULL, " ");
            continue;
        }
        
        // Обработка чисел (включая отрицательные)
        current_number = 0.0;
        i = 0;
        unary_minus = 0;
        
        // Проверка на унарный минус в начале токена
        if (token[0] == '-') {
            unary_minus = 1;
            ptr = token + 1; // Пропускаем минус
        } else {
            ptr = token;
        }
        
        // Преобразуем строку в число
        current_number = strtod(ptr, NULL);
        
        // Если был унарный минус, делаем число отрицательным
        if (unary_minus) {
            current_number = -current_number;
        }
        
        // Выполняем операцию
        if (first_number) {
            result = current_number;
            first_number = 0;
        } else {
            if (current_operator == '+') {
                result += current_number;
            } else if (current_operator == '-') {
                result -= current_number;
            }
        }
        
        token = strtok(NULL, " ");
    }
    
    printf("Результат: %g\n", result);
    
    return 0;
}