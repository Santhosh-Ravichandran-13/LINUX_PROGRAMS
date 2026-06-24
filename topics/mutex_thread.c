#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
int shared=1;
pthread_mutex_t l;
void* func1(void *args){
	int x;
	printf("Thread1 is trying to lock.\n");
	pthread_mutex_lock(&l);
	printf("Thread1 is locked using the mutex.\n");
	x=shared;
	printf("The shared value is %d\n",x);
	x=x+2;
	sleep(1);
	shared=x;
	printf("The thread 1 updation of value is %d\n",shared);
	pthread_mutex_unlock(&l);
	printf("Thread1 released the lock\n");
	return NULL;
}
void* func2(void* args){
	int y;
	printf("Thread2 is trying to lock.\n");
	pthread_mutex_lock(&l);
	printf("Thread2 is locked using the mutex.\n");
	y=shared;
	printf("The shared value is %d\n",y);
	y=y+4;
	sleep(1);
	shared=y;
	printf("The thread 2 updation of value is %d\n",shared);
	pthread_mutex_unlock(&l);
	printf("Thread2 released the lock\n");
	return NULL;
}

int main(){
	pthread_t t1,t2;
	pthread_mutex_init(&l,NULL);
	pthread_create(&t1,NULL,func1,NULL);
	pthread_create(&t2,NULL,func2,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	printf("The final value is %d\n",shared);
	pthread_mutex_destroy(&l);
	}
	
