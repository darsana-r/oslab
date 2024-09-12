#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void * thread_function(void *args){
	printf("Inside the THREAD function\n");
	for(int i=0;i<5;i++){
		printf("Thread function %d\n",i);
		sleep(1);
	}
}

int main()
{
	pthread_t t1;
	pthread_create(&t1,NULL,thread_function,NULL);
	pthread_join(t1,NULL);
	printf("Inside MAIN THREAD\n");
	for(int i=500;i<505;i++){
		printf("Main thread %d\n",i);
		sleep(1);
	}
	pthread_exit(&t1);
}

/*

OUTPUT

pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp4/thread$ gcc -pthread thread.c
pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp4/thread$ ./a.out
Inside the THREAD function
Thread function 0
Thread function 1
Thread function 2
Thread function 3
Thread function 4
Inside MAIN THREAD
Main thread 500
Main thread 501
Main thread 502
Main thread 503
Main thread 504

*/
