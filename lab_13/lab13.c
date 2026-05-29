#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handler(int sig)
{
    if (sig == SIGABRT)
    {
        printf("Signal handler SIGABRT: %d.\n", sig);
    }
    else if (sig == SIGFPE)
    {
        printf("Signal handler SIGFPE: %d.\n", sig);
    }
    else if (sig == SIGILL)
    {
        printf("Signal handler SIGILL: %d.\n", sig);
    }
    else if (sig == SIGINT)
    {
        printf("Signal handler SIGINT: %d.\n", sig);
    }
    else if (sig == SIGSEGV)
    {
        printf("Signal handler SIGSEGV: %d.\n", sig);
    }
    else if (sig == SIGTERM)
    {
        printf("Signal handler SIGTERM: %d.\n", sig);
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
        else if(chc == 1)
        {
            signal(SIGABRT, handler);
            printf("raise signal\n");
            raise(SIGABRT);
            signal(SIGABRT, SIG_DFL);
        }
        else if(chc == 2)
        {
            signal(SIGFPE, handler);
            printf("raise signal\n");
            raise(SIGFPE);
            signal(SIGFPE, SIG_DFL);
        }
        else if(chc == 3)
        {
            signal(SIGILL, handler);
            printf("raise signal\n");
            raise(SIGILL);
            signal(SIGILL, SIG_DFL);
        }
        else if(chc == 4)
        {
            signal(SIGINT, handler);
            printf("raise signal\n");
            raise(SIGINT);
            signal(SIGINT, SIG_DFL);
        }
        else if(chc == 5)
        {
            signal(SIGSEGV, handler);
            printf("raise signal\n");
            raise(SIGSEGV);
            signal(SIGSEGV, SIG_DFL);
        }
        else if(chc == 6)
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
        printf("OK\n");
    }
    
    return 0;
}