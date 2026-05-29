#include <stdio.h>
#include <stdlib.h>

int num_bits(long n)  // изменил тип параметра на long
{
    if (n == 0) return 0;
    return (n % 2) + num_bits(n / 2);
}    

int main(int argc, char *argv[])
{
    long n;  // изменил тип переменной на long
    printf("n=");
    scanf("%ld", &n);  // %ld для long
    printf("number of bits=%d\n", num_bits(n)); 
    system("PAUSE");  
    return 0;
}