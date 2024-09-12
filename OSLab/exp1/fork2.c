#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
void main()
{
	fork();
	fork();
	fork();
	printf("hello\n");
	
}

/*
pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab$ gcc fork1.c
pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab$ ./a.out 
hello
hello
hello
hello
hello
hello
hello


*/
