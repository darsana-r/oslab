#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
void main()
{
	
	execl("/bin/ls","ls","-l",NULL);

}

/*
pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab$ gcc execdemo.c
pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab$ ./a.out 
total 20
-rwxrwxr-x 1 pkd22it027 pkd22it027 8608 Jul 23 12:14 a.out
-rw-rw-r-- 1 pkd22it027 pkd22it027  115 Jul 23 12:14 execdemo.c
-rw-rw-r-- 1 pkd22it027 pkd22it027  383 Jul 23 11:58 forkexample.c

*/
