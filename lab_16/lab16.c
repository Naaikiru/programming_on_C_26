#include <stdio.h>
#include <stdlib.h>

int bit_long(long num)
{
    if (num == 0)
	{
		return 0;
	}
    return (num % 2) + bit_long(num / 2);
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
            {
                cunt++;
            }
        }
    }
    return cunt;
}
  
void print_long(long num)
{
    if (num == 0)
    {
        printf("0");
        return;
    }
    if (num > 1)
        print_long(num / 2);
    printf("%d", num % 2);
}

void print_double(double num)
{
    unsigned char *numnum = (unsigned char*)&num;
    int i, bit;
    
    for(i = sizeof(double) - 1; i >= 0; i--)
    {
        for(bit = 7; bit >= 0; bit--)
        {
            if(numnum[i] & (1 << bit))
                printf("1");
            else
                printf("0");
        }
        printf(" ");
    }
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
        printf("binary: ");
        print_long(num);
        printf("\nnumber of bits = %d\n", bit_long(num));
    }

    else if (chc == 2)
    {
        double num;
        printf("enter number with type double: ");
        scanf("%lf", &num);
        printf("binary: ");
        print_double(num);
        printf("\nnumber of bits = %d\n", bit_double(num));
    }
    return 0;
} 