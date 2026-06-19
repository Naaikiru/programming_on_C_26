#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 1. Заполняет матрицу случайными числами от 0 до 20
void createMatrix(int n, int m, int matrix[n][m]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            matrix[i][j] = rand() % 21;
}

// 2. Выводит матрицу в файл
void printMatrix(FILE *f, int n, int m, int matrix[n][m]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            fprintf(f, "%d ", matrix[i][j]);
        fprintf(f, "\n");
    }
}

// 3. Складывает две матрицы
void addMatrices(int n, int m, int a[n][m], int b[n][m], int result[n][m]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            result[i][j] = a[i][j] + b[i][j];
}

// 4. Умножает две квадратные матрицы
void multiplyMatrices(int n, int a[n][n], int b[n][n], int result[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++)
                result[i][j] += a[i][k] * b[k][j];
        }
    }
}

// 5. Находит минимальный элемент и считает нечётные числа
void findMinAndOdd(int n, int m, int matrix[n][m]) {
    int min = matrix[0][0];
    int odd_count = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] < min)
                min = matrix[i][j];
            if (matrix[i][j] % 2 != 0)
                odd_count++;
        }
    }
    
    printf("\n--- Анализ первой матрицы ---\n");
    printf("Минимальный элемент: %d\n", min);
    printf("Количество нечётных чисел: %d\n", odd_count);
}

// 6. Проверяет, есть ли строка или столбец с одинаковыми числами
void findSameRowCol(int n, int m, int matrix[n][m]) {
    int found = 0;
    
    // Проверяем строки
    for (int i = 0; i < n; i++) {
        int same = 1;
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] != matrix[i][0]) {
                same = 0;
                break;
            }
        }
        if (same) {
            printf("Строка %d состоит из одинаковых чисел\n", i);
            found = 1;
        }
    }
    
    // Проверяем столбцы
    for (int j = 0; j < m; j++) {
        int same = 1;
        for (int i = 1; i < n; i++) {
            if (matrix[i][j] != matrix[0][j]) {
                same = 0;
                break;
            }
        }
        if (same) {
            printf("Столбец %d состоит из одинаковых чисел\n", j);
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
    
    // Просим пользователя ввести размер матриц
    printf("Введите размер матриц (строки столбцы): ");
    scanf("%d %d", &n, &m);
    
    int a[n][m], b[n][m];
    
    // Создаём две матрицы со случайными числами
    createMatrix(n, m, a);
    createMatrix(n, m, b);
    
    // Записываем матрицы в файл input.txt
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
    fprintf(f, "\n");
    
    // Вторая матрица
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            fprintf(f, "%d ", b[i][j]);
        fprintf(f, "\n");
    }
    fclose(f);
    printf("Файл input.txt создан\n");
    
    // Очищаем матрицы (для примера)
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            b[i][j] = 0;
    printf("Матрицы очищены\n");
    
    // Читаем матрицы из файла обратно
    f = fopen("input.txt", "r");
    if (f == NULL) {
        printf("Ошибка открытия input.txt\n");
        return 1;
    }
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            fscanf(f, "%d", &a[i][j]);
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            fscanf(f, "%d", &b[i][j]);
    fclose(f);
    
    // Складываем матрицы
    int sum[n][m];
    addMatrices(n, m, a, b, sum);
    
    // Умножаем матрицы (только если они квадратные)
    int prod[n][m];
    if (n == m) {
        multiplyMatrices(n, a, b, prod);
    }
    
    // Записываем результаты в output.txt
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
    
    // Анализируем первую матрицу
    findMinAndOdd(n, m, a);
    findSameRowCol(n, m, a);
    
    // Выводим время работы программы
    end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nВремя работы программы: %.3f секунд\n", time_spent);
    
    return 0;
}