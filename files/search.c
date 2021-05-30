#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv) {
		
  char *filename = argv[1];
	char *tipo= argv[2];
	char *palabra=argv[3];
  FILE *forigen;
  forigen = fopen(filename,"rb");
	STUDENT newstudent;
	while(fread(&newstudent, sizeof(newstudent),1, forigen)){
		if(strcmp(tipo,"name")==0){
			if(strcmp(palabra,newstudent.name)==0){
				printf("%s %s %d %d \n",newstudent.name,newstudent.lastname,newstudent.id,newstudent.semestre);
			}
		}
		if(strcmp(tipo,"lastname")==0){
			if(strcmp(palabra,newstudent.lastname)==0){
				printf("%s %s %d %d \n",newstudent.name,newstudent.lastname,newstudent.id,newstudent.semestre);
			}
		}
		if(strcmp(tipo,"id")==0){
			char snum[5];
			sprintf(snum, "%d", newstudent.id);
			//itoa(newstudent.id, snum, 10);
			if(strcmp(palabra,snum)==0){
				printf("%s %s %d %d \n",newstudent.name,newstudent.lastname,newstudent.id,newstudent.semestre);
			}
		}
		
		if(strcmp(tipo,"semestre")==0){
			char snum[5];
			sprintf(snum, "%d", newstudent.semestre);
			//itoa(newstudent.semestre, snum, 10);
			if(strcmp(palabra,snum)==0){
				printf("%s %s %d %d \n",newstudent.name,newstudent.lastname,newstudent.id,newstudent.semestre);
			}
		}
		
	}
  

fclose(forigen);
}
