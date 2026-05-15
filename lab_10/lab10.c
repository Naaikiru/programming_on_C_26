#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Макрос для нахождения максимального числа в массиве
#define FIND_MAX(arr, n) ({ \
    int _max = (arr)[0]; \
    for(int _i = 1; _i < (n); _i++) { \
        if((arr)[_i] > _max) _max = (arr)[_i]; \
    } \
    _max; \
})

int main() {
    char input[1000];
    int numbers[100];
    int count = 0;
    char *token;
    
    printf("Введите числа через пробел: ");
    fgets(input, sizeof(input), stdin);
    
    token = strtok(input, " \t\n");
    while(token != NULL && count < 100) {
        numbers[count] = atoi(token);
        count++;
        token = strtok(NULL, " \t\n");
    }
    
    if(count == 0) {
        printf("Числа не введены!\n");
        return 1;
    }
    
    int max_number = FIND_MAX(numbers, count);
    printf("Максимальное число: %d\n", max_number);
    
    return 0;
}