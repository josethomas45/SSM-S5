#include<stdio.h>

int main() {
    int n, i;
    printf("Enter the number of processes: \n");
    scanf("%d", &n);
    
    int p[n], bt[n], wt[n], tat[n];
    
    printf("Enter the process number and burst time: \n");
    for(i = 0; i < n; i++) {
        scanf("%d %d", &p[i], &bt[i]);
    }
    
    wt[0] = 0;
    tat[0] = bt[0];
    float totwt = 0, tottat = bt[0];
    
    for(i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = wt[i] + bt[i];
        totwt += wt[i];
        tottat += tat[i];
    }
    
    
    printf("\nProcesses\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }
    
    
    printf("\nGantt Chart:\n");
    printf(" ");
    for(i = 0; i < n; i++) {
        printf("-------");
    }
    printf("\n|");
    for(i = 0; i < n; i++) {
        printf("  P%d  |", p[i]);
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
    
    printf("\nTotal Waiting Time: %.2f\n", totwt);
    printf("Total Turnaround Time: %.2f\n", tottat);
    
    printf("\nAverage Waiting Time: %.2f\n", totwt / n);
    printf("Average Turnaround Time: %.2f\n", tottat / n);
    
    return 0;
}

