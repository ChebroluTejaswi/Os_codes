#include<stdio.h>
int main()
{
	int np,nm,j,l,s,q;
	printf("Enter the number of process");
	scanf("%d",&np);
	printf("Enter the number of memory blocks");
	scanf("%d",&nm);
	int p[np],m[nm],frag[nm];
	printf("Enter process size:\n");
	for(l=0;l<np;l++)
	{
		printf("%d process size",l+1);
		scanf("%d",&p[l]);
	}
	printf("Enter memory size for each block:\n");
	for(l=0;l<nm;l++)
	{
		printf("%d memory size",l+1);
		scanf("%d",&m[l]);
	}
	printf("\nProcess_no:\tProcess_size :\tBlock_no:\tBlock_size:\tFragement");
	int k=0,i=0;
		while(i<np)
		{
			int f1=0;
			for( j=k;j<nm;j++)// to get header position
			{
				if(m[j]>=p[i])//check the possibility
				{
					printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i+1,p[i],j+1,m[j],m[j]-p[i]);
					m[j]=m[j]-p[i];//update
					k=j;
					i++;
					f1=1;
				}
				if(k>nm)
					j=0;	
			}
			if(f1==0)//allocation not possible
			{
				printf("\nmemory not allocated for process %d\n",i+1);
				i++;
			}
		}
	
}