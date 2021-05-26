#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/*int main(){
    char fun[20];
    float inicio,final,puntos;
    int pah[2];
    int hap[2];
    pipe(pah);
    pipe(hap);
    int pid = fork();
	if(pid==0){
		// Hijo
        // connect pc2p to stdout
        close(pah[1]);
        close(hap[0]);
        //(pah[0], hap[1]);
        FILE *in = fdopen(pah[0], "r");
        FILE *out = fdopen(hap[1], "w");
        char params[50];
        fscanf(in,"%s",params);
        printf("%s\n",params);
		//execl("/usr/bin/bc","bc","-l",params,NULL);
	}
	if(pid>0){
		// Padre
		close(pah[0]);
        close(hap[1]);
        FILE *out = fdopen(pah[1], "w");
        FILE *in = fdopen(hap[0], "r");
        int sum=0;
        
        scanf("%s",fun);
        printf("%s",fun);
        scanf("%f %f %f",&inicio,&final,&puntos);
        
        /*
        while(fscanf(in, "%s", fun) !=EOF){
				printf("%s\n", fun);
			}
			fclose(in);
            
        //fprintf(out,"x=%f\n %s\n",inicio,fun);
        //fprintf(out,"x=%f %s",inicio,fun);
        //fprintf(out,"%f %f",inicio,final);

	}*/
    
	int main(){
		int p1[2]; //P->C Padre
		int p2[2]; //C->P Child
		
		//Inicializar Pipes
		pipe(p1);
		pipe(p2);
		
		int pid = fork();
		
		
		if(pid==0){
			//Child
			close(p1[1]); //Entrada write padre
			close(p2[0]); //Salida read hijo
			
			//Conectar los pipes a STDIN Y STDOUT
			dup2(p1[0], STDIN_FILENO);
			close(p1[0]);
			
			dup2(p2[1], STDOUT_FILENO);
			close(p2[1]);
			
			execlp("bc", "bc","-l", (char*) NULL);
			
			
		}
		if(pid>0){
			//Parent
			close(p1[0]); //Salida read
			close(p2[1]); //Entrada Write
			
			FILE *out = fdopen(p1[1], "w");
        	FILE *in = fdopen(p2[0], "r");
			
			while(1){
				//Leer la funciรณn 
				char funcion [25]; 
				
				//Rango
				int min, max, divs;
				
				float sum = 0;
				
				//Escribir funciรณn
				printf("Ingresa a la funciรณn: ");
				
				//Guardar funcion
				scanf("%s", funcion);
				
				while((fgetc(stdin))!='\n');
				
				
				//Escribir funciรณn
				printf("Ingresa el rango y la divisiรณn: ");
				
				//Guardar funcion
				scanf("%d %d %d", &min, &max, &divs);
				
				
				
				float incremento = 0;
				for(int i = 0; i<divs; i++){
					float tmp;
					
					fprintf(out,"x=%f\n", incremento);
					
					fprintf(out, "%s\n", funcion);
					
					fflush(out);
					
					fscanf(in, "%f", &tmp);
					
					sum += tmp; 
					
					incremento+= (max-min)/divs;
						
				}
				printf("%f\n", sum/divs);
			}
			
		}return 0;
		
		
		
	}