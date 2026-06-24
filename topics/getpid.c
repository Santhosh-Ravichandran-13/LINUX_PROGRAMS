#include<stdio.h>
#include<unistd.h>

int main(){
	pid_t pid;
	pid=getpid();
	printf("Running Program ID is:%d",pid);
	return 0;
}
