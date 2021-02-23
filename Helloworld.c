#include <stdio.h>

int main(int numargs, char **argv){
	for(int i = 1; i<numargs;i++){
		printf("Hello World %s\n",argv[i]);
	}
	return 0;
}