#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<utime.h>

int main(){
	int f;
	struct stat st;
	f=open("Santhosh.txt",O_CREAT | O_RDWR,0644);
	if(f<0)
	{
		perror("CANNOT OPEN");
		return -1;
		}
	
	write(f,"File Metadata Control operation\n",31);
	
	printf("Stat\n");
	stat("Santhosh.txt",&st);
	printf("File Size:%ld bytes\n",st.st_size);
	printf("Permissions:%o\n",st.st_mode & 0777);
	
	printf("fstat\n");
	fstat(f,&st);
	printf("File Size:%ld bytes\n",st.st_size);
	
	printf("lstat\n");
	lstat("Santhosh.txt",&st);
	printf("File Size:%ld bytes\n",st.st_size);
	
	printf("Chmod\n");
	chmod("Santhosh.txt",0777);
	printf("Permissions changed to 0777\n");
		
	printf("utime\n");
	utime("San.txt",NULL);
	printf("Timesamp Updated\n");
	
	printf("fcntl()\n");
	fcntl(f,F_SETFL,O_NONBLOCK);
	printf("File descriptor set t NON BLOCKING mode\n");
	close(f);
	return 0;
	}
	
		
