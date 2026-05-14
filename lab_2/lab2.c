#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) 
{
    int i = 0;
    while (i == 0)
    {       
        int size;
        printf("enter the size of the matrix: \n");
        scanf("%d", &size);


        printf("matrices with the 'double' type(3x3): \n");

        double m[size][size];
        int x;
        int y;
        double sum1= 0, sum2= 0;
        for(x =0; x < size; x++)
        {
            for(y =0; y < size; y++)
            {
                scanf("%lf", &m[x][y]);
            }
        }

        for (int s = 0; s < size; s++)
        {
            sum1 += m[s][s];
            sum2 += m[s][size-1-s];
      
        }
                           
        printf("the sum of the values of the main diagonal = %lf \n", sum1);
        printf("the sum of the values of the side diagonal = %lf \n", sum2);
        
        

        printf("matrices with the 'int' type(2x2): \n");
        double array [2][2];
        double sqr [2][2];
        for (int i = 0; i < 2; i++) 
        {
            for (int j = 0; j < 2; j++) 
            {
                scanf("%lf", &array [i][j]);
            }
        }

        sqr [0][0] = array [0][0] * array [0][0] + array [0][1] * array [1][0];
        sqr [0][1] = array [0][0] * array [0][1] + array [0][1] * array [1][1];
        sqr [1][0] = array [1][0] * array [0][0] + array [1][1] * array [1][0];
        sqr [1][1] = array [1][0] * array [0][1] + array [1][1] * array [1][1];
        
        for(x =0; x < size; x++)
        {
            for(y =0; y < size; y++)
            {
                printf ("%lf", sqr([x][y]);
                printf(" ");
            }
        }

            /*printf("the square of the second matrix: \n");
            printf("%d", (mm[0][0]*mm[0][0])+(mm[0][1]*mm[1][0]));
            printf(" %d \n", (mm[0][0]*mm[0][1])+(mm[0][1]*mm[1][1]));
            printf("%d", (mm[0][0]*mm[1][0])+(mm[1][1]*mm[1][0]));
            printf(" %d \n", (mm[1][0]*mm[0][1])+(mm[1][1]*mm[1][1]));*/


        int z;
        printf(" \n");
        printf("write '1' if ypu wanna contune or '0' if you wanna stop: \n");
        scanf("%d", &z);
        if (!z) break;
    }

	return 0;
}



