#include<stdio.h>

struct process{
	int pid;
	int burst_time;
	int priority;
	int waiting_time;
	int turnaround_time;
};

int main(){
	int no_process;
	int wait=0;
	int turn=0;
	float avg_waiting;
	float avg_turnaround;

	printf("Enter the number of process: ");
	scanf("%d",&no_process);

	struct process ready[no_process];
	
	for(int i=0;i<no_process;i++){
		ready[i].pid=i;
		printf("Enter CPU burst time of %d: ",i);
		scanf("%d",&ready[i].burst_time);
		printf("Enter priority number of %d: ",i);
		scanf("%d",&ready[i].priority);
	}
	
	printf("\npid  | burst time |priority|");
	printf("\n____________________________________________________________");
	for(int i=0;i<no_process;i++){
		printf("\n\n  %d |",ready[i].pid);
		
		printf("   %d\t   |",ready[i].burst_time);

		printf("   %d\t |",ready[i].priority);
			
	}
	for(int i=0;i<no_process;i++){
		for(int j=i+1;j<no_process;j++){
			if(ready[i].priority>ready[j].priority){
				struct process temp=ready[i];
				ready[i]=ready[j];
				ready[j]=temp;
			}
		}
	}

	ready[0].waiting_time=0;
	ready[0].turnaround_time=ready[0].burst_time;

	for(int i=1;i<no_process;i++){
		ready[i].waiting_time=ready[i-1].waiting_time+ready[i-1].burst_time;
		ready[i].turnaround_time=ready[i].waiting_time+ready[i].burst_time;
	}

	for(int i=0;i<no_process;i++){
		wait=wait+ready[i].waiting_time;
		turn=turn+ready[i].turnaround_time;
	}

	avg_waiting=wait/(float)no_process;
	avg_turnaround=turn/(float)no_process;

	
	printf("\n\npid  | priority | burst time | waiting time  | turnaround time");
	printf("\n____________________________________________________________");
	for(int i=0;i<no_process;i++){
		printf("\n\n  %d |",ready[i].pid);
		printf("   %d\t |",ready[i].priority);
		printf("   %d\t   |",ready[i].burst_time);
		printf("   %d\t   |",ready[i].waiting_time);
		printf("   %d\t   |",ready[i].turnaround_time);		
	}

	printf("\n\nAverage waiting time=%f\n",avg_waiting);
	printf("Average turnaround time time=%f\n",avg_turnaround);
	
	
}

/*

pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp2$ gcc priority.c
pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp2$ ./a.out
Enter the number of process: 5
Enter CPU burst time of 0: 6
Enter priority number of 0: 3
Enter CPU burst time of 1: 8
Enter priority number of 1: 6
Enter CPU burst time of 2: 3
Enter priority number of 2: 1
Enter CPU burst time of 3: 9
Enter priority number of 3: 2
Enter CPU burst time of 4: 6
Enter priority number of 4: 4

pid  |  burst time |   priority  |
__________________________________
  0 |   6	   |   3	 |

  1 |   8	   |   6	 |

  2 |   3	   |   1	 |

  3 |   9	   |   2	 |

  4 |   6	   |   4	 |

pid | priority   | burst time | waiting time  | turnaround time
____________________________________________________________

  2 |   1	 |   3	    |   0	   |   3	   |

  3 |   2	 |   9	    |   3	   |   12	   |

  0 |   3	 |   6	    |   12	   |   18	   |

  4 |   4	 |   6	    |   18	   |   24	   |

  1 |   6	 |   8	    |   24	   |   32	   |

Average waiting time=11.400000
Average turnaround time time=17.799999


*/
