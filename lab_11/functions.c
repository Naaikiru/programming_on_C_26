#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int summ(int n, ...);
{
    int res = 0;
    va_list list;
    va_start(list, n);
    while(n)
    {
        res += va_arg(list, int);
        --n;
    }
    va_end(list);
    return res;
}

int maxx(int n, ...);
{

}

int minn(int n, ...);


int srznach(int n, ...);
