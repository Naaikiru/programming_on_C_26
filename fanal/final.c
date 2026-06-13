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

int main()
{
    int size;
    char op;
    printf("enter the size of the matrix: \n");
    scanf("%d", &size);


    int **M1, **M2, **MM;
    int x, y;
    int i, j;

    M1 = (int**)malloc(size*sizeof(int*));
	for(x = 0; x < size; x++){
		M1[x] = (int*)malloc(size*sizeof(int));
	}
    printf("enter 1matrix: \n");
    scnfm(M1, size);

    M2 = (int**)malloc(size*sizeof(int*));
	for(x = 0; x < size; x++){
		M2[x] = (int*)malloc(size*sizeof(int));
	}
    printf("enter 2matrix: \n");
    scnfm(M2, size);

    FILE *f1 = fopen("input.txt", "w");

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j ++)
        {
            fprintf(f1, "%d ", M1[i][j]);
        }
        fprintf(f1, "\n");
    }
    fprintf(f1, "\n");
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j ++)
        {
            fprintf(f1, "%d ", M2[i][j]);
        }
        fprintf(f1, "\n");
    }
    fclose(f1);

    showm(MM, size);

    free(M1);
    free(M2);
    free(MM);
    
    return 0;
}