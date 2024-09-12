#include<stdio.h>
#include<unistd.h>

int main()
{
	int fd[2],n;
	char msg[]="This is my message\n";
	char buffer[100];
	pid_t pid;
	pipe(fd);
	pid=fork();
	
	if(pid!=0){
		printf("This is a parent process and pid is %d\n",getpid());
		write(fd[1],msg,sizeof(msg));
	}else{
		printf("Child process pid is %d\n",getpid());
		n=read(fd[0],buffer,100);
		write(1,buffer,n);
	}
}




/*

OUTPUT 

pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp3/ord_pipe$ gcc ord_pipe.c
pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp3/ord_pipe$ ./a.out
This is a parent process and pid is 3450
Child process pid is 3451
This is my message


*/

