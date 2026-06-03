#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	int fd;
	fd=open("San.txt",O_RDONLY);
	if(fd<0){
		perror("Cannot open");
		}
	close(fd);
	return 0;
	}
	
