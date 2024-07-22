#include<stdio.h>
void main()
{
   int n,i,temp,j;
   printf("Enter the number of process:\n");
   scanf("%d",&n);
   int p[n],bt[n],wt[n],tat[n];
   printf("Enter the process number and burst time:\n");
   for(i=0;i<n;i++)
   {
      scanf("%d%d",&p[i],&bt[i]);
   }
   for(i=0;i<n;i++)
   {
     for(j=i+1;j<n;j++)
     {
        if(bt[i]>bt[j])
        {
           temp=bt[i];
           bt[i]=bt[j];
           bt[j]=temp;
           temp=p[i];
           p[i]=p[j];
           p[j]=temp;
        }
     }
   }
   wt[0]=0;
   tat[0]=bt[0];
   float totwt=0,tottat=0;
   
   for(i=1;i<n;i++)
   {
     wt[i]=wt[i-1]+bt[i-1];
     tat[i]=tat[i-1]+bt[i];
     totwt+=wt[i];
     tottat+=tat[i];
   }
   
   printf("process\tbt\twt\ttat\n");
   for(i=0;i<n;i++)
   {
     printf("%d\t%d\t%d\t%d\n",p[i],bt[i],wt[i],tat[i]);
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
   
   printf("\nAverage waiting time=%f\nAverage turn around time=%f\n\ntotal waiting time=%f\ntotal turn around time=%f\n",totwt/n,tottat/n,totwt,tottat);

   }
