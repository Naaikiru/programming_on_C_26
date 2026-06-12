#include <stdio.h>

void comm_v(int n) {
    if (n < 10) {
        printf("%d ", n);
        return;
    }
    comm_v(n / 10);
    printf("%d ", n % 10);
}

void invert_v(int n) {
    if (n < 10) {
        printf("%d ", n);
        return;
    }
    printf("%d ", n % 10);
    invert_v(n / 10);
}

int main() {
    int N;
    printf("Введите натуральное число: ");
    scanf("%d", &N);

    printf("В прямом порядке: ");
    comm_v(N);
    printf("\n");

    printf("В обратном порядке: ");
    invert_v(N);
    printf("\n");

    return 0;
}