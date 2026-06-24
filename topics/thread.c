#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void* msg_func(void*args){
	char*msg=(char*)args;
	printf("%s\n",msg);
	return NULL;
}
int main(){
	pthread_t t;
	char msg[]="Hello from santhosh";
	pthread_create(&t,NULL,msg_func,msg);
	pthread_join(t,NULL);
	return 0;
}

