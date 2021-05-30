#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv) {
		
  char *filename = argv[1];
	char *tipo= argv[2];
	char *palabra=argv[3];
	char *sustituto=argv[4];
  FILE *forigen;
  forigen = fopen(filename,"r+b");
	STUDENT newstudent;
	while(fread(&newstudent, sizeof(newstudent),1, forigen)){
		if(strcmp(tipo,"name")==0){
			if(strcmp(palabra,newstudent.name)==0){
				 
				strcpy(newstudent.name,sustituto);
				printf("%s",newstudent.name);
				fseek(forigen,-1*sizeof(newstudent),SEEK_CUR);
				fwrite(&newstudent,sizeof(newstudent),1, forigen);
				fread(&newstudent,sizeof(newstudent),1, forigen);
			}
		}
		if(strcmp(tipo,"lastname")==0){
			if(strcmp(palabra,newstudent.lastname)==0){
				strcpy(newstudent.lastname,sustituto);
				fseek(forigen,-1*sizeof(newstudent),SEEK_CUR);
				fwrite(&newstudent,sizeof(newstudent),1, forigen);
				fread(&newstudent,sizeof(newstudent),1, forigen);
			}
		}
		if(strcmp(tipo,"id")==0){
			char snum[5];
			sprintf(snum, "%d", newstudent.id);
			
			if(strcmp(palabra,snum)==0){
				newstudent.id=atoi(sustituto);
				fseek(forigen,-1*sizeof(newstudent),SEEK_CUR);
				fwrite(&newstudent,sizeof(newstudent),1, forigen);	
				fread(&newstudent,sizeof(newstudent),1, forigen);
			}
		}
		
		if(strcmp(tipo,"semestre")==0){
			char snum[5];
			sprintf(snum, "%d", newstudent.semestre);
			if(strcmp(palabra,snum)==0){
				newstudent.semestre=atoi(sustituto);
				fseek(forigen,-1*sizeof(newstudent),SEEK_CUR);
				fwrite(&newstudent,sizeof(newstudent),1, forigen);
				fread(&newstudent,sizeof(newstudent),1, forigen);
			}
		}
		
	}

fclose(forigen);
}
