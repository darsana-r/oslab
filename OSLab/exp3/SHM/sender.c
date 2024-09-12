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
	shmid=shmget(key,1024,0666|IPC_CREAT);
	shared_memory=shmat(shmid,NULL,0);

	printf("Enter the message: ");
	fgets(shared_memory,100,stdin);

	printf("The sender message is %s",(char*)shared_memory);
	shmdt(shared_memory);

}

/*

OUTPUT

pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp3/SHM$ gcc sender.c
pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp3/SHM$ ./a.out
Enter the message: WELCOME TO SHM
The sender message is WELCOME TO SHM

*/
