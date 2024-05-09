#include <stdio.h>

#define MAX_PROCESSES 10
#define TIME_QUANTUM 5

typedef struct {
    int id;
    int burst_time; 
    int remaining_time;
} Process;

void round_robin(Process processes[], int n) {
    int i, total_burst_time = 0;
   
    for (i = 0; i < n; i++) {
        total_burst_time += processes[i].burst_time;
        processes[i].remaining_time = processes[i].burst_time;
    }

    int current_time = 0;
    printf("Execution Order:\n");
   
    while (total_burst_time > 0) {
        for (i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                printf("Process %d is running", processes[i].id);
                if (processes[i].remaining_time <= TIME_QUANTUM) {
                    current_time += processes[i].remaining_time;
                    total_burst_time -= processes[i].remaining_time;
                    processes[i].remaining_time = 0;
                    printf("-> Time: %d ,", current_time);
                    printf("Process %d has finished \n", processes[i].id);
                } else {
                    current_time += TIME_QUANTUM;
                    total_burst_time -= TIME_QUANTUM;
                    processes[i].remaining_time -= TIME_QUANTUM;
                    printf("-> Time: %d\n", current_time);
                }
            }
        }
    }
}

int RoundRobin() {
    int n, i;
    Process processes[MAX_PROCESSES];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].id = i + 1;
    }

    round_robin(processes, n);

    return 0;
}
