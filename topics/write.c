#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>
int main(){
	int fd;
	char msg[30];
	scanf("%s",msg);
	mkfifo("San",0666);
	fd=open("San",O_WRONLY);
	write(fd,msg,strlen(msg)+1);
	printf("Message Sent is:%s\n",msg);
	close(fd);
	return 0;
	}
