#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
	int res,n;
	char buffer[100];
	res=open("FIFO",O_RDONLY);
	n=read(res,buffer,100);
	printf("message received successfully. pid is %d\n",getpid());
	write(1,buffer,n);
	
	close(res);
}


/*

OUTPUT

pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp3/named_pipe$ gcc named_pipe_sender.c -o sender
pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp3/named_pipe$ gcc named_pipe_receiver.c -o receiver
pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp3/named_pipe$ ./sender & ./receiver
[1] 3529
This message is send by process 3529
message received successfully. pid is 3530
This is my message
[1]+  Done 
*/
