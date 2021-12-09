#include<stdio.h>
#include<stdlib.h>
 
 int main()

 {
   int rq[100],i,n,total_headmoment=0,initial,size,move,j;
   printf("enter the no. of req\n");
   scanf("%d",&n);
   printf("enter the request sequence\n");
    for(i=0;i<n;i++)
     scanf("%d",&rq[i]);
   printf("enter initial head posititon\n");
   scanf("%d",&initial);
   printf("enter disk size\n");
   scanf("%d",&size);
   printf("enter the headmovement directiom for high 1 for low 0\n");
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
         total_headmoment=total_headmoment+abs(rq[i]-initial);
         initial=rq[i];
  	}

	total_headmoment=total_headmoment+abs(size-rq[i-1]-1);
	initial=size-1;
	for(i=index-1;i>=0;i--)
 	 {
  	  total_headmoment=total_headmoment+abs(rq[i]-initial);
  	  initial=rq[i];
 	 }
   }
else
{
	for(i=index-1;i>=0;i--) ;
 	 {
	  total_headmoment=total_headmoment+abs(rq[i]-initial);
 	  initial=rq[i];
	 }
total_headmoment=total_headmoment+abs(rq[i+1]-0);
 initial=0;

	for(i=index;i<n;i++)
	 {
 	  total_headmoment=total_headmoment+abs(rq[i]-initial);
 	  initial=rq[i];
	  }
}

printf("total headmoment is %d",total_headmoment);

return(0);

}


