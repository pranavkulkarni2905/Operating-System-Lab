#include<assert.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

int main(){
	
	int fd[2],pid;
	int filedes=open("file1",O_RDONLY);
	dup2(filedes,0); // 0-> fileno(stdin)
	
	close(filedes);
	
	pipe(fd);
	
	if((pid=fork())==0){
		dup2(fd[1],1); // 1-> fileno(stdout)
		close(fd[0]);
		close(fd[1]);
		execl("/usr/bin/sort","sort",(char*)0);
	}else if(pid>0){
		dup2(fd[0],0);// 0-> fileno(stdin)
		close(fd[0]);
		close(fd[1]);
		execl("/usr/bin/uniq","uniq",(char*)0);
	}else{
		perror("fork");
		exit(1);
	}
	return 0;

}
