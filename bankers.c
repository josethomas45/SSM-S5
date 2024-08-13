#include<stdio.h>
#include<stdlib.h>
void main()
{

 int rq,rs,i,j,k=0,c=0,exec=0,flag;
 printf("Enter the number of request: \n");
 scanf("%d",&rq);
 printf("Enter the number of resources: \n");
 scanf("%d",&rs);
 int avail[rs],need[rq][rs],alloc[rq][rs],max[rq][rs],vis[rq],a[rq];
 printf("Enter the available: \n");
 for(i=0;i<rs;i++)
 {
  scanf("%d",&avail[i]);
 }
 for(i=0;i<rq;i++)
 {
 vis[i]=0;
  printf("enter the allocation of p%d:\n",i);
  for(j=0;j<rs;j++)
  {
   scanf("%d",&alloc[i][j]);
  }
  printf("enter the max of p%d:\n",i);
  for(j=0;j<rs;j++)
  {
   scanf("%d",&max[i][j]);
  }
  for(j=0;j<rs;j++)
  {
   need[i][j]=max[i][j]-alloc[i][j];
  }
 }
 printf("Alloc\tmax\tneed\tavail\n");
 for(i=0;i<rq;i++)
 {
  for(j=0;j<rs;j++)
  {
   printf("%d",alloc[i][j]);
  }
  printf("\t");
  for(j=0;j<rs;j++)
  {
    printf("%d", max[i][j]);
  }
  printf("\t"); 
  
   for(j=0;j<rs;j++)
  {
   printf("%d",need[i][j]);
  }
  printf("\t");
  
  if(i==0)
  {
  for(j=0;j<rs;j++)
  {
   printf("%d",avail[j]);
  }
  printf("\t");
  }
  printf("\n");
 }
 
 while(c<rq)
 {
  flag=0;
  for(i=0;i<rq;i++)
  {
   exec=0;
   for(j=0;j<rs;j++)
   {
    if(need[i][j]<=avail[j])
    {
     exec++;
    }
   }
   if(exec==rs&&vis[i]==0)
   {
    for(j=0;j<rs;j++)
    {
     avail[j]=avail[j]+alloc[i][j];
    }
    flag++;
   c++;
   a[k++]=i;
   vis[i]=1;
   }
   
  }
  if(flag==0)
  {
   printf("no safe seq\n");
   exit(0);
  }
 }
 printf("The safe seq is \n");
 for(i=0;i<rq;i++)
 {
  printf("p%d\t" , a[i]);
 }
 printf("\n");
}
