#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct message{
	long mytype;
	char msg[100];
	};

int main(){
	key_t key=1234;
	int msgid=msgget(key,0666 | IPC_CREAT);
	 
	if(msgid<0){
		printf("Error");
		return 1;
		}
	
	struct message m;
	msgrcv(msgid,&m,sizeof(m.msg),1,0);
	printf("Received Message :%s\n",m.msg);
	return 0;
	}

	
