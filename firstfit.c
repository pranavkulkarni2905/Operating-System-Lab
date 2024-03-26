
#include<stdio.h> 


void firstFit(int blockSize[], int m, int processSize[], int n) 
{ 
	int i, j; 
	
	int allocation[n]; 

	
	for(i = 0; i < n; i++) 
	{ 
		allocation[i] = -1; 
	} 
	
	
	for (i = 0; i < n; i++)	 
	{ 
		for (j = 0; j < m; j++)	 
		{ 
			if (blockSize[j] >= processSize[i]) 
			{ 
				
				allocation[i] = j; 

				
				blockSize[j] -= processSize[i]; 

				break; 
			} 
		} 
	} 

	printf("\nProcess No.\tProcess Size\tBlock no.\n"); 
	for (int i = 0; i < n; i++) 
	{ 
		printf(" %i\t\t\t", i+1); 
		printf("%i\t\t", processSize[i]); 
		if (allocation[i] != -1) 
			printf("%i", allocation[i] + 1); 
		else
			printf("Not Allocated"); 
		printf("\n"); 
	} 
	
	printf("\nRemaining sizes of block.\n");
	
	printf("Block no\tRemaining size\n");
	
	for (int i=0; i<m; i++){
	printf("\n%d\t\t%d", i+1, blockSize[i]);
	}
} 


int main() 
{ 
	int m; //number of blocks in the memory 
	int n; //number of processes in the input queue 
	printf("Enter no of blocks in memory : ");
	scanf("%d",&m);
	printf("Enter no of processes : ");
	scanf("%d",&n); 
	int blockSize[m]; 
	int processSize[n];
	
	printf("Enter the block sizes : \n");
	for (int i=0; i<m; i++){
		scanf("%d", &blockSize[i]);
	} 
	
	printf("Enter the process sizes : \n");
	for (int i=0; i<n; i++){
		scanf("%d", &processSize[i]);
	} 
	

	firstFit(blockSize, m, processSize, n); 

	return 0 ; 
} 
