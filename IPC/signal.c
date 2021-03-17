#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int varGlobal;

void signalHandler(int sig){
  printf("Recibi segnal %d\n", sig);
	if(sig==2||sig==15)varGlobal=1;
}

int main(){
  signal(2, signalHandler);
  signal(15, signalHandler);
  while(1){
	  if(varGlobal==1)break;
    printf("Trabajando\n");
    sleep(1);
  }
  printf("Ya voy a terminar \n");
  return 0;
}