#include <stdio.h>      // Для printf, scanf, FILE, fopen и т.д.
#include <stdlib.h>     // Для malloc, free
#include <string.h>     // Для strcmp, strlen

// Структура "человек" с полями: имя, фамилия, год рождения, пол, рост
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
    int count = 0;                      // Счётчик строк в файле
    char bff[256];                      // Буфер для чтения строк
    FILE * f1 = fopen("info_about_you.txt", "r");   // Открываем файл для чтения
    
    // Первый проход: считаем количество строк в файле
    while (fgets(bff, sizeof(bff), f1) != NULL) 
    {
        if (strlen(bff) > 1)            // Если строка не пустая
        {
            count++;                    // Увеличиваем счётчик
        }
    }
    fclose(f1);                         // Закрываем файл

    // Выделяем память под массив структур (count штук)
    struct humen *kek;
    kek = (struct humen*)malloc(count * sizeof(struct humen));

    int i, j;                           // Индексы для циклов
    FILE * f2 = fopen("info_about_you.txt", "r");   // Снова открываем файл

    // Второй проход: читаем данные в массив структур
    for (i = 0; i < count; i++)
    {
        // Читаем: имя фамилия год_рождения пол рост
        fscanf(f2, "%s %s %d %s %lf", kek[i].name, kek[i].lastn, &kek[i].bthd, kek[i].gendr, &kek[i].hght);
    }
    fclose(f2);                         // Закрываем файл

    char ops[20];                       // Массив для хранения выбранных параметров сортировки
    int hop;                            // Количество параметров
    printf("Organization parameter: Name/Lastname, Bday, Gender, Height (only capital letters & u can use several options)\n");
    printf("How many options you wanna choose: ");
    scanf("%d", &hop);                  // Вводим количество параметров
    
    printf("choose %d parameter(s): ", hop);
    for (j = 0; j < hop; j++)
    {
        scanf(" %c", &ops[j]);          // Вводим параметры: N, L, B, G или H
    }
    
    // Пузырьковая сортировка с множественным критерием
    for (i = 0; i < count - 1; i++)                 // Внешний цикл
    {
        for (j = 0; j < count - i - 1; j++)         // Внутренний цикл
        {
            int nchange = 0;            // Флаг: нужно ли менять элементы (1 - да, 0 - нет)
            int l;
            for (l = 0; l < hop; l++)   // Перебираем все параметры сортировки по приоритету
            {
                char op = ops[l];
                
                // Сортировка по имени (N)
                if (op == 'N')
                {
                    int con = (strcmp(kek[j].name, kek[j + 1].name) > 0);
                    if (con < 0)        // Имя j+1 больше? (меньше в лексикографическом порядке)
                    {
                        nchange = 0;    // Менять не нужно
                        break;          // Выходим из цикла параметров
                    }
                    if (con > 0)        // Имя j больше?
                    {
                        nchange = 1;    // Нужно менять
                        break;
                    }
                    // con == 0 - имена равны, идём к следующему параметру
                }
                
                // Сортировка по фамилии (L)
                else if (op == 'L')
                {
                    int con = (strcmp(kek[j].lastn, kek[j + 1].lastn) > 0);
                    if (con < 0)
                    {
                        nchange = 0;
                        break;
                    }
                    if (con > 0)
                    {
                        nchange = 1;
                        break;
                    }
                }
                
                // Сортировка по полу (G) - сравниваем первую букву строки
                else if (op == 'G')
                {
                    if (kek[j].gendr[0] > kek[j + 1].gendr[0])
                    {
                        nchange = 1;    // Текущий больше - меняем
                        break;
                    }
                    else if (kek[j].gendr[0] < kek[j + 1].gendr[0])
                    {
                        nchange = 0;    // Текущий меньше - не меняем
                        break;
                    }
                }
                
                // Сортировка по году рождения (B)
                else if (op == 'B')
                {
                    if (kek[j].bthd > kek[j + 1].bthd)
                    {
                        nchange = 1;
                        break;
                    }
                    else if (kek[j].bthd < kek[j + 1].bthd)
                    {
                        nchange = 0;
                        break;
                    }
                }
                    
                // Сортировка по росту (H)
                else if (op == 'H')
                {
                    if (kek[j].hght > kek[j + 1].hght)
                    {
                        nchange = 1;
                        break;
                    }
                    else if (kek[j].hght < kek[j + 1].hght)
                    {
                        nchange = 0;
                        break;
                    }
                }
            }

            // Если по всем параметрам решили, что нужно менять
            if (nchange == 1)
            {
                // Обмениваем элементы местами
                struct humen meow = kek[j];
                kek[j] = kek[j + 1];
                kek[j + 1] = meow;
            }
        }
    }
    
    // Выводим отсортированный массив на экран
    for (i = 0; i < count; i++)
    {
        printf("%s %s %d %s %g\n", kek[i].name, kek[i].lastn, kek[i].bthd, kek[i].gendr, kek[i].hght);
    }

    free(kek);          // Освобождаем выделенную память
    return 0;           // Завершаем программу
}