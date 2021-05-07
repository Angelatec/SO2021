/*Jose Luis Aguilar Nucamendi
Marlene Rodríguez Harms
Dalia Rosalinda Vazquez Fonseca
Ángela Rodríguez Maldonado
*/

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

FILE *out;
FILE *in;

void signalHandler(int sig){
	
	fprintf(out, "quit\n");
	fflush(out);
	fclose(out);
	fclose(in);
	printf("\nSe ha terminado el proceso \n");
	 exit(-1);	
}

int main(){
	int fd1[2];
	int fd2[2];
	int pid;
	pipe(fd1);
	pipe(fd2);
	pid = fork();
		
	
	if (pid == 0){
		//hijo
		close(fd1[1]);
		close(fd2[0]);
		dup2(fd1[0], STDIN_FILENO);
		dup2(fd2[1], STDOUT_FILENO);
		//tenemos que guardar la función y el valor que nos pase el fd1 y meterlo en bc 
		execlp("bc", "bc","-l", (char*) NULL);
	}

	if (pid > 0){
		//padre 
		close(fd1[0]);
		close(fd2[1]);
		out = fdopen(fd1[1], "w");//acá escribimos
		in = fdopen(fd2[0], "r"); //de aquí leemos
		
		signal(2, signalHandler);
		while(1){//Inicializamos un bucle infinito que se romperá con ^C, Como? no sé pero lo descubriremos más adelante amiguitos
			char funcion[100];
			int ran1;
			int ran2;
			int puntos;
			float prom;
			float sum=0;
			float actual;
			
			printf("Ingresa la funcion\n");
			scanf("%s",funcion);
			while((fgetc(stdin))!='\n');
			printf("Ingresa el rango y los puntos a dividirlo:\n");
			scanf("%d %d %d", &ran1, &ran2, &puntos);
			
			//inicializamos la suma para después hacer el promedio, y se inicializa el valor actual en el inicio del rango 
			actual=ran1;
			
			for(int i=0;i<puntos;i++){ //cada vez tendrémos un punto a evaluar que hay que meter en el pipe con la función

				float aux;
				fprintf(out, "x=%f\n",actual); //aquí escribimos en el pipe1 la función y el valor actual
				fprintf(out, "%s\n",funcion);
				fflush(out);
				
				fscanf(in, "%f", &aux);// aquí leemos lo que puso el hijo en el pipe2
				
				sum+=aux;
				actual+=(ran2-ran1)/puntos;				
			}
			prom=sum/puntos;
			printf("%f\n",prom);
		}
		
	}
	return 0;
}