#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	char buf[20];
	int fd;
	fd=open("San",O_RDONLY);
	read(fd,buf,sizeof(buf));
	printf("Message recived is %s\n",buf);
	close(fd);
	return 0;
	}
