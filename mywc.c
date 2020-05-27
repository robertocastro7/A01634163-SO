#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argn, char **argv){
    char *filename = argv[1];
    char buffer;
    char espacio = 0;
    int fd = open(filename, O_RDONLY);
    if (fd < 0){
        printf("No se pudo abrir \n");
        exit(1);
    }
    unsigned int numChar = 0, numNewL = 0, numWord = 0;
    while(read(fd, &buffer, 1)) {
        numChar++;
        if (buffer == 10) numNewL++;
        if ((buffer == ' ' || buffer == '\n' ) && espacio == 0) {
            espacio = 1;
            numWord++;
        } else if (buffer != ' ' && buffer != '\n' ) {
            espacio = 0;
        }
    }
    printf("chars | lines | words | file\n");
    printf("%5d   %5d   %5d  %s\n", numChar, numNewL, numWord, filename);
    close(fd);
    exit(0);

}
