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

	char op[20];
	int hop;
	printf("Organization parameter: Name/Lastname, Bday, Gender, Height (only capital letters & u can use several options)\n");
	printf("How many options you wanna choose: ");
	scanf("%d", &hop);
	for (j = 0; j < hop; j++)
	{
		printf("choose %d parameter(s): ", hop);
		scanf(" %c", &op);
	}
	for (i = 0; i < count - 1; i++)
	{
		for (j = 0; j < count - i - 1; j ++)
		{
			int nchange = 0;
			if (op == 'N')
			{
				if (strcmp(kek[j].name, kek[j + 1].name) > 0);
			}

			else if (op == 'L')
			{
				if (strcmp(kek[j].lastn, kek[j + 1].lastn) > 0);
			}

			else if (op == 'B')
			{
				if (kek[j].bthd < kek[j + 1].bthd);
			}

			else if (op == 'G')
			{
				if (kek[j].gendr[0] > kek[j + 1].gendr[0]);
			}
				
			else if (op == 'H')
			{
				if (kek[j].hght < kek[j + 1].hght);
			}


			if (nchange == 1)
			{
                struct humen meow = kek[j];
                kek[j] = kek[j + 1];
                kek[j + 1] = meow;
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