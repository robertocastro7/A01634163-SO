#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
  int shmId = smhget(200, 400, 0644 | IPC_CREAT);
  int hijos[5];
  for(int i = 0; i < 5; i++){
    int pid = fork();
    hijos[i] = pid;
    if(pid != 0){
      shmId = smhget(200, 400, 0644);
      int * var = (int *)shmat(smhId, NULL, 0);
      var = &var[i*10];
      for(int j = 0; j < 10; j++){
        var[j] = i + '0';
      }
      return 0;
    }
  }
  for(int i = 0; i < 5; i++){
    waitpid(hijos[i], 0, 0);
  }
  int * var = (int *)shmat(smhId, NULL, 0);
  for(int i = 0; i < 100; i++){
    printf("El contenido es %d\n", var[i]);
  }
  return 0;
}
