# operating_systems_scheduling
# non preemptive priority based scheduling based on estimated run tim
NON-PREEMPTIVE SCHEDULING
The problem assigned in this project is based upon non-pre-emptive priority scheduling.
Non-preemptive scheduling: When the currently executing process gives up the CPU voluntarily. i.e. the process once assigned the CPU will only give up when its execution completes. If in between its execution any process even of higher priority comes then it will not terminate. 
The idea is to schedule the process based on a priority assigned to them. Priority of the process is decided by its waiting time and estimated run time.
Waiting Time: The time interval between the arrival time and time at which the process is assigned the CPU is waiting time.
Calculated as: waiting time= time assigned – arrival time.
Arrival time: The time at which the process come in Ready Queue from Job Queue.
Estimated Run Time: Approximate time spent by the process in the CPU. It is denoted as Burst time in the program.
Here in this problem, the priority of the process is dependent upon both waiting time and estimated run time as : 
Priority =1+ (waiting time /estimated run time).
Along with the priorities assigned to the process, if any conflict occurs (tie between priorities occurs) then it will be resolved by SHORTEST JOB FIRST ALGORITHM (SJF).
SHORTEST JOB FIRST: Shortest job first is a scheduling algorithm in which the process with the smallest execution time is selected for execution next.
•	If the process has same priorities and same burst time then the tie will be resolved using FCFS algorithm.
FCFS: FIRST COME FIRST SERVE, i.e. the process which will come first in the ready queue will be executed first.
JOB QUEUE:  contains all the processes that reside on mass storage/secondary storage and await main memory allocation.
READY QUEUE: contains all the processes that are waiting to be scheduled on a core/CPU.
By using the above strategy, Jobs gain higher priority the longer they wait, which prevents indefinite postponement. The jobs that have spent a long time waiting compete against those estimated to have short run times

