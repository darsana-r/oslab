#include<stdio.h>

struct process{
	int pid;
	int burst_time;
	int remaining_burst;
	int waiting_time;
	int turnaround_time;
};

int main(){
	int no_process;
	int exec_time=0;
	int quantum_time;
	int total_exec_time=0;
	int tot_waiting=0;
	int tot_TAT=0;
	float avg_wait=0;
	float avg_turnaround_time=0;
	
	printf("Enter the number of process: ");
	scanf("%d",&no_process);

	struct process q[no_process];

	for(int i=0;i<no_process;i++){
		q[i].pid=i;
		printf("\nenter the burst time of %d: ",i);
		scanf("%d",&q[i].burst_time);
		q[i].remaining_burst=q[i].burst_time;	
	}

	printf("Enter the quantum time :");
	scanf("%d",&quantum_time);
	

	while(1){
		int count=0;
		for(int i=0;i<no_process;i++){
			if(q[i].remaining_burst==0){
				count++;
				continue;			
			}
			if(q[i].remaining_burst>quantum_time){
				exec_time=quantum_time;
				q[i].remaining_burst=q[i].remaining_burst-quantum_time;
			}
			else{
				if(q[i].remaining_burst>0){
					exec_time=q[i].remaining_burst;
					q[i].remaining_burst=0;
				}			
			}
			total_exec_time=exec_time+total_exec_time;
			q[i].turnaround_time=total_exec_time;
		}
		if(count==no_process){
			break;
		}
	}
	
	for(int i=0;i<no_process;i++){
		q[i].waiting_time=q[i].turnaround_time-q[i].burst_time;	
		tot_waiting=tot_waiting+q[i].waiting_time;
		tot_TAT=tot_TAT+q[i].turnaround_time;
	}


	avg_wait=tot_waiting/(float)no_process;
	avg_turnaround_time=tot_TAT/(float)no_process;

	printf("\npid     |  burst time   | waiting time  | turnaround time");
	printf("\n____________________________________________________________");
	for(int i=0;i<no_process;i++){
		printf("\n%d\t |\t",q[i].pid);
		printf("%d\t|\t",q[i].burst_time);
		printf("%d\t|\t",q[i].waiting_time);
		printf("%d\t|\t",q[i].turnaround_time);		
	}

	printf("\n\nAverage waiting time=%f\n",avg_wait);
	printf("Average turnaround time time=%f\n",avg_turnaround_time);		
}

/*

pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp2$ gcc roundrobin.c
pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp2$ ./a.out
Enter the number of process: 5

enter the burst time of 0: 3

enter the burst time of 1: 2

enter the burst time of 2: 5

enter the burst time of 3: 4

enter the burst time of 4: 1
Enter the quantum time :2

pid     |  burst time   | waiting time  | turnaround time
____________________________________________________________
0	 |	3	|	7	|	10	|	
1	 |	2	|	2	|	4	|	
2	 |	5	|	10	|	15	|	
3	 |	4	|	10	|	14	|	
4	 |	1	|	8	|	9	|	

Average waiting time=7.400000
Average turnaround time time=10.400000

*/
