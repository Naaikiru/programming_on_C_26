я люблю рыжих.

<img width="736" height="734" alt="South Park" src="https://github.com/user-attachments/assets/8a41c741-b4d7-41ce-b8f6-e05daf44c111" />




bkv.vvsu.ru/ftp — вай фай ввгу

bkv.net.ru/ftp — не вай фай ввгу



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Функция создания квадратной матрицы m x m со случайными числами 0-9
void createMatrix(int m, int matrix[m][m]) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            matrix[i][j] = rand() % 10;
}

// Функция подсчёта суммы всех элементов матрицы
int sumMatrix(int m, int matrix[m][m]) {
    int sum = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            sum += matrix[i][j];
    return sum;
}

// Функция вывода матрицы в файл
void printMatrix(FILE *f, int m, int matrix[m][m]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++)
            fprintf(f, "%d ", matrix[i][j]);
        fprintf(f, "\n");
    }
}

int main() {
    clock_t start, end;
    start = clock();
    
    srand(time(NULL));
    
    // --- 1. Расчёт количества дней до даты ---
    FILE *f = fopen("input.txt", "r");
    if (f == NULL) {
        printf("Ошибка: файл input.txt не найден!\n");
        return 1;
    }
    
    int day, month, year;
    fscanf(f, "%d %d %d", &day, &month, &year);
    fclose(f);
    
    // Проверяем корректность даты
    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 2025) {
        printf("Некорректная дата в файле!\n");
        return 1;
    }
    
    // Количество дней в каждом месяце (не високосный год)
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Проверка на високосный год
    int leap = 0;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        leap = 1;
    if (leap) daysInMonth[1] = 29;
    
    // Текущая дата: 13 июня 2026 года (сегодня)
    int curDay = 13, curMonth = 6, curYear = 2026;
    
    // Если введённая дата раньше сегодняшней
    if (year < curYear || (year == curYear && month < curMonth) || 
        (year == curYear && month == curMonth && day < curDay)) {
        printf("Дата должна быть не раньше сегодняшней (13.06.2026)!\n");
        return 1;
    }
    
    int totalDays = 0;
    
    // Считаем дни от текущей даты до указанной
    // Сначала от сегодня до конца года
    if (year == curYear) {
        // Тот же год
        if (month == curMonth) {
            totalDays = day - curDay;
        } else {
            // Остаток дней в текущем месяце
            totalDays += daysInMonth[curMonth - 1] - curDay;
            // Полные месяцы между
            for (int m = curMonth + 1; m < month; m++)
                totalDays += daysInMonth[m - 1];
            // Дни в целевом месяце
            totalDays += day;
        }
    } else {
        // Дни от сегодня до конца текущего года
        totalDays += daysInMonth[curMonth - 1] - curDay;
        for (int m = curMonth + 1; m <= 12; m++)
            totalDays += daysInMonth[m - 1];
        
        // Полные годы между
        for (int y = curYear + 1; y < year; y++) {
            if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
                totalDays += 366;
            else
                totalDays += 365;
        }
        
        // Дни в целевом году до указанного месяца
        for (int m = 1; m < month; m++) {
            // Обновляем високосность для целевого года
            int leapYear = 0;
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
                leapYear = 1;
            int dim = (m == 2 && leapYear) ? 29 : daysInMonth[m - 1];
            totalDays += dim;
        }
        totalDays += day;
    }
    
    printf("Дней до указанной даты: %d\n", totalDays);
    
    // --- 2-3. Создание матриц до совпадения сумм ---
    int m;
    printf("Введите размер матрицы m: ");
    scanf("%d", &m);
    
    if (m <= 0) {
        printf("Размер должен быть положительным!\n");
        return 1;
    }
    
    FILE *out = fopen("output.txt", "w");
    if (out == NULL) {
        printf("Ошибка создания output.txt\n");
        return 1;
    }
    
    fprintf(out, "Дата в input.txt: %02d.%02d.%04d\n", day, month, year);
    fprintf(out, "Дней до даты: %d\n\n", totalDays);
    
    int matrix1[m][m], matrix2[m][m];
    int sum1, sum2;
    int count = 0;
    
    fprintf(out, "--- Поиск двух матриц с одинаковой суммой ---\n");
    
    do {
        // Создаём первую матрицу
        createMatrix(m, matrix1);
        sum1 = sumMatrix(m, matrix1);
        
        // Создаём вторую матрицу
        createMatrix(m, matrix2);
        sum2 = sumMatrix(m, matrix2);
        
        count++;
        
        if (count % 1000 == 0) {
            printf("Создано %d пар матриц...\n", count);
        }
        
    } while (sum1 != sum2);
    
    printf("Найдено совпадение после %d попыток!\n", count);
    fprintf(out, "Найдено совпадение после %d попыток\n", count);
    fprintf(out, "\nПервая матрица (сумма = %d):\n", sum1);
    printMatrix(out, m, matrix1);
    fprintf(out, "\nВторая матрица (сумма = %d):\n", sum2);
    printMatrix(out, m, matrix2);
    
    fclose(out);
    printf("Результаты записаны в output.txt\n");
    
    // --- 4. Замер времени ---
    end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Время работы программы: %.3f секунд\n", time_spent);
    
    return 0;
}
