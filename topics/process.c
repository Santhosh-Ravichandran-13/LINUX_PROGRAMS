#include<stdio.h>
#include<unistd.h>

int main(){
	pid_t pid;
	pid=fork();
	if(pid<0){
	   printf("Error");
	   return 0;
	}
	else if(pid==0){
	printf("I am Child and My Id is %d\n",getpid());
	printf("My Parent Id is :%d\n",getppid());
	}
	else{
	printf("I am Parent and My id is %d\n",getpid());
	printf("My Child is %d",pid);
	}
return 0;
}
