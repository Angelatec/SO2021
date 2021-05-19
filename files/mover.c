#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argvnum, char **argv){
    char argsuma[50];
    char *arg1 = argv[1];
    char *arg2 = argv[2];
    struct stat sb1, 
                sb2;
//Si arg1 existe y arg2 no existe renombra
    //Si arg2 existe : Error
    if(stat(arg1, &sb1) == 0){
        printf("Archivo 1 valido \n");
        if(stat(arg2, &sb2) == 0 && !S_ISDIR(sb2.st_mode)){
            printf("Error: El archivo 2 ya existe \n");
            return -1;
        }
    //Si arg1 existe y arg2 es directorio mueve arg1 a arg2
        if(stat(arg2, &sb2) == 0 && S_ISDIR(sb2.st_mode)){
            strcat(strcpy(argsuma,arg2),"/");
            strcat(strcpy(argsuma,argsuma),arg1);
            link(arg1,argsuma);
            unlink(arg1);
        }
        if(stat(arg2, &sb2) == -1 && !S_ISDIR(sb2.st_mode)){
            link(arg1, arg2);
            unlink(arg1);
        }
        
    }      
}