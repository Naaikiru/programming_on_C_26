#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct humen
{
	char name[20];
	char lastn[20];
	int bthd;
};

int main() 
{
	int chlen;

	FILE * f1 = fopen("nlnage.txt", "r");
	
	
	struct humen *kek;
    kek = (int*)malloc(chlen*sizeof(struct humen));
	
    struct humen *lol;
    lol = (int*)malloc(chlen*sizeof(struct humen));
    
	fclose(f1);
	int i, j;

    FILE * f1 = fopen("nlnage.txt", "r");
    
    for(i = 0; i < chlen; i++)
    {
        fscanf(f1, "%s %s %d", kek[i].name, kek[i].lastn, &kek[i].bthd);
    }

    fclose(f1);

    for (i = 0; i < chlen; i++) 
    {
        lol[i] = kek[i];
    }

    for(i = 0; i < chlen - 1; i++)
    {
        for (j = 0; j < chlen - 1 - i; j++)
        {
            if (lol[j].bthd < lol[j + 1].bthd)
            {
                struct humen meow = lol[j];
                lol[j] = lol[j + 1];
                lol[j + 1] = meow;
            }
        }
    }
    
    for(j = 0; j < chlen; j++)
    {
    	printf("%s %s %d\n", lol[j].name, lol[j].lastn, lol[j].bthd);
	}
	
	free(kek);
	free(lol);
	
	return 0;
}