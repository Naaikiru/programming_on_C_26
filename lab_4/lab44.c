#include "lab44.h"
#include <stdio.h>
#include <math.h>

int prov(double a, double b, double c)
{
    if (a < 0 || b < 0 || c < 0)
    {
        return 0;
    }

    if (((a + b) > c && (a + c) > b && (b + c) > a))
    {
        return 1;
    }
    return 0;
}

double per(double a, double b, double c)
{
    return a + b + c;
}

double plos(double a, double b, double c)
{
    double pr = (a + b + c) / 2.0;
    return sqrt(pr*(pr - a)*(pr - b)*(pr - c));
}