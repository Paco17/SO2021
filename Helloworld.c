#include <stdio.h>

int main(int numargs, char **argv){
	for(int i = 0; i<numargs; i++){
		//printf("Hello World %s\n",argv[i]);
		int begin, end, count = 0;
		while(argv[i][count] != '\0')
			count++;
		
		end = count - 1;
		
		while(begin<end){
			argv[i][begin] = argv[i][end];
			begin++;
			end--;
		}
		
		//argv[i][begin] = '\0';
		
		printf("Hello World %s\n", argv[i]);
		
	}
	return 0;
}