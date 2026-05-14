#include "lab44.h"
#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c;

    printf("enter sides of the triangle: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (!prov(a,b,c)) 
    {
        printf("the triangle doesn't exist\n");
        return 1;
    }

    double pr = per(a, b, c);
    double pls = plos(a, b, c);

    printf("perimetr = %lf\n", pr);
    printf("ploshad = %lf\n", pls);
    
    return 0;
}