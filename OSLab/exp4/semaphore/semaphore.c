#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>

int shared=1;

void * thread_increment(void *args){
	int local=shared;
	printf("Thread1 reads the value of shared variable as : %d\n",local);
	sleep(1);
	local=local+1;
	printf("Thread1 updates the value to %d\n",local);
	shared=local;
}

void * thread_decrement(void *args){
	int local=shared;
	printf("Thread2 reads the value of shared variable as : %d\n",local);
	sleep(1);
	local=local-1;;
	printf("Thread2 updates the value to %d\n",local);
	shared=local;
}

int main(){
	pthread_t t1,t2;
	printf("Initial value of shared variable :%d\n",shared);
	pthread_create(&t1,NULL,thread_increment,NULL);
	pthread_create(&t2,NULL,thread_decrement,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	printf("Final value of shared variable :%d\n",shared);
}


