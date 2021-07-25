#include<stdio.h>
int main()
{
 	int np,nb,i,j,z,w;
 	printf("\nEnter the number of blocks: ");
	scanf("%d",&nb);
	printf("Enter the number of processes: ");
	scanf("%d",&np);
	int m[nb],p[np];
	for(i=0;i<np;i++)
    {
		printf("enter the %dth process size : ",i+1);
        scanf("%d",&p[i]);
    }
	for(j=0;j<nb;j++)
    {
        printf("enter the %dth memory size : ",j+1);
        scanf("%d",&m[j]);
    }
    printf("\nProcess_no\tProcess_size\tBlock_no\tBlock_size\tFragment");
    for(w=0;w<np;w++)
    {
    	int max=p[w],index=-1;
		for(z=0;z<nb;z++)
		{
			if(m[z]>max)//caluclating max of the possible cases
			{
				index=z;
				max=m[z];
			}
		}
		int k=index;
    		if(k!=-1)
    		{
    			printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",w+1,p[w],k+1,m[k],m[k]-p[w]);
    			m[k]=m[k]-p[w];
    		}
    		else
    			printf("\n%d\t\t%d\t\t0\t\t0\t\t0",w+1,p[w]);
    	}
    	printf("\n");	

}