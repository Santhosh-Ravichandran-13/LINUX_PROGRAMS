#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

#define FIF01 "C_S"
#define FIF02 "S_C"

int main(){
	int fd_read,fd_write;
	int num,res;
	
	mkfifo(FIF01,0666);
	mkfifo(FIF02,0666);
	
	fd_write=open(FIF01,O_WRONLY);
	fd_read=open(FIF02,O_RDONLY);
	
	if(fd_read <0 || fd_write < 0){
		perror("Error opening File");
		return 1;
		}
	else{
	 printf("Enter Number : ");
    	 scanf("%d", &number);

    	write(fd_write, &number, sizeof(number));

    	printf("CLIENT SENT : %d\n", number);

    	read(fd_read, &result, sizeof(result));
	
    	printf("CLIENT RECEIVED SQUARE : %d\n", result);

    	close(fd_write);
    	close(fd_read);

    return 0;
}
