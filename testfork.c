#include <stdio.h>

int main() {
    int pid;
    pid = fork();
    if (pid != 0)
    {
        printf("Soy el proceso padre.");
    }
    else
    {
        printf("Soy el proceso hijo.");
    }
}
