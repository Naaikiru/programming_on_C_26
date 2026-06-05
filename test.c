#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = getpid(); // получение идентификатора текущего процесса
    if (kill(pid, SIGTERM) == -1) {
        perror("Ошибка отправки сигнала");
        exit(1);
    }
    return 0;
}
