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
	mqid=msgget(key,0666);

	msgrcv(mqid,&message,MAX,1,0);

	printf("%s",message.mtext);
	msgctl(mqid,IPC_RMID,NULL);

}

/*

OUTPUT

pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp3/msg_Q$ gcc mqsender.c
pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp3/msg_Q$ ./a.out
Enter the message : Hello Welcome                                            
pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp3/msg_Q$ gcc mqreceiver.c
pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp3/msg_Q$ ./a.out
Hello Welcome


*/
