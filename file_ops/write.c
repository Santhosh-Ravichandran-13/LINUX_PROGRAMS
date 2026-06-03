#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	int fd;
	fd=open("San.txt",O_WRONLY | O_CREAT,0644);
	write(fd,"First file write operation",26);
	close(fd);
	}
