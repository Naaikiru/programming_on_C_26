#include <stdio.h>
#include <signal.h>

void handler(int sig)
{
    printf("Signal handler: %d.\n", sig);
}

int main(void)
{
    void (*f) (int); /* указатель на обработчик */

    signal(SIGTERM, handler);

    /* запоминаем предыдущий обработчик */
    f = signal(SIGINT, handler);
    if (f == SIG_ERR)
    {
    printf("Signal set failed.\n"); // неудача
    return 1;
    }

    printf("Raise signal.\n");
    if (raise(SIGINT) != 0)
    {
    printf("Raise failed.\n");
    return 2;
    }
    printf("OK.\n");

    /* восстанавливаем обработчик по умолчанию */
    signal(SIGINT, SIG_DFL);

    return 0;
}