#include<stdio.h>

#include<string.h>
#include<stdlib.h>

int process[10],arrival_time[10],burst_time[10],waiting_time[10],turnaround_time[10];
float avg_waiting_time,avg_turnaround_time;
int total_wait_time=0,total_turnaround_time=0;
int n,i,j,temp;

void part1(){
	
	printf("\nEnter How Many Process do u want : ");
	scanf("%d",&n);
	
	printf("\nEnter %d process : ",n);
	for(i=0;i<n;i++){
		scanf("%d",&process[i]);
	}
	
	printf("enter %d arrival time:",n);
	for(i=0;i<n;i++)
	{
	    scanf("%d",&arrival_time[i]);
        }
	printf("enter %d burst time:",n);
	for(i=0;i<n;i++)
	{
	    scanf("%d",&burst_time[i]);
	}

}
void part2(){
	waiting_time[0]=0;
	turnaround_time[0]=waiting_time[0]+burst_time[0];
	for(i=1;i<n;i++){
	
		waiting_time[i]=burst_time[i-1]+waiting_time[i-1];
		turnaround_time[i]=waiting_time[i]+burst_time[i];
		total_wait_time+=waiting_time[i];
		total_turnaround_time+=turnaround_time[i];
	}
	avg_waiting_time=total_wait_time/n;
	avg_turnaround_time=total_turnaround_time/n;
	printf("\np\t A.T\t B.T\t TAT\t WT");
	
	for(i=0;i<n;i++)
    	{
    		printf("\n----------------------------------------------------------------------------------");
      		printf("\nP%d\t %d\t %d \t %d \t %d",process[i],arrival_time[i],burst_time[i],turnaround_time[i],waiting_time[i]);
    	}
    	printf("\naverage turnaround time is %f",avg_turnaround_time);

    	printf("\naverage wating timme is %f",avg_waiting_time);
}
void fcfs_scheduling(){
	
	part1();
	for(i=0;i<n;i++)
	{
	     for(j=0;j<(n-i);j++)
	    {
		      if(arrival_time[j]>arrival_time[j+1])
		     {
				temp=process[j+1];
				process[j+1]=process[j];
				process[j]=temp;
				
				temp=arrival_time[j+1];
				arrival_time[j+1]=arrival_time[j];
				arrival_time[j]=temp;
				
				temp=burst_time[j+1];
				burst_time[j+1]=burst_time[j];
				burst_time[j]=temp;
		      }
	     }
	}
	part2();
	
}

void sjf_scheduling(){
	
	part1();	
	for(i=0;i<n;i++)
	{
	     for(j=0;j<(n-i-1);j++)
	    {
		      if(burst_time[j]>burst_time[j+1])
		     {
				temp=process[j+1];
				process[j+1]=process[j];
				process[j]=temp;
				
				temp=burst_time[j+1];
				burst_time[j+1]=burst_time[j];
				burst_time[j]=temp;
				
				temp=arrival_time[j+1];
				arrival_time[j+1]=arrival_time[j];
				arrival_time[j]=temp;
				
		      }
	     }
	}
	
	part2();

}

void round_robin_scheduling(){

}


void priority_scheduling(){

}

int main(){
	int choice,ch;
	do{
		printf("\n1.FCFS\n2.SJF\n3.Round Robin\n4.Priority\n5.Exit");
		printf("\nEnter Your choice :");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				fcfs_scheduling();
				break;
			case 2:
				sjf_scheduling();
				break;
				
			case 3:
				round_robin_scheduling();
				break;
			case 4:
				priority_scheduling();
				break;
			case 5:
				exit(0);
				break;
			default:
				break;
		}
		printf("\n-------------------------------------------------");
		printf("\nDo You want to continue press 1 :\n");
		scanf("%d",&ch);
	}while(ch==1);
	return 0;
}
