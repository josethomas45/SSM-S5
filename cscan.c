#include<stdio.h>
#include<stdlib.h>
 void main()
 {
  int n,hd,dist,i,size,dir,temp,j;
  int sktime=0;
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
  int ind=0;
  while(ind<n&&hd>=a[ind])
  {
   ind++;
   if(dir==1)
   {
    for(i=ind;i<n;i++)
    {
     sktime+=abs(a[i]-hd);
     hd=a[i];
    }
    sktime+=abs(size-a[n-1]-1);
    sktime+=size-1;
    hd=0;
    for(i=0;i<ind;i++)
    {
     sktime+=abs(a[i]-hd);
     hd=a[i];
    }
   }
   else
   {
    for(i=ind-1;i>=0;i++)
    {
     sktime+=abs(a[i]-hd);
     hd=a[i];
    }
    sktime+=abs(a[0]-0);
    sktime+=size-1;
    hd=size-1;
    for(i=n-1;i>=ind;i--)
    {
     sktime+=abs(a[i]-hd);
     hd=a[i];
    }
   }
  }
  printf("Average seaktime = %d \n",&sktime);
 }
