#include <stdio.h>
#include <malloc.h>
#include <string.h>
int main(int argnum, char **argv){
    char *original = argv[1];
    char *destino = argv[2];
    char buffer;
    int size;
    FILE *foriginal, *fdestino;
    foriginal = fopen(original,"rb");
    fdestino = fopen(destino,"wb");

    while(fread(&buffer,sizeof(char),1,foriginal) ){
		char c=size;
		printf("%c",c);
        if(buffer == '\n'){
            char *linea;
            size += 1;
            fseek(foriginal, -size, SEEK_CUR);
            linea = (char *) calloc(size, sizeof(char)); // linea[size];
            fread(linea,sizeof(char),size,foriginal);
			printf("Lineaa\n");
			printf(linea);
            if(strstr(linea,"hola") == NULL){
				printf("No hola en esta \n");
				//fwrite(fdestino,sizeof(char),size,"Si entiendo");
                fwrite(fdestino,sizeof(char),size,linea);
            }
			fseek(foriginal, +size, SEEK_CUR);
			size = 0;
        } else {
            size += 1;
        }
        //fwrite(&buffer,sizeof(char),1,fdestino);
    }
	
    fclose(foriginal);
    fclose(fdestino);

    return 0;
}