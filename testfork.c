#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int pid;
    pid = fork();
    if (pid != 0)
    {
        printf("Soy el proceso padre.\n");
    }
    else
    {
        printf("Soy el proceso hijo.\n");
    }
}
