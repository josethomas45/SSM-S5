#include<stdio.h>
void main()
{
 printf("Enter the time quatum:\n");
 int TIME_QUA;
 scanf("%d",&TIME_QUA);
 printf("Enter the number of process:\n");
 int limit;
 scanf("%d",&limit);
 
 int process[limit], bt[limit], rem_bt[limit], wt[limit], tat[limit], tt[30], i, j=0;
 int time=0;
 int completed=0;
 tt[j]=time;
 
 printf("Enter the processes and burst time:\n");
 for(i=0;i<limit;i++){
  scanf("%d%d",&process[i],&bt[i]);
  rem_bt[i]=bt[i];
 }
 
 while(completed<limit){
   for(i=0;i<limit;i++){
    if(rem_bt[i]>0){
     if(rem_bt[i]> TIME_QUA){
      time+=TIME_QUA;
      tt[++j]=time;
      rem_bt[i]-=TIME_QUA;
      printf("   p%d\t",process[i]);
      }
      else{
      time +=rem_bt[i];
      tt[++j]=time;
      wt[i]= time-bt[i];
      printf("   p%d\t",process[i]);
      
      rem_bt[i]=0;
      completed++;
      tat[i]=time;
      }
      }
      }
      }
      printf("\n");
      for(i=0;i<=j;i++)
      {
       printf("%d\t",tt[i]);
      }
      printf("\n");
      
      float tot_wt=0, tot_tat=0;
      
      printf("Process\tBT\tWT\tTAT\n");
      for(i=0;i<limit;i++){
       printf("%d\t%d\t%d\t%d\n", process[i],bt[i],wt[i],tat[i]);
       tot_wt+=wt[i];
       tot_tat+=tat[i];
       }
       
       printf("Average WT= %.2f\n AVerage TAT= %.2f\n Total WT= %.2f\n Total TAT= %.2f\n", tot_wt /limit, tot_tat /limit, tot_wt ,tot_tat );
       }
      
