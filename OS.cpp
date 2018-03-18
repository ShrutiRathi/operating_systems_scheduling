#include<conio.h>
#include<stdio.h>
int main(){
	int process[10],sum=0,temp,pos;
	int burst_time[10],arrival_time[10],priority[10];
	int wt_time[10];
	int i,j;
	int limit;
	int max=10;
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
	printf("\n process \t arrival_time \t bursrt_time");
	for(i=1;i<=limit;i++){
		printf("\n process[%d] \t\t %d \t\t %d",i,arrival_time[i],burst_time[i]);
	//	printf("\t");
	//	printf("%d",arrival_time[i]);
	//	printf("\t");
	//	printf("%d",burst_time[i]);
	}
	for(i=1;i<=limit;i++){
		sum=arrival_time[i]+sum;
		if(sum==0){
			printf("\n Execution order of process is :");
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
			//	printf("\n %d",burst_time[i]);
				printf("\n %d",process[i]);
			}
	}
	
	
}
