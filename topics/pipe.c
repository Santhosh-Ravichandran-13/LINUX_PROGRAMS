#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
	int fd[2];
	char buf[20];
	pid_t pid;
	pipe(fd);
	pid=fork();
	
	if(pid==0){
		close(fd[1]);
		read(fd[0],buf,sizeof(buf));
		printf("Child  recieved is %s\n",buf);
		close(fd[0]);
		}
	else if(pid>0){
		close(fd[0]);
		char msg[]="hello pipe msg";
		write(fd[1],msg,15);
		close(fd[1]);
		}
	else{
		printf("error");
		return 0;
		}
	return 0;
	}
