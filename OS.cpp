#include<conio.h>
#include<stdio.h>
int main(){
	int process[10],sum=0,temp,pos,ex_process[10];
	int burst_time[10],arrival_time[10],priority[10];
	int wt_time[10];
	int total_wt[10];
	int i,j,k=0,a=0,total=0;
	int limit;
	int max=10;
	int pnum,t;
	int min=50;
	
	//Limit should be positive;
	printf("\n Enter number of process");
	scanf("%d",&limit);
	
	
	if(limit>max){
		printf("\n More than 10 process are'nt allowed");
		printf("\n Enter number of  process again ");
		scanf("%d",&limit);
		
	}
	else{
		for(i=1;i<=limit;i++){
			process[i]=i;
		}
	}

	
	//Time should be positive;
	printf("\n Enter arrival time for process ");
	for(i=1;i<=limit;i++){
		printf("\n process[%d]",i);
		scanf("%d",&arrival_time[i]);
		
	}
	
	
	//Time should be positive;
	printf("\n Enter Burst time for process");
	for(i=1;i<=limit;i++){
		printf("\n process[%d]",i);
		scanf("%d",&burst_time[i]);
		
	}
	
	// to display entered details 
	
	printf("\n process \t arrival_time \t bursrt_time");
	for(i=1;i<=limit;i++){
		printf("\n process[%d] \t\t %d \t\t %d",i,arrival_time[i],burst_time[i]);
	
	}
	
	
	for(i=1;i<=limit;i++){
		sum=arrival_time[i]+sum;
		if(sum==0){
			// case -All process arrives at t=0
			printf("\n Execution order of process is :");
			//using selection sort
			for(i=0;i<limit;i++)
    {
        pos=i;
        for(j=i+1;j<limit;j++)
        {
            if(burst_time[j]<burst_time[pos])
                pos=j;
        }
 
        temp=burst_time[i];
        burst_time[i]=burst_time[pos];
        burst_time[pos]=temp;
 
        temp=process[i];
        process[i]=process[pos];
        process[pos]=temp;
            }
    
			}
				for(i=1;i<=limit;i++){
    		printf("\n %d",process[i]);
    	}

	}
	
	
//case--2	when all process arrives at different time;
for(i=0;i<limit;i++)
{
   if(arrival_time[i]==0){
   	//store its burst time in variable t;
   	//and process number in pnum;
 	t=burst_time[i];
	pnum=i+1;
	priority[i]=1;
 	printf("\n the process having arrival time 0 will be executed first ");
 	printf("\n process[%d] will be executed first as arrival time is 0 ",pnum);
 	ex_process[k]=pnum;
 	k++;
 	
 	total_wt[a]=burst_time[pnum-1];
 	a++;
 	
 	
 	for(i=pnum-1;i<limit;i++)
	{
 		process[i]=process[i+1];
 		arrival_time[i]=arrival_time[i+1];
 		burst_time[i]=burst_time[i+1];
 	}
 	limit--;
 	
   }
	}// seperating the process that comes at t=0 from the other processes
	
   while(limit!=0){
   	
   for(i=0;i<limit;i++){
   		
   		while(arrival_time[i]!=0)
	{
	for(i=0;i<a;i++){
		total=total+total_wt[i];
	}
	
	wt_time[i]=total-arrival_time[i];
	if(wt_time[i]>=0){
		
	priority[i]=1+(wt_time[i]/burst_time[i]);
	for(i=0;i<limit;i++){
		if(min>priority[i])
		{
			min=priority[i];
			pos=i+1;
			// the process with minimum priority value  willbe executed next;
			ex_process[k]=pos+1;
			k++;
			
			total_wt[a]=burst_time[pos-1];
 			a++;
 	
			for(i=pos-1;i<limit;i++)
	{
 		process[i]=process[i+1];
 		arrival_time[i]=arrival_time[i+1];
 		burst_time[i]=burst_time[i+1];
 	}
 	limit--;
 
			
			
			// after this to select the 3rd position we need to set the priorites again for the remaining processes
			// and need to filter out ; 
		}
		
	}
	}
	}
   		
   }
   }
   // shows the order of execution
   for(i=0;i<k;i++){
   	printf("\n %d",ex_process[i]);
   }
   
	
}
	


