#include <stdio.h>

void main() {
    int n, i, temp, j;
    printf("Enter the number of processes:\n");
    scanf("%d", &n);
    
    int p[n], bt[n], pri[n], wt[n], tat[n];
    
    printf("Enter the process number, burst time, and priority:\n");
    for(i = 0; i < n; i++) {
        scanf("%d %d %d", &p[i], &bt[i], &pri[i]);
    }
    
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(pri[i] > pri[j]) {
                temp = pri[i];
                pri[i] = pri[j];
                pri[j] = temp;
                
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    
    wt[0] = 0;
    tat[0] = bt[0];
    float totwt = 0, tottat = tat[0];
    
    for(i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
        totwt += wt[i];
        tottat += tat[i];
    }
    
    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], pri[i], wt[i], tat[i]);
    }
    
    printf("\nGantt Chart:\n");
    printf(" ");
    for(i = 0; i < n; i++) {
        printf("-------");
    }
    printf("\n");
    for(i = 0; i < n; i++) {
        printf("  P%d  ", p[i]);
    }
    printf("\n ");
    for(i = 0; i < n; i++) {
        printf("-------");
    }
    printf("\n0");
    for(i = 0; i < n; i++) {
        printf("      %d", tat[i]);
    }
    printf("\n");
    
    printf("\nAverage Waiting Time: %.2f\n", totwt / n);
    printf("Average Turnaround Time: %.2f\n", tottat / n);
    printf("Total Waiting Time: %.2f\n", totwt);
    printf("Total Turnaround Time: %.2f\n", tottat);
}

