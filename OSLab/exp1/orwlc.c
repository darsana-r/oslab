#include<fcntl.h>
#include <stdio.h>
#include<sys/types.h>
#include<sys/stat.h>

void main(){
	int fd;
	char wbuf[100]="Hello world\n";
	char rbuf[100];
	fd=open("file1.txt",O_RDWR|O_CREAT,S_IRWXU);
	write(fd,wbuf,strlen(wbuf));
	lseek(fd,5,SEEK_SET);
	read(fd,rbuf,100);
	printf(rbuf);
}

/*
pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab$ gcc orwlc.c
pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab$ ./a.out 
Hello world

*/
