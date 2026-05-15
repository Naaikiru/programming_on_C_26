#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct humen
{
	char name[20];
	char lastn[20];
	int bthd;
    char gendr[20];
    double hght;
};


int main()
{
    int count = 0;
	char bff[256];
	FILE * f1 = fopen("info_about_you.txt", "r");
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

	int i, j;

	FILE * f2 = fopen("info_about_you.txt", "r");

	for (i = 0; i < count; i++)
	{
		fscanf(f2, "%s %s %d %s %lf", kek[i].name, kek[i].lastn, &kek[i].bthd, kek[i].gendr, &kek[i].hght);
	}
	fclose(f2);

	char op;
	printf("enter the organization parameter(Name/LastName, BDay, Gender, Height(only capital letters & u can use several options)):\n");
	scanf("%c", &op);

	if (op == 'N')
	{
		for (i = 0; i < count - 1; i++)
		{
			for (j = 0; j < count - 1 - i; j++)
			{
				if (strcmp(kek[j].name, kek[j + 1].name) > 0)
				{
					struct humen meow = kek[j];
					kek[j] = kek[j + 1];
					kek[j + 1] = meow; 
				}
			}
		}
	}

	for (i = 0; i < count; i++)
	{
		printf("%s %s %d %s %g\n", kek[i].name, kek[i].lastn, kek[i].bthd, kek[i].gendr, kek[i].hght);
	}

	free(kek);
    return 0;
}