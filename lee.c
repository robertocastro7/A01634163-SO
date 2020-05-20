#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argh, char **argv){
  char *fileName = argv[1];
  char buffer;
  int fd = open(fileName, O_RDONLY);
  if(fd < 0){
    printf("No se puede abrir \n");
    exit(1);
  }
  while(read(fd,&buffer,1)){
    printf("%c",buffer);
  }
  close(fd);
  exit(0);
}
