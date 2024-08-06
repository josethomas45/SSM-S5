#include<stdio.h>
#include<stdlib.h>
 void main()
 {
  int n,hd,dist,sktime=0,i,size,dir,temp,j;
  printf("Enter the number of request:\n");
  scanf("%d",&n);
  printf("Enter the initial head position:\n");
  scanf("%d",&hd);
  printf("Enter the max size:\n");
  scanf("%d",&size);
  int a[n];
  printf("Enter the request:\n");
  for(i=0;i<n;i++)
  {
   scanf("%d",&a[i]);
  }
  for(i=0;i<n;i++)
  {
   for(j=i+1;j<n;j++)
   {
    if(a[i]>a[j])
    {
     temp=a[i];
     a[i]=a[j];
     a[j]=temp;
    }
   }
  }
  printf("Enter the direction 1 for high and 0 for low :\n");
  scanf("%d",&dir);
  if(dir==1)
  {
   sktime+=size-1-hd;
   if(a[0]<hd)
   {
    sktime+=size-1-a[0];
   }
  }
  else
  {
   sktime+=hd;
   if(a[n-1]>hd)
   {
    sktime+=a[n-1];
   }
  }
  printf("The average seaktime = %d \n",sktime);
 }
 
