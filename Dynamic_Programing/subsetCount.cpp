#include <iostream>
#include <stdlib.h>
using namespace std;

int t[1000][1000];

int countSubset(int arr[],int n,int sum){
	if(sum == 0)
		return 1;
	if(n == 0)
		return 0;
	if(t[n][sum] != -1) return t[n][sum];
	
	if(arr[n-1] <= sum){
		return t[n][sum] = countSubset(arr, n-1, sum - arr[n-1]) +
		        countSubset(arr,n-1,sum);
	}
	else return t[n][sum] = countSubset(arr,n-1,sum);
}


int memoize(int arr[],int n,int sum){
	
	int count[n+1][sum+1];

	
	for(int i=0;i<n+1;i++){
	for(int j=0;j<sum+1;j++){
		if(j == 0)
		   count[i][j] = 1;
		  
	    else if(i == 0)
	    	count[i][j] = 0;
	    
	    else if(arr[i-1] <= j){
	    	count[i][j] = count[i-1][j-arr[i-1]] +
	    	              count[i-1][j];
	    }
	    else count[i][j] = count[i-1][j];
	}
	}
	
	return count[n][sum];
}



int main(int argc, char *argv[])
{
	int arr[] = {2,3,5,6,8,10};
		memset(t,-1,1000*1000);
	int size = sizeof(arr)/sizeof(int);
	
	cout<<countSubset(arr,size,10);
}