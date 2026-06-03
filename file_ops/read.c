#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>

int main(){
	char b[100];
	int fd;
	fd=open("San.txt",O_RDONLY);
	int n;
	n=read(fd,b,sizeof(b));
	write(1,b,n);
	close(fd);
	}
