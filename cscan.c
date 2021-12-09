#include<stdio.h>
#include<stdlib.h>

int main()

{

  int rq[100],i,j,n,totalhead_moment=0,initial,size,move;
  printf("enter the number of requests\n");
  scanf("%d",&n);
  printf("entter the req seq\n");
   for(i=0;i<n;i++)
  scanf("%d",&rq[i]);
  printf("enter iniital head position\n");
  scanf("%d",&initial);
  printf("enter total disk size\n");
  scanf("%d",&size);
  printf("enter the haed moment direction for high 1 low 0"); 
  scanf("%d",&move);
 

for(i=0;i<n;i++)
 {
   for(j=0;j<n-i-1;j++)
    { 
      if(rq[j]>rq[j+1])
      {
       int temp;
       temp=rq[j];
       rq[j]=rq[j+1];
       rq[j+1]=temp;
      }
    }
 }
 

int index;

for(i=0;i<n;i++)
  {
      if(initial<rq[i])
    {
     index=i;
     break;
    }

  }


if(move==1)
{
  for(i=index;i<n;i++)
 {
  totalhead_moment=totalhead_moment+abs(rq[i]-initial);
  initial=rq[i];
 }
        totalhead_moment=totalhead_moment+abs(size-rq[i-1]-1);
        totalhead_moment=totalhead_moment+abs(size-1-0);
        initial=0;
        
    for( i=0;i<index;i++)
     {
       totalhead_moment=totalhead_moment+abs(rq[i]-initial);
       initial=rq[i];
     }
}

else
{ 
    for(i=index-1;i>=0;i--)
      {
       totalhead_moment=totalhead_moment+abs(rq[i]-initial);
       initial=rq[i];
      }
 
	totalhead_moment=totalhead_moment+abs(rq[i+1]-0);
 	totalhead_moment=totalhead_moment+abs(size-1-0);
 	initial=size-1;


    for(i=n-1;i>=index;i--)
    {
     totalhead_moment=totalhead_moment+abs(rq[i]-initial);
     initial=rq[i];
    }
}
printf("total head moment is %d",totalhead_moment);
return 0;
}
