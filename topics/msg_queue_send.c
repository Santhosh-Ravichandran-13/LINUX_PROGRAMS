#include<unistd.h>
#include<stdio.h>
#include<string.h>
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
	 m.mytype=1;
	 strcpy(m.msg,"hello Queue");
	 msgsnd(msgid,&m,sizeof(m.msg),0);
	 
	 printf("The Message Sent is :%s\n",m.msg);
	 	return 0;
	 	}
