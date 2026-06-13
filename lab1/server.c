#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

#define FIF01 "C_S"
#define FIF02 "S_C"

int main(){
	int fd_read,fd_write;
	int num,res;
	
	fd_read=open(FIF01,O_RDONLY);
	fd_write=open(FIF02,O_WRONLY);
	
	if(fd_read<0 || fd_write<0){
		perror(" Error in opening file.");
		return 1;
		}
	else{
		
		read(fd_read,&num,sizeof(num));
		
		printf("SERVER RECIEVED :%d",num);
		
		res=num*num;
		write(fd_write,&res,sizeof(res));
		
		printf("SERVER SENT:%d",res);
		}
		
		close(fd_read);
		close(fd_write);
		return 0;
		}
		
