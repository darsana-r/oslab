#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdlib.h>
void main()
{
	pid_t cpid;
	
	pid=fork();
	int var=10;
	if(pid==0){
		printf("I am child process pid is %d",getpid());
		var++;
		sleep(10);
		printf("Child terminated\n",var);
		exit(0);
	}else{
		
		printf("\nI am parent process, pid is %d",getpid());
		cpid=wait(NULL);
		printf("Parent process Terminated.pid is %d",getpid());
		
	}	

}


/*
pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab$ gcc forkexample.c
pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab$ ./a.out 

I am parent process, pid is 3274
var=15
I am child process pid is 3275
var=11

*/


