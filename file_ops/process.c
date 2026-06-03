#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h>

int main(){
	pid_t pid1,pid2;
	int s;
	
	printf("Parent Process PID=%d\n",getpid());
	
	pid1=fork();
	
	if(pid1<0){
		perror("Fork");
	exit(1);
	}
	if(pid1==0){
		printf("Child Process 1\n");
		printf("Child process 1 PID=%d\n",getpid());
		printf("Running Execl\n");
		execl("/bin/ls","ls","-1",NULL);
		
		perror("Execl failed");
		exit(10);
		}
		else{
			wait(&s);
			printf("\nPatrent :child 1 finished\n");
			if(WIFEXITED(s)){
				printf("EXIT Status =%d\n",WIFEXITED(s));
			}
			
			}
		pid2=fork();
		if(pid2<0){
		perror("Fork");
		exit(1);
		}
		if(pid2==0){
			printf("Child 2\n");
			
			char *args[]={"date",NULL};
			printf("Execvp\n");
			
			execvp("date",args);
			perror("Execvp failed");
			exit(20);
			}
			else{
			waitpid(pid2,&s,0);
			printf("\n parent : child2 finished\n");
			if(WIFEXITED(s)){
				printf("Exit status=%d\n",WIFEXITED(s));
				}
				}
			printf("\nParent process exiting\n");
			 exit(0);
			 }
			
