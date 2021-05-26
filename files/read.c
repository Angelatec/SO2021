#include "student.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char **argv) {
		
  char *filename = argv[1];
  int cuantos= atoi(argv[2]);

  FILE *forigen;
  forigen = fopen(filename,"rb");
  for (int i = 0; i < cuantos; i++) {
    STUDENT newstudent;
	fread(&newstudent,sizeof(newstudent),1,forigen);
	 printf("%s %s %d %d \n",newstudent.name,newstudent.lastname,newstudent.id,newstudent.semestre);
  }
fclose(forigen);
}
