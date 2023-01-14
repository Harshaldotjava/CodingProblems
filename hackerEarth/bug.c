# include<stdio.h>

int main()
{
	int n;
	printf("Enter how many process: ");
	scanf("%d",&n);
	
	int bt[n],wt[n], tat[n], pro[n], total_tat=0, total_wt=0,i,t,j;
	
	for(i=0;i<n;i++) // accept bt
	{	 	
	 	printf("Enter Burst time of process [%d]: ", i+1 );
	 	scanf("%d", &bt[i]);
	 	pro[i]= i+1;
	 	
	 	printf("\n");
	}
	printf("hi");
	for(i=0,j=i+1;i<n,j<n;++i) // sorting
	{
		if(bt[i]>bt[j])
		{
			t=bt[i];
			bt[i]=bt[j];     //bt
			bt[j]=t;
			
			t=pro[i];
			pro[i]=pro[j];   //pro
			pro[j]=t;
		}
	}
	wt[0]=0;
	for(i=1,j=0;i<n,j<n;++i,j++)
	{ 
			
		wt[i]=0;
		wt[i]+=bt[j];
		total_wt+= wt[i];
	}
	for(i=0;i<n;i++)
	{
		tat[i]=bt[i]+wt[i];
		total_tat+= tat[i];
	}
	
	printf("Solution: \n\n");
	printf("Pro\t BT\t WT\t TAT\t");
		
	for(i=0;i<n;i++)
	{
		printf(" %d\t  %d\t  %d\t  %d\t",pro[i],bt[i],wt[i],tat[i]);
	}
	
	printf("\nAverage Waiting Time = %d\n",total_wt/n);
	printf("\nAverage Turn Arround Time = %d\n",total_tat/n);
		
	return 0;
}
