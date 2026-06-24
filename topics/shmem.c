#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
int main(){
	key_t key=1234;
	int shmid=shmget(key,1024,0666 | IPC_CREAT);
	if(shmid<0){
		printf("Eroor");
		return 1;
		}
	char *msg=(char*)shmat(shmid,NULL,0);
	strcpy(msg,"Hello Shared Memory");
	printf("Stored Message is %s",msg);
	shmdt(msg);
	return 0;
	}
