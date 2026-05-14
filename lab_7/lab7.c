/*#include <stdio.h>
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
	
	struct humen kek[4];
    struct humen lol[4];
	int i, j;
	for(i = 0; i < 4; i++)
	{
		scanf("%s", kek[i].name); 
    	scanf("%s", kek[i].lastn);
    	scanf("%d", &kek[i].bthd);
	}

    for (int i = 0; i < 4; i++) 
    {
        lol[i] = kek[i];
    }

    for(i = 0; i < 3; i++)
    {
        for (j = 0; j < 3 - i; j++)
        {
            if (lol[j].bthd < lol[j + 1].bthd)
            {
                struct humen meow = lol[j];
                lol[j] = lol[j + 1];
                lol[j + 1] = meow;
            }
        }
    }
    
    for(j = 0; j < 4; j++)
    {
    	printf("%s %s %d\n", lol[j].name, lol[j].lastn, lol[j].bthd);
	}
	
	return 0;
}*/

// 2nd variant:

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
	int count = 0;
	char bff[256];
	FILE * f1 = fopen("nlnage.txt", "r");
	while (fgets(bff, sizeof(bff), f1) != NULL) 
	{
        if (strlen(bff) > 1) 
		{
            count++;
        }
    }
	fclose(f1);
	
	struct humen *kek;
    kek = (struct humen*)malloc(count*sizeof(struct humen));
	
    struct humen *lol;
    lol = (struct humen*)malloc(count*sizeof(struct humen));
    
	int i, j;

    FILE * f2 = fopen("nlnage.txt", "r");
    
    for(i = 0; i < count; i++)
    {
        fscanf(f2, "%s %s %d", kek[i].name, kek[i].lastn, &kek[i].bthd);
    } 

    fclose(f2);

    for (i = 0; i < count; i++) 
    {
        lol[i] = kek[i];
    }

    for(i = 0; i < count - 1; i++)
    {
        for (j = 0; j < count - 1 - i; j++)
        {
            if (lol[j].bthd < lol[j + 1].bthd)
            {
                struct humen meow = lol[j];
                lol[j] = lol[j + 1];
                lol[j + 1] = meow;
            }
        }
    }
    
    for(j = 0; j < count; j++)
    {
    	printf("%s %s %d\n", lol[j].name, lol[j].lastn, lol[j].bthd);
	}
	
	free(kek);
	free(lol);
	
	return 0;
}