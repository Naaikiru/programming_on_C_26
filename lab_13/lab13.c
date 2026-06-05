#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig)
{
    if (sig == SIGABRT)
    {
        printf("Signal handler SIGABRT: %d.\n", sig);
        exit(0);
    }
    else if (sig == SIGFPE)
    {
        printf("Signal handler SIGFPE: %d.\n", sig);
        exit(0);
    }
    else if (sig == SIGILL)
    {
        printf("Signal handler SIGILL: %d.\n", sig);
        exit(0);
    }
    else if (sig == SIGINT)
    {
        printf("Signal handler SIGINT: %d.\n", sig);
        exit(0);
    }
    else if (sig == SIGSEGV)
    {
        printf("Signal handler SIGSEGV: %d.\n", sig);
        exit(0);
    }
    else if (sig == SIGTERM)
    {
        printf("Signal handler SIGTERM: %d.\n", sig);
        exit(0);
    }
}

int main(void)
{
    int chc;

    printf("choose SIGNALS!\n");
    printf("1 - SIGABRT\n");
    printf("2 - SIGFPE\n");
    printf("3 - SIGILL\n");
    printf("4 - SIGINT\n");
    printf("5 - SIGSEGV\n");
    printf("6 - SIGTERM\n");
    printf("0 - exit.\n");

    while(1)
    {
        printf("choose!: ");
        scanf("%d", &chc);

        if (chc == 0)
        {
            return 0;
        }
        else if(chc == 1)//	Сигнал аварийного завершения процесса.
        {
            signal(SIGABRT, handler);
            printf("calling abort()...\n");
            abort();
            signal(SIGABRT, SIG_DFL);
        }
        else if(chc == 2)//Некорректная арифметическая операция.
        {
            signal(SIGFPE, handler);
            int a = 5, b = 0;
            printf("dividing by zero...\n");
            int c = a / b;
            signal(SIGFPE, SIG_DFL);
        }
        else if(chc == 3)//Некорректная команда.
        {
            signal(SIGILL, handler);
            printf("illegal instruction...\n");
            __builtin_trap();
            signal(SIGILL, SIG_DFL);
        }
        else if(chc == 4)//	Сигнал прерывания
        {
            signal(SIGINT, handler);
            while(1)
            {
                printf("hello mister fish!\n");
                sleep(1);
            }
        }
        else if(chc == 5)//Некорректное обращение к памяти.
        {
            signal(SIGSEGV, handler);
            int *ptr = NULL;
            printf("NULL pointer...\n");
            *ptr = 67;
            signal(SIGSEGV, SIG_DFL);
        }
        else if(chc == 6)//Подразумеваемая реакция - аварийное завершение процесса
        {
            signal(SIGTERM, handler);
            printf("raise signal\n");
            raise(SIGTERM);
            signal(SIGTERM, SIG_DFL);
        }
        else
        {
            printf("wrong enter!\n");
            continue;
        }
    }
    
    return 0;
}