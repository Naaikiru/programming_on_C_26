#include <stdio.h>

int main() {

    FILE *f1 = fopen("lnnfn.txt", "r");
    FILE *f2 = fopen("lnnfn80.txt", "w");

    char bff[256];
    int bd;

    while ((fgets(bff, 256, f1)) != NULL) 
	{
		if (bff[0] == 'B')
		{
			fputs(bff, f2);
    		printf("%s", bff);
		}
    	/*char * bdp = strrchr(bff, ' ');
    	if (bdp != NULL && sscanf(bdp + 1, "%d", &bd) == 1)
		{
    		if (bd >= 1980)
			{
    			fputs(bff, f2);
    			printf("%s", bff);
			}
		}*/
    }

    fclose(f1);
    fclose(f2);

    return 0;
}