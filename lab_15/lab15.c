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
    int n;
    printf("please enter natural namber = ");
    scanf("%d", &n);

    printf("the numbers are one at a time, in the usual order: ");
    comm_v(n);
    printf("\n");

    printf("В обратном порядке: ");
    invert_v(n);
    printf("\n");

    return 0;
}