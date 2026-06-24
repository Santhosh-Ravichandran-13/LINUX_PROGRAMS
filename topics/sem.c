#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
int sh=1;
sem_t s;
void* f1(void*args){
	int x;
	sem_wait(&s);
	x=sh;
	printf("The value is %d\n",x);
	x++;
	printf("Local updation o value is %d\n",x);
	sleep(1);
	sh=x;
	printf("The updated value  shared by thread 1 is %d\n",sh);
	sem_post(&s);
	return NULL;
	}
void* f2(void*args){
	int y;
	sem_wait(&s);
	y=sh;
	printf("The value is %d\n",y);
	y--;
	printf("Local updation o value is %d\n",y);
	sleep(1);
	sh=y;
	printf("The updated value shared by thread2 is  is %d\n",sh);
	sem_post(&s);
	return NULL;
	}
int main(){
	sem_init(&s,0,1);
	
	pthread_t t1,t2;
	pthread_create(&t1,NULL,f1,NULL);
	pthread_create(&t2,NULL,f2,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	printf("Final Value is %d\n",sh);
	sem_destroy(&s);
	
	}
	
