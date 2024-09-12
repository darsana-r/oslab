#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){
	int res;
	res=mkfifo("FIFO",0777);
	printf("a pipe named FIFO is created\n");
}

/*

OUTPUT

pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp3/named_pipe$ gcc named_pipe.c
pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp3/named_pipe$ ./a.out
a pipe named FIFO is created


*/
