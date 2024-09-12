#include<stdio.h>
#include<sys/msg.h>
#include<sys/ipc.h>

#define MAX 50

struct msg{
	long mtype;
	char mtext[MAX];

}message;

int main()
{
	key_t key;
	int mqid;

	key=ftok("msgQ",55);
	mqid=msgget(key,0666|IPC_CREAT);
	message.mtype=1;

	printf("Enter the message : ");
	fgets(message.mtext,MAX,stdin);

	msgsnd(mqid,&message,50,0);
	
}

/*

OUTPUT

pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp3$ gcc mqsender.c
pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp3$ ./a.out
Enter the message : Hello WELCOME

*/
