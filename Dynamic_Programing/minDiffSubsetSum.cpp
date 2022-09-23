#include <iostream>
using namespace std;


bool *subsetSum(int arr[],int n,int sum){
	bool t[n+1][sum+1];
	
	for(int i=0;i<n+1;i++){
	for(int j=0;j<sum+1;j++){
		if(j == 0){
			t[i][j] = true;
		}
		else if(i == 0){
			t[i][j] = false;
		}
		else if(arr[i-1]<=j){
			t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
		}
		else t[i][j] = t[i-1][j];
	}
	}
	
	return t[n];
}


int minDiffSumPartition(int arr[],int n){
	int sum = 0;
	for(int i=0;i<n;i++) sum+=arr[i];
	
	bool *subsets = subsetSum(arr,n,sum);
	
	int minValue = INT_MAX;
	for(int i=0;i<=sum/2;i++){
		if(subsets[i]){
			int m = sum -(2*i);
			minValue = min(m,minValue);
		}
	}
	
	return minValue;
}


int main(int argc, char *argv[])
{
	int arr[] = {1,6,11,5};
	int size = sizeof(arr)/sizeof(int);
	cout<<minDiffSumPartition(arr,size);
	return 0;
	
}