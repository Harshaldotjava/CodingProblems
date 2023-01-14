#include <stdio.h>

int main(){
    int processes;
    printf("enter number of process \n");
    scanf("%d",&processes);
    int arrival_time[processes];
    int burst_time[processes];
    int waiting_time[processes];
    int turnaround_time[processes];

    printf("enter arrival time and burst_time\n");
    for(int i=0;i<processes;i++){
        scanf("%d",&arrival_time[i]);
        scanf("%d",&burst_time[i]);
    }

    //waiting time
    for(int i=0;i<processes;i++){
        int total_burst = 0;
        waiting_time[i] = 0;
        for(int j=0;j<processes;j++){
            if(arrival_time[j] < arrival_time[i])
                total_burst += burst_time[j];
        }
        if(total_burst > arrival_time[i])
            waiting_time[i] = total_burst - arrival_time[i];
        turnaround_time[i] = waiting_time[i] + burst_time[i];
    }

    printf("at  bt  ta  wt\n");
    for(int i=0;i<processes;i++){
        printf("%d    %d    %d    %d  \n",arrival_time[i],burst_time[i],turnaround_time[i],waiting_time[i]);
    }
    return 0;
}
