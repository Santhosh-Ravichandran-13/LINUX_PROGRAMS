#include<stdio.h>
#include<errno.h>

int main(){
 	FILE* f;
 	f=fopen("San.txt","r");
 	if(f==NULL){
 		perror("ERROR FILE");
 		printf("errno=%d\n",errno);
 		}
 	else{
 		printf("File is located");
 		}
 	}
