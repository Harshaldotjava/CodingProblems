#include <iostream>
#include <stdlib.h>

int t[1000][1000];
int subsetSumCount(int arr[],int n,int sum){
	if(sum == 0) return 1;
	if(n == 0) return 0;
	
	if(t[n][sum] != -1)
		return t[n][sum];
		
	if(arr[n-1] <= sum){
		return t[n][sum] = subsetSumCount(arr,n-1,sum-arr[n-1])
		       +
		       subsetSumCount(arr,n-1,sum);
	}
	else return t[n][sum] = subsetSumCount(arr,n-1,sum);
}


int memoize(int arr[],int n,int sum){
	
	int t[n+1][sum + 1];
	
	for(int i = 0;i<n+1;i++){
		for(int j = 0;j<sum+1;j++){
			if(j == 0)
				t[i][j] = 1;
			else if(i == 0)
				t[i][j] = 0;
			else if(arr[i-1] <= j){
				t[i][j] = t[i-1][j] + t[i-1][j - arr[i-1]];
			}
			else t[i][j] = t[i-1][j];
			
		}
	}
	
	return t[n][sum];
}

int main(int argc, char *argv[])
{

	memset(t,-1,1000*1000);
	int arr[] = {2,3,5,6,8,10};
	int n = sizeof(arr) / sizeof(int);
	
	std::cout<<memoize(arr,n,10);
	
}