#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct humen
{
	char name[20];
	char lastn[20];
	int bthd;
    char gendr[20];
    int hght;
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

	

    return 0;
}