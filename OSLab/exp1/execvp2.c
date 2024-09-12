#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
void main()
{
	char *argv[]={NULL};
	printf("I am execvp2 Pid is %d\n",(int)getpid());
	execvp("./execvp",argv);
	printf("Terminated\n");

}


/*

pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab$ gcc execvp.c -o execvp
pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab$ ./execvp

pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab$ gcc execvp2.c 
pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab$ ./a.out 
I am execvp2 Pid is 8071
I am execvp. Pid is 8071

*/
