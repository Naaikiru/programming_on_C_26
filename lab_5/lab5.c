#include "lab55.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;
    char op;
    printf("enter the size of the matrix: \n");
    scanf("%d", &size);


    int **M1, **M2, **MM;
    int x, y;

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

    printf("enter operation('+', '-' or '*'): ");
    scanf("%c", &op);

    if (op == '+')
    {
        MM = sum(M1, M2, size);
    }

    else if (op == '-')
    {
        MM = sub(M1, M2, size);
    }

    else if (op == '*')
    {
        MM = mult(M1, M2, size);
    }

    showm(MM, size);

    free(M1);
    free(M2);
    free(MM);

    return 0;
}