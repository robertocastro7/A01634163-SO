#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void processSignal(int s) {
    printf("Recibí la s %d\n", s);
}

void notKill(int s) {
    printf("No me mataste -9\n");
}

int main() {
    signal(10, processSignal);
    signal(15, notKill);
    while(1) {
        sleep(3);
        printf("Working...\n");
    }
    return 0;
}
