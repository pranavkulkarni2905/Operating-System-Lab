#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include<stdlib.h>
void fork_syscall() {
    pid_t pid = 0;
    int status;
    pid = fork();

    if (pid == 0) {
        printf("I am the child process\n");
        printf("It is the child process and pid is %d\n", getpid());
        execl("/bin/ls", "ls", "-l", "/home/pccoe/Downloads/", (char *)0);
        perror("In exec()");
    }

    if (pid > 0) {
        printf("I am the parent, and the pid is %d\n", getpid());
        pid = wait(&status);
        printf("End of process %d\n", pid);
    } else {
        printf("Process creation failed...!\n");
    }
}

void cp_syscall(int args, char **cp_args) {
    if(strcmp(cp_args[1],cp_args[2])!=0){

	    char fs[100];

	    FILE *fptr;
	    fptr=fopen(cp_args[1],"r+");

	   if(fptr){
		FILE *fn=fopen(cp_args[2],"a");
		while(fscanf(fptr,"%s",fs)!=EOF){
		    fprintf(fn,"%s\n",fs);
	   	}
	   	printf("content copied success...\n");
	   }else{

			printf("\n Opps.....File does not exist or failed to open..");
	    }
   }
}

void grep_syscall(int argc,char **cp_args){
	
	char fs[100];
	FILE *fptr;
	fptr=fopen(cp_args[3],"r+");
	
	if(fptr){
		if(strcmp(cp_args[1],"-c")==0){
			int count=0;
			if(argc>=2){
				while(fscanf(fptr,"%s",fs)!=EOF){
					
					if(strcmp(cp_args[2],fs)==0){
						count++;
					}
				
				}
			}
			printf("Count = %d\n",count);
		}
	}else{
		printf("\n OOpss...File does not exist or failed to open");
	}
	
	fclose(fptr);

}

int main() {
    int choice, ch;
    char input[20];
    char *cp_args[3];  
    char *com[4];

    do {
    	printf("\n--------- MENU -------------\n");
        printf("Press 1 : Fork sys call\n");
        printf("Press 2 : cp sys call\n");
	printf("Press 3 : grep sys call\n");
	printf("Press 4 : exec sys call\n");\
	printf("Press 5 : Exit\n");
        printf("Enter Your Choice :\n");
        printf("-----------------------------------------------\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            	 printf("\nExecuting FORK Command...\n");
                fork_syscall();
                break;

            case 2:
              
                cp_args[0] = "cp";
                cp_args[1] = "a.txt";
                cp_args[2] = "b.txt";
                printf("\nExecuting CP command..\n");
                cp_syscall(3, cp_args);
                break;
            case 3:
            	com[0]="grep";
            	com[1]="-c";
            	printf("\nEnter String to search in file : ");
            	scanf("%s",input);
            	com[2]=input;
            	com[3]="file.txt";
            	printf("\nExecuting GREP Command...\n");
            	grep_syscall(4,com);
            	
            	break;
            case 4:
            	printf("\nExecuting EXECL command...\n");
            	execl("/bin/ls", "ls", "-l", "/home/pccoe/Downloads/", (char *)0);
        	perror("In exec()\n");
            	break;
            case 5:
            	exit(0);
            	break;

            default:
                printf("Invalid choice..\n");
                break;
        }

        printf("\nDo you want to continue? Press 1: \n");
        scanf("%d", &ch);
    } while (ch == 1);

    return 0;
}
