#include<stdio.h>
#define INF 10000
int main(){
	int process[10],sum=0,temp,pos,ex_process[10];
	int burst_time[10],arrival_time[10];
	float priority[10];
	int wt_time[10]={0};
	int total_wt[10]={0};
	int i,j,k=0,a=0,total=0;
	int limit;
	int max=10;
	int pnum,t;
	float min=INF;
	
	//Limit should be positive;
	printf("\n Enter number of process");
	scanf("%d",&limit);
	
	
	if(limit>max){
		printf("\n More than 10 process aren't allowed");
		printf("\n Enter number of  process again ");
		scanf("%d",&limit);
		
	}
	for(i=1;i<=limit;i++){
		process[i]=i;
	}

	
	//Time should be positive;
	printf("\n Enter arrival time for process ");
	for(i=1;i<=limit;i++){
		printf("\n process[%d]",i);
		scanf("%d",&arrival_time[i]);
	}
	for(i=1;i<=limit;i++){
		if(arrival_time[i]<0){
			printf("\n Enter positive arrival time for each process");
			for(i=0;i<limit;i++){
			
			scanf("%d",&arrival_time[i]);}
		}
	}
	
	//Time should be positive;
	printf("\n Enter Burst time for process");
	for(i=1;i<=limit;i++){
		printf("\n process[%d]",i);
		scanf("%d",&burst_time[i]);
	}
		for(i=1;i<=limit;i++){
		if(burst_time[i]<0){
			printf("\n Enter positive burst time for each process");
			for(i=0;i<limit;i++){
			
			scanf("%d",&burst_time[i]);}
		}
	}
	// to display entered details 
	
	printf("\n process \t arrival_time \t burst_time");
	for(i=1;i<=limit;i++){
		printf("\n process[%d] \t\t %d \t\t %d",i,arrival_time[i],burst_time[i]);
	
	}
	
	//This works for all cases.
	while(limit!=0){
   	//Calculating total waiting time.
   	total=0;
   	min=INF;
   	pos=0;
	for(i=1;i<=limit;i++){
		total=total+total_wt[i];
	}
	//Calculating waiting time and priority for each process
   for(i=1;i<=limit;i++){
	wt_time[i]=total-arrival_time[i];
	priority[i]=1.0+(float)(wt_time[i]/(float)burst_time[i]);
	if(priority[i]<0)
		priority[i]*=-1;
	}
	//Finding minimum priority.
	for(i=1;i<=limit;i++){
		if(min>priority[i])
		{
			min=priority[i];
			pos=i;
		}
		else if(min==priority[i])
		{
			if(arrival_time[pos]==arrival_time[i])
			{
				if(burst_time[pos]>burst_time[i])
				pos=i;
			}
			else if(arrival_time[pos]>arrival_time[i])
			{
				pos=i;
			}
		}
		}
			// the process with minimum priority value will be executed next;
			ex_process[k]=process[pos];
			k++;
			total_wt[a]=burst_time[pos];
 			a++;
 	
			for(i=pos;i<=limit-1;i++)
			{
		 		process[i]=process[i+1];
		 		arrival_time[i]=arrival_time[i+1];
		 		burst_time[i]=burst_time[i+1];
		 	}
		 	limit--; 
		 	for(i=1;i<=limit;i++){
    	} 
	}
   // shows the order of execution
	printf("\nThe order of execution of process:");
   for(i=0;i<k;i++){
   	
   	printf("\n %d",ex_process[i]);
   }
   printf("\n");
   return 0;
}
	
