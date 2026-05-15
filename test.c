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
    if (f1 == NULL) {
        printf("Ошибка открытия файла!\n");
        return 1;
    }
    
    while (fgets(bff, sizeof(bff), f1) != NULL) 
    {
        if (strlen(bff) > 1) 
        {
            count++;
        }
    }
    fclose(f1);

    struct humen *kek;
    kek = (struct humen*)malloc(count * sizeof(struct humen));

    int i, j;

    FILE * f2 = fopen("info_about_you.txt", "r");
    if (f2 == NULL) {
        printf("Ошибка открытия файла!\n");
        free(kek);
        return 1;
    }

    for (i = 0; i < count; i++)
    {
        fscanf(f2, "%s %s %d %s %lf", 
               kek[i].name, 
               kek[i].lastn, 
               &kek[i].bthd, 
               kek[i].gendr, 
               &kek[i].hght);
    }
    fclose(f2);

    int hop;
    char params[10];  // массив для хранения параметров
    
    printf("Organization parameter: Name(N), Lastname(L), Bday(B), Gender(G), Height(H)\n");
    printf("How many options you wanna choose: ");
    scanf("%d", &hop);  // исправлено: %d
    
    printf("Enter %d parameter(s) (N/L/B/G/H): ", hop);
    for (int p = 0; p < hop; p++)
    {
        scanf(" %c", &params[p]);  // исправлено: пробел перед %c
    }
    
    // СОРТИРОВКА ПО ВСЕМ ПАРАМЕТРАМ СРАЗУ
    for (i = 0; i < count - 1; i++)
    {
        for (j = 0; j < count - 1 - i; j++)
        {
            int should_swap = 0;
            
            // Проверяем параметры в порядке приоритета
            for (int p = 0; p < hop; p++)
            {
                char op = params[p];
                
                if (op == 'N')  // по имени
                {
                    int cmp = strcmp(kek[j].name, kek[j+1].name);
                    if (cmp > 0) { should_swap = 1; break; }
                    if (cmp < 0) { should_swap = 0; break; }
                    // если равны, продолжаем со следующим параметром
                }
                else if (op == 'L')  // по фамилии
                {
                    int cmp = strcmp(kek[j].lastn, kek[j+1].lastn);
                    if (cmp > 0) { should_swap = 1; break; }
                    if (cmp < 0) { should_swap = 0; break; }
                }
                else if (op == 'B')  // по году рождения
                {
                    if (kek[j].bthd < kek[j+1].bthd) { should_swap = 1; break; }
                    if (kek[j].bthd > kek[j+1].bthd) { should_swap = 0; break; }
                }
                else if (op == 'G')  // по полу
                {
                    if (kek[j].gendr[0] > kek[j+1].gendr[0]) { should_swap = 1; break; }
                    if (kek[j].gendr[0] < kek[j+1].gendr[0]) { should_swap = 0; break; }
                }
                else if (op == 'H')  // по росту
                {
                    if (kek[j].hght < kek[j+1].hght) { should_swap = 1; break; }
                    if (kek[j].hght > kek[j+1].hght) { should_swap = 0; break; }
                }
            }
            
            if (should_swap == 1)
            {
                struct humen meow = kek[j];
                kek[j] = kek[j + 1];
                kek[j + 1] = meow;
            }
        }
    }
    
    
    
    for (i = 0; i < count; i++)
    {
        printf("%s %s %d %s %g\n", 
               kek[i].name, 
               kek[i].lastn, 
               kek[i].bthd, 
               kek[i].gendr, 
               kek[i].hght);
    }

    free(kek);
    return 0;
}