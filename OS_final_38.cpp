#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
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
	float w_sum=0.0,b_sum=0.0;
	bool all_equal=false;// initialise it to false
	
	//Limit should be positive;
	printf("\n Enter number of process   ");
	scanf("%d",&limit);
	if(limit<0){
		printf("\n Number of process entered should be positive ");
		printf("\n Enter number of  process again ");
		scanf("%d",&limit);
	}
	
	
	else if(limit>=1 && limit>max){
		printf("\n More than 10 process aren't allowed");
		printf("\n Enter number of  process again ");
		scanf("%d",&limit);
		
	}
	else if(limit==max){
		printf("\n Maximum number of process entered ");
	}
	else if(limit>=1 && limit<=max){
		
	}
	else{
		printf("\n No process is ready to execute");
	}
	
	
	int n=limit;
	
	//else if(limit>=1 && limit==10){
	//	printf("\n Maximum number of processes entered");
	//}
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
			for(i=1;i<=limit;i++){
			
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
			for(i=1;i<=limit;i++){
			
			scanf("%d",&burst_time[i]);}
		}
	}
	for(i=1;i<=n;i++){
		b_sum+=burst_time[i];
	}
	

	
	
	// to display entered details 
	
	printf("\n process \t arrival_time \t burst_time");
	for(i=1;i<=limit;i++){
		printf("\n process[%d] \t\t %d \t\t %d",i,arrival_time[i],burst_time[i]);
	
	}
	printf("\n Total Burst time = %f",b_sum);
	
	for(i=1;i<=limit-1;i++)
	{
		if(arrival_time[i]!=arrival_time[i+1])
			break;
	}
	if(i==limit)
		all_equal=true;
	//All cases Priority and waiting calulation .
	while(limit!=0){
   	//Calculating total waiting time.
   	total=0;
   	min=(all_equal)?INF:-INF;
   	pos=0;
	for(i=0;i<a;i++){
		total=total+total_wt[i];
	}
	//Calculating waiting time and priority for each process
	//printf("\nTotal=%d",total);
   for(i=1;i<=limit;i++){
	wt_time[i]=total-arrival_time[i];
	priority[i]=1.0+(float)(wt_time[i]/(float)burst_time[i]);
	if(priority[i]<0)
		priority[i]*=-1;
	}
	//Finding minimum priority.
	for(i=1;i<=limit;i++){
		if(min<priority[i] && !all_equal)
		{
			min=priority[i];
			pos=i;
		}
		else if(min>priority[i] && all_equal)
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
   for(i=0;i<n;i++){
   	w_sum+=wt_time[i];
   	
   }
printf("\n Total waiting time = %f",w_sum);
   printf("\n The avg waiting time is  %f",(w_sum/n));
	printf("\n The avg turnaround time is %f",(w_sum/n)+(b_sum/n));
   printf("\n");
   return 0;
}
	


