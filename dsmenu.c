#include<stdio.h>
#include<stdlib.h>
void main(){
  int ch=1,c;
  while(ch==1){
    printf("enter the choice\n 1)FCFS 2)scan 3)cscan 4)exit \n");
    scanf("%d",&c);
    switch(c){
    
       case 1:
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
 break;
 }
 case 2:
   {int n,hd,dist,sktime=0,i,size,dir,temp,j;
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
  break;}
  
  case 3:
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
  break;}
  
  case 4:
     { exit(0);}
      
 
 }
 }
 }
