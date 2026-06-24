#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
int main(){
	int fd;
	char buf[30];
	fd=open("test.txt",O_CREAT | O_WRONLY,0642);
	write(fd,"Hello Linux From Santhosh",25);
}
