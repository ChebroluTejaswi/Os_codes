#include<stdio.h>
int main()
{
    int no_of_frames, no_of_pages, frames[10], pages[30], temp[10], flag1, flag2, flag3, i, j, k, pos, max, faults = 0;
    //inputs
    printf("Enter the number of pages: ");
    scanf("%d", &no_of_pages);
    printf("Enter the reference string: ");
    for(i = 0; i < no_of_pages; ++i){
        scanf("%d", &pages[i]);
    }
    printf("Enter the number of frames: ");
    scanf("%d", &no_of_frames);
    
    for(i = 0; i < no_of_frames; ++i)
    {
        frames[i] = -1;//initializing
    }
    
    for(i = 0; i < no_of_pages; ++i)
    {
        flag1 = flag2 = 0;
        for(j = 0; j < no_of_frames; ++j)
        {
            if(frames[j] == pages[i])
            {
                   flag1 = flag2 = 1;//hit 
                   break;
            }
        }
        
        if(flag1 == 0)//miss condition
        {
            for(j = 0; j < no_of_frames; ++j)
            {
                if(frames[j] == -1)//frame is empty initially 
                {
                    faults++;
                    frames[j] = pages[i];//allocation
                    flag2 = 1;
                    break;
                }
            }    
        }
        
        if(flag2 == 0)//flag1!=0 and flag2==0
        {
        	flag3 =0;
        	for(j = 0; j < no_of_frames; ++j)
        	{
            		temp[j] = -1;
            		for(k = i + 1; k < no_of_pages; ++k)
            		{
            			if(frames[j] == pages[k])//HIT CONDITION
            			{
            				temp[j] = k;
            				break;
            			}
            		}
            	}
            
            for(j = 0; j < no_of_frames; ++j)
            {
            	if(temp[j] == -1)//there is no hit in frame
            	{
            		pos = j;
            		flag3 = 1;
            		break;
            	}
            }
            
            if(flag3 ==0)//miss condition
            {
            	max = temp[0];
            	pos = 0;
            	
            	for(j = 1; j < no_of_frames; ++j)
            	{
            		if(temp[j] > max)//to check the longest unused value
            		{
            			max = temp[j];
            			pos = j;
            		}
            	}            	
            }
			
	     frames[pos] = pages[i];//allocation
	     faults++;
        }
        
        printf("\n");
        for(j = 0; j < no_of_frames; ++j)
	{
		if(frames[j]==-1)
			printf(" \t");
		else
            		printf("%d\t", frames[j]);
        }
    }
    printf("\n\nTotal Page Faults = %d\n", faults);
    return 0;
}