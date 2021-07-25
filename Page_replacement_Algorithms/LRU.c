#include<stdio.h>
int main()
{
	int q[20],p[50],c=0,c1,d,f,i,j,k=0,n,r,t,b[20],c2[20];
	printf("Enter number of pages:");
	scanf("%d",&n);
	printf("Enter the reference string:");
	for(i=0;i<n;i++)
	    scanf("%d",&p[i]);
	printf("Enter number  of frames:");
	scanf("%d",&f);
	
	q[k]=p[k]; //  1st value in string q[0]=p[0]
	printf("\n\t%d\n",q[k]);
	c++;k++;//c=1,k=1
	for(i=1;i<n;i++)// to traverse whole string 
	{
	    c1=0;
	    for(j=0;j<f;j++)//traversing all frames
	    {
	        if(p[i]!=q[j])//checking condition for hit
	            c1++;
	    }
	    if(c1==f)//no hit 
	    {
	        c++;
	    	if(k<f)//frame is not completely filled up 
	        {
	            q[k]=p[i];//allocate 
	            k++;
	            for(j=0;j<k;j++)
	                printf("\t%d",q[j]);
	            printf("\n");
	    	}
	        else //if all places are occupied in a frame
	    	{
	        	for(r=0;r<f;r++)
	            	{
	        		c2[r]=0;
	                	for(j=i-1;j<n;j--)
	            		{
	                    		if(q[r]!=p[j])
	                        		c2[r]++;
	                    		else
	                    			break;
	            		}
	        	}
	        	for(r=0;r<f;r++)
	                	b[r]=c2[r];
	    		for(r=0;r<f;r++)
	            	{
	                	for(j=r;j<f;j++)
	                	{
	                    		if(b[r]<b[j])//to check least used
	                    		{
	                        	t=b[r];
	                        	b[r]=b[j];
                            		b[j]=t;
	                    		}
	                	}
	          	}
	          	for(r=0;r<f;r++)
	          	{
	                	if(c2[r]==b[0])//least used done 
	                		q[r]=p[i];//allocation
	                	printf("\t%d",q[r]);
	          	}
	            	printf("\n");
	           }
      	      }
	}
	printf("\nThe no of page faults is %d",c);
}