#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

//typedef int entere; //crear un alias

typedef struct m{
	char status;
	int data[4];
} MyData;

int main(){
	MyData *datos;
	int key = 27;
	int shmId = shmget(key, sizeof(MyData), IPC_CREAT | 0666);
	datos = (MyData *)shmat(shmId, NULL, 0); //casteo del apuntador al objeto definido arriba
	datos->status='n'; //parte de sincronización 
	datos->data[0] = 40;
	datos->data[1] = 30;
	datos->data[2] = 20;
	datos->data[3] = 10;
	datos->status = 'r';
	while(datos->status != 't'){
		sleep(1);
	}
	
	printf("los datos han sido consumidos \n");
	return(0);
}