#include <stdio.h>
int main()
{
int Max[10][10], need[10][10], allocated[10][10], available[10],
completed[10], processorder[10];
int p, r, i, j, process, count;
count = 0;
printf("Total no of processes : ");
scanf("%d", &p);
for(i = 0; i< p; i++)
completed[i] = 0;
printf("\nNumber of resources : ");
scanf("%d", &r);
printf("\nEnter the Maximum Matrix for each process : ");
for(i = 0; i < p; i++)
{
printf("\nFor process %d : ", i + 1);
for(j = 0; j < r; j++)
scanf("%d", &Max[i][j]);
}
printf("\nEnter the allocation for each process : ");
for(i = 0; i < p; i++)
{
printf("\nFor process %d : ",i + 1);
for(j = 0; j < r; j++)
scanf("%d", &allocated[i][j]);
}
printf("\nEnter the Available Resources : ");
for(i = 0; i < r; i++)
scanf("%d", &available[i]);
for(i = 0; i < p; i++)
for(j = 0; j < r; j++)
need[i][j] = Max[i][j] - allocated[i][j];
do
{
printf("\n Max matrix:\tAllocation matrix:\n");
for(i = 0; i < p; i++)
{
for( j = 0; j < r; j++)
printf("%d ", Max[i][j]);
printf("\t\t");
for( j = 0; j < r; j++)
printf("%d ", allocated[i][j]);
printf("\n");
}
process = -1;
for(i = 0; i < p; i++)
{
if(completed[i] == 0)//if not completed
{
process = i ;
for(j = 0; j < r; j++)
{
if(available[j] < need[i][j])
{
process = -1;
break;
}
}
}
if(process != -1)
break;
}
if(process != -1)
{
printf("\nProcess %d runs to completion!", process + 1);
processorder[count] = process + 1;
count++;
for(j = 0; j < r; j++)
{
available[j] += allocated[process][j];
allocated[process][j] = 0;
Max[process][j] = 0;
completed[process] = 1;
}
}
}while(count != p && process != -1);
if(count == p)
{
printf("\nThe system is in a safe state!!\n");
printf("Safe Sequence : < ");
for( i = 0; i < p; i++)
printf("%d ", processorder[i]);
}
else
printf("\nThe system is in an unsafe state!!");
}