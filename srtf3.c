#include <stdio.h> 
#include <stdbool.h> 

#define MAX_PROCESSES 100 

//declaring the stucture 
struct process { 
	int pid; 
	int arrival_time; 
	int burst_time; 
	int remaining_time; 
}; 

int main() { 
	int n; 
	struct process processes[MAX_PROCESSES]; 
	bool completed[MAX_PROCESSES] = {false}; 
	int current_time = 0; 
	int shortest_time = 0; 
	int shortest_index = 0; 

	printf("Enter the number of processes: "); 
	scanf("%d", &n); 

	for (int i = 0; i < n; i++) { 
		printf("Enter arrival time and burst time for process %d: ", i+1); 
		scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time); 
		processes[i].pid = i+1; 
		processes[i].remaining_time = processes[i].burst_time; 
	} 

	printf("\n"); 

	while (true) { 
        //printf("h ");
		bool completed_all = true; 
		for (int i = 0; i < n; i++) { 
            printf("%d", i);
			if (!completed[i]) { 
				completed_all = false; 
				if (processes[i].arrival_time <= current_time && 
					processes[i].remaining_time < processes[shortest_index].remaining_time) { 
					shortest_index = i;
				} 
			}
		} 
		if (completed_all) { 
			break; 
		} 
		if (shortest_index != -1) { 
			processes[shortest_index].remaining_time--; 
			if (processes[shortest_index].remaining_time == 0) { 
				completed[shortest_index] = true; 
			} 
		} 
		current_time++; 
		shortest_index = -1; 
	} 

	printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnAround Time\n"); 

	int total_waiting_time = 0; 
	int total_turnaround_time = 0; 
	for (int i = 0; i < n; i++) { 
		int waiting_time = 0; 
		int turnaround_time = 0; 
		waiting_time = current_time - processes[i].burst_time - processes[i].arrival_time; 
		turnaround_time = current_time - processes[i].arrival_time; 
		total_waiting_time += waiting_time; 
		total_turnaround_time += turnaround_time; 
		printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, waiting_time, turnaround_time); 
	} 

	float avg_waiting_time = (float) total_waiting_time / n; 
	float avg_turnaround_time = (float) total_turnaround_time / n; 

	printf("The Average Waiting Time: %.2f\n", avg_waiting_time); 
	printf("The Average Turnaround Time: %.2f\n", avg_turnaround_time); 

	return 0; 
}
