#include<stdio.h>
#include<unistd.h>


int main(){
	int pipefds[2];
	int returnstatus;
	char writemessage[2][20]={"Pranav","Gauri"};
	char readmessage[20];
	
	returnstatus=pipe(pipefds);
	
	if(returnstatus==-1){
		printf("\nUnable to create pipe");
		return 1;
	}
	
	
	printf("Writing to pipe -> Message 1 is %s\n",writemessage[0]);
	
	write(pipefds[1],writemessage[0],sizeof(writemessage[0]));
	
	read(pipefds[0],readmessage,sizeof(readmessage));
	
	printf("\nReading from pipe - Message 1 is %s\n",readmessage);
	
	printf("\nWriting to pipe - Message 2 is %s\n",writemessage[1]);
	
	write(pipefds[1],writemessage[1],sizeof(writemessage[1]));
	
	read(pipefds[0],readmessage,sizeof(readmessage));
	
	printf("\nReading from pipe - Message 2 is %s\n",readmessage);
	
	return 0;
}
