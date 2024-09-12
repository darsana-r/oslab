#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/types.h>

int main()
{
	key_t key;
	int shmid;

	void * shared_memory;

	key=ftok("SHM",55);
	shmid=shmget(key,1024,0666);
	shared_memory=shmat(shmid,NULL,0);

	printf("The messege received is %s",(char*)shared_memory);
	shmdt(shared_memory);
	shmctl(shmid,IPC_RMID,shared_memory);
}

/*

OUTPUT

pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp3/SHM$ gcc receiver.c
pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp3/SHM$ ./a.out
The messege received is WELCOME TO SHM


*/
