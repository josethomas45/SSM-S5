#include<stdio.h>
#include<stdlib.h>
 void main()
 {
  int n,hd,dist,sktime=0,i;
  printf("Enter the number of request:\n");
  scanf("%d",&n);
  printf("Enter the initial head position:\n");
  scanf("%d",&hd);
  int a[n];
  printf("Enter the request:\n");
  for(i=1;i<=n;i++)
  {
   scanf("%d",&a[i]);
  }
  a[0]=hd;
  for(i=0;i<n;i++)
  {
   dist=abs(a[i+1]-a[i]);
   //printf("The head movement from %d is %d\n",a[i],a[i+1],dist);
   sktime+=dist;
  }
 printf("The average seaktime is %d\n",sktime);
 }
