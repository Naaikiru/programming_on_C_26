я люблю рыжих.

<img width="736" height="734" alt="South Park" src="https://github.com/user-attachments/assets/8a41c741-b4d7-41ce-b8f6-e05daf44c111" />




bkv.vvsu.ru/ftp — вай фай ввгу

bkv.net.ru/ftp — не вай фай ввгу


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Функция создания матрицы со случайными числами
void createMatrix(int n, int m, int matrix[n][m]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            matrix[i][j] = rand() % 21; // числа от 0 до 20
}

// Функция вывода матрицы в файл
void printMatrix(FILE *f, int n, int m, int matrix[n][m]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            fprintf(f, "%d ", matrix[i][j]);
        fprintf(f, "\n");
    }
}

// Функция сложения матриц
void addMatrices(int n, int m, int a[n][m], int b[n][m], int result[n][m]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            result[i][j] = a[i][j] + b[i][j];
}

// Функция умножения матриц (только для квадратных)
void multiplyMatrices(int n, int a[n][n], int b[n][n], int result[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++)
                result[i][j] += a[i][k] * b[k][j];
        }
    }
}

// Функция поиска минимального элемента и количества нечётных чисел
void findMinAndOdd(int n, int m, int matrix[n][m]) {
    int min = matrix[0][0], min_i = 0, min_j = 0, odd_count = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
                min_i = i;
                min_j = j;
            }
            if (matrix[i][j] % 2 != 0)
                odd_count++;
        }
    }
    
    printf("\n--- Анализ первой матрицы ---\n");
    printf("Минимальный элемент: %d на позиции [%d][%d]\n", min, min_i, min_j);
    printf("Количество нечётных чисел: %d\n", odd_count);
}

// Функция поиска строки или столбца с одинаковыми числами
void findSameRowCol(int n, int m, int matrix[n][m]) {
    int found = 0;
    
    // Проверка строк
    for (int i = 0; i < n; i++) {
        int same = 1;
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] != matrix[i][0]) {
                same = 0;
                break;
            }
        }
        if (same) {
            printf("Строка %d состоит из одинаковых чисел (%d)\n", i, matrix[i][0]);
            found = 1;
        }
    }
    
    // Проверка столбцов
    for (int j = 0; j < m; j++) {
        int same = 1;
        for (int i = 1; i < n; i++) {
            if (matrix[i][j] != matrix[0][j]) {
                same = 0;
                break;
            }
        }
        if (same) {
            printf("Столбец %d состоит из одинаковых чисел (%d)\n", j, matrix[0][j]);
            found = 1;
        }
    }
    
    if (!found)
        printf("Нет строк или столбцов с одинаковыми числами\n");
}

int main() {
    clock_t start, end;
    start = clock();
    
    int n, m;
    srand(time(NULL));
    
    // --- Шаг 1: Создание input.txt с двумя случайными матрицами ---
    printf("Введите размер матриц (строки столбцы): ");
    scanf("%d %d", &n, &m);
    
    int a[n][m], b[n][m];
    
    // Создаём матрицы
    createMatrix(n, m, a);
    createMatrix(n, m, b);
    
    // Записываем в файл
    FILE *f = fopen("input.txt", "w");
    if (f == NULL) {
        printf("Ошибка создания input.txt\n");
        return 1;
    }
    
    // Первая матрица
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            fprintf(f, "%d ", a[i][j]);
        fprintf(f, "\n");
    }
    fprintf(f, "\n"); // разделитель
    
    // Вторая матрица
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            fprintf(f, "%d ", b[i][j]);
        fprintf(f, "\n");
    }
    fclose(f);
    printf("Файл input.txt создан\n");
    
    // Очищаем массивы
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            b[i][j] = 0;
    printf("Массивы очищены\n");
    
    // --- Шаг 2: Чтение из input.txt и операции ---
    f = fopen("input.txt", "r");
    if (f == NULL) {
        printf("Ошибка открытия input.txt\n");
        return 1;
    }
    
    // Читаем первую матрицу
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            fscanf(f, "%d", &a[i][j]);
    
    // Читаем вторую матрицу
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            fscanf(f, "%d", &b[i][j]);
    fclose(f);
    
    // Сложение
    int sum[n][m];
    addMatrices(n, m, a, b, sum);
    
    // Умножение (только если квадратные)
    int prod[n][m];
    if (n == m) {
        multiplyMatrices(n, a, b, prod);
    }
    
    // Запись результатов в output.txt
    FILE *out = fopen("output.txt", "w");
    if (out == NULL) {
        printf("Ошибка создания output.txt\n");
        return 1;
    }
    
    fprintf(out, "=== Исходные матрицы ===\n\n");
    fprintf(out, "Матрица A:\n");
    printMatrix(out, n, m, a);
    fprintf(out, "\nМатрица B:\n");
    printMatrix(out, n, m, b);
    
    fprintf(out, "\n=== Результаты операций ===\n\n");
    fprintf(out, "Сумма матриц:\n");
    printMatrix(out, n, m, sum);
    
    if (n == m) {
        fprintf(out, "\nПроизведение матриц:\n");
        printMatrix(out, n, m, prod);
    } else {
        fprintf(out, "\nУмножение невозможно (матрицы не квадратные)\n");
    }
    
    fclose(out);
    printf("Результаты записаны в output.txt\n");
    
    // --- Шаг 3: Поиск минимума и нечётных чисел в первой матрице ---
    findMinAndOdd(n, m, a);
    
    // --- Шаг 4: Поиск строки/столбца с одинаковыми числами ---
    findSameRowCol(n, m, a);
    
    // --- Шаг 5: Замер времени ---
    end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nВремя работы программы: %.3f секунд\n", time_spent);
    
    return 0;
}
