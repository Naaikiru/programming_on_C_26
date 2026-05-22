#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("summa: %d\n", summ(5, 10, 7, 12, 2, 19));
    printf("maximum: %d\n", maxx(5, 10, 7, 12, 2, 19));
    printf("minimum: %d\n", minn(5, 10, 7, 12, 2, 19));
    printf("srednee znachenie: %d\n", srznach(5, 10, 7, 12, 2, 19));
    
    return 0;
}