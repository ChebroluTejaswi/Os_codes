#include<stdio.h>
int main()
{
	int i,j,n,a[50],frame[10],no,k,avail,count=0;
	printf("\n Enter  number of pages:\n");
	scanf("%d",&n);
	printf("\n Enter the string :\n");
	for(i=1;i<=n;i++)
	    scanf("%d",&a[i]);
	printf("\n Enter number of frames:");
	    scanf("%d",&no);
	for(i=0;i<no;i++)
	    frame[i]= -1;//initialising all values in frame as -1
	    j=0;
	    
	    printf("\tRef string\t Page frames\n");
	for(i=1;i<=n;i++)
        {
            printf("%d\t\t",a[i]);
            avail=0;
        	for(k=0;k<no;k++)
			if(frame[k]==a[i])
                    avail=1; // hit 
            if (avail==0) //miss
            {
            	frame[j]=a[i];
            	j=(j+1)%no;
            	count++;
            	for(k=0;k<no;k++) //for printing values in frames
            	{
                	if(frame[k]==-1)
                		printf(" \t");
                	else
	                    printf("%d\t",frame[k]);
	        }
	    }
            printf("\n");
	}
	printf("Page Fault count: %d",count);
	return 0;
}