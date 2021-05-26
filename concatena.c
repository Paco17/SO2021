#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    string palabra[] = "";
    
    if(argc == 1){
        printf("No diste valores \n");
        
    }else{
        
        for(int i=argc; i>1; i--){
        	strcat(palabra, argv[i]);
		}
    }
    printf(palabra);
   return 0;
}
