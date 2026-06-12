// 2nd variant:

#include <stdio.h>      // Для printf, scanf, FILE, fopen, fgets, fclose
#include <stdlib.h>     // Для malloc, free
#include <string.h>     // Для strlen

// Структура "человек" с полями: имя, фамилия, год рождения
struct humen
{
    char name[20];
    char lastn[20];
    int bthd;
};

int main() 
{
    int count = 0;                      // Счётчик количества записей в файле
    char bff[256];                      // Буфер для чтения строк
    FILE * f1 = fopen("nlnage.txt", "r");   // Открываем файл для чтения
    
    // ПЕРВЫЙ ПРОХОД: считаем количество непустых строк в файле
    while (fgets(bff, sizeof(bff), f1) != NULL)   // Читаем построчно, пока не конец файла
    {
        if (strlen(bff) > 1)            // Если строка длиннее 1 символа (не пустая)
        {
            count++;                    // Увеличиваем счётчик
        }
    }
    fclose(f1);                         // Закрываем файл после подсчёта
    
    // Выделяем динамическую память под массив kek (исходные данные)
    struct humen *kek;
    kek = (struct humen*)malloc(count * sizeof(struct humen));
    
    // Выделяем динамическую память под массив lol (отсортированные данные)
    struct humen *lol;
    lol = (struct humen*)malloc(count * sizeof(struct humen));
    
    int i, j;                           // Переменные для циклов

    // ВТОРОЙ ПРОХОД: читаем данные из файла в массив kek
    FILE * f2 = fopen("nlnage.txt", "r");   // Снова открываем файл
    
    for(i = 0; i < count; i++)
    {
        // Читаем: имя фамилия год_рождения
        fscanf(f2, "%s %s %d", kek[i].name, kek[i].lastn, &kek[i].bthd);
    } 
    fclose(f2);                         // Закрываем файл после чтения

    // Копируем данные из kek в lol (создаём копию для сортировки)
    for (i = 0; i < count; i++) 
    {
        lol[i] = kek[i];                // Присваиваем структуру целиком
    }

    // СОРТИРОВКА ПУЗЫРЬКОМ (по убыванию года рождения)
    for(i = 0; i < count - 1; i++)                  // Внешний цикл: количество проходов
    {
        for (j = 0; j < count - 1 - i; j++)         // Внутренний цикл: сравнение соседей
        {
            // Если текущий год рождения МЕНЬШЕ следующего (т.е. нужно менять для убывания)
            if (lol[j].bthd < lol[j + 1].bthd)
            {
                // Меняем элементы местами
                struct humen meow = lol[j];         // Временная переменная для обмена
                lol[j] = lol[j + 1];
                lol[j + 1] = meow;
            }
        }
    }
    
    // ВЫВОД ОТСОРТИРОВАННОГО МАССИВА
    for(j = 0; j < count; j++)
    {
        // Печатаем имя, фамилию, год рождения
        printf("%s %s %d\n", lol[j].name, lol[j].lastn, lol[j].bthd);
    }
    
    // ОСВОБОЖДАЕМ ПАМЯТЬ (хороший тон)
    free(kek);      // Освобождаем массив с исходными данными
    free(lol);      // Освобождаем массив с отсортированными данными
    
    return 0;       // Завершаем программу
}