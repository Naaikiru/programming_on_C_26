//5 6 7

#include <stdio.h>
#include <stdlib.h>

// Подсчёт битов для long с выводом двоичного вида
int bit_long(long num)
{
    if (num == 0)
    {
        return 0;
    }
    return (num % 2) + bit_long(num / 2);
}

// Вывод двоичного вида для long
void print_binary_long(long num)
{
    if (num > 1)
        print_binary_long(num / 2);
    printf("%d", num % 2);
}

// Подсчёт битов для double с выводом двоичного вида
int bit_double(double num)
{
    unsigned char *ptr = (unsigned char*)&num;
    int count = 0;
    int i, bit;
    
    // Выводим двоичный вид (8 байт)
    for(i = sizeof(double) - 1; i >= 0; i--)
    {
        for(bit = 7; bit >= 0; bit--)
        {
            if(ptr[i] & (1 << bit))
            {
                printf("1");
                count++;
            }
            else
            {
                printf("0");
            }
        }
        printf(" ");
    }
    printf("\n");
    
    return count;
}

int main()
{
    int chc;
    printf("Выберите тип (1 - long, 2 - double): ");
    scanf("%d", &chc);
    
    if (chc == 1)
    {
        long num;
        printf("Введите long число: ");
        scanf("%ld", &num);
        
        printf("Двоичный вид: ");
        if (num == 0)
            printf("0");
        else
            print_binary_long(num);
        printf("\n");
        
        printf("Количество единиц: %d\n", bit_long(num));
    }
    else if (chc == 2)
    {
        double num;
        printf("Введите double число: ");
        scanf("%lf", &num);
        
        printf("Двоичный вид: ");
        int count = bit_double(num);
        printf("Количество единиц: %d\n", count);
    }
    
    return 0;
}