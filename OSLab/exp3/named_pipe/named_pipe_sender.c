#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{

	int res;
	char msg[]="This is my message\n";
	res=open("FIFO",O_WRONLY);
	write(res,msg,sizeof(msg));
	printf("This message is send by process %d\n",getpid());
}
