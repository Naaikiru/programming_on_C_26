#include "lab55.h"
#include <stdio.h>
#include <stdlib.h>

int **sum(int **M1, int **M2, int size)
{
    int x, y;
    int **MM;

    MM=(int**)malloc(size*sizeof(int*));
    for(x=0;x<size;x++)
    {
        MM[x]= (int*)malloc(size*sizeof(int));
    }
    for (x = 0; x < size; x++)
    {
        for (y = 0; y < size; y++)
        {
            MM[x][y] = M1[x][y] + M2[x][y];
        }
    }
    return MM;
}

int **sub(int **M1, int **M2, int size)
{
    int x, y;
    int **MM;

    MM=(int**)malloc(size*sizeof(int*));
    for(x=0;x<size;x++)
    {
        MM[x]= (int*)malloc(size*sizeof(int));
    }
    for (x = 0; x < size; x++)
    {
        for (y = 0; y < size; y++)
        {
            MM[x][y] = M1[x][y] - M2[x][y];
        }
    }
    return MM;
}

int **mult(int **M1, int **M2, int size)
{
    int x, y, s;
    int **MM;

    MM=(int**)malloc(size*sizeof(int*));
    for(x=0;x<size;x++)
    {
        MM[x]= (int*)malloc(size*sizeof(int));
    }
    for (x = 0; x < size; x++)
    {
        for (y = 0; y < size; y++)
        {
            MM[x][y] = 0;
            for (s = 0; s < size; s++)
            {
                MM[x][y] += M1[x][s] + M2[s][y];
            }
        }
    }
    return MM;
}

void scnfm(int **M, int size)
{
    int x, y;
    for (x = 0; x < size; x++)
    {
        for (y = 0; y < size; y++)
        {
            printf("[%d][%d] = ", x, y);
            scanf("%d", &M[x][y]);
        }
    }
}

void showm(int **M, int size)
{
    int x, y;
    printf("the result of operation: \n");
    for (x = 0; x < size; x++)
    {
        for (y = 0; y < size; y++)
        {
            printf(" %d", M[x][y]);
        }
    }
}