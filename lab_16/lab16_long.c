#include <stdio.h>
#include <stdlib.h>

int bit_long(long num)
{
    if (num == 0) return 0;
    return (num % 2) + num_bits(num / 2);
}   

int bit_double(double num)
{
    unsigned char *numnum = (unsigned char*)&num;
    int cunt = 0;
    int bit, i;
    
    for(i = 0; i < sizeof(double); i++)
    {
        for(bit = 0; bit < 8; bit++)
        {
            if(numnum[i] & (1 << bit))
                cunt++;
        }
    }
    return cunt;
}

int main()
{
    int chc;
    printf("choose type(1 - long, 2 - double): ");
    scanf("%d", &chc);
    
    if (chc == 1)
    {
        long num;
        printf("enter number with type long: ");
        scanf("%ld", &num);
        printf("number of bits = %d\n", bit_long(num));
    }

    else if (chc == 2)
    {
        double num;
        printf("enter number with type double: ");
        scanf("%lf", &num);
        printf("number of bits = %d\n", bit_double(num));
    }
    return 0;
}