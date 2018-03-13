# operating_systems_scheduling
# non preemptive priority based scheduling based on estimated run time.
# #define max
#include<stdio.h>
int main (){
int proces[10];
int burst_time[10];
int waiting_time[10];
int turn_around[10];
float avg_wt;
float avg_turn;
int arrival_time[10];
int priority[10];
int number;
printf("\n Enter Total number of process want to enter");
scanf("%d",&number);
printf("\n Enter burst time for each process");
for(int i=0;i<number;i++){
//pritnf("\n P[%d] ",i+1);
scanf("%d",&burst_time[i])
}
printf("\n Enter Arrival time for each process");
for(int i=0;i<number;i++){
scanf("%d",&arrival_time[i]);
}
printf("\n Priority of each process")
for(int i=0;i<number;i++){
priority[i]=1+(waiting_time[i]/burst_time[i]);
}

}
