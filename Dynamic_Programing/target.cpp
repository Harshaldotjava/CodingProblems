#include <iostream>
using namespace std;


int targetSum(int arr[],int n,int sum){
	if(n == 0){
		if(sum == 0) return 1;
		return 0;
	}
	if(arr[n-1]> sum) return 0;
	return targetSum(arr,n-1,sum-arr[n-1]) + targetSum(arr,n-1,sum+arr[n-1]);
}

int countSum(int arr[],int n,int sum){
	int t[n+1][sum+1];
	
	for(int i=0;i<n+1;i++){
		for(int j=0;j<sum+1;j++){
			if(j == 0){
				t[i][j] = 1;
			}
			else if(i == 0){
				t[i][j] = 0;
			}
			else if(arr[i-1] <=j ){
				t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
			}
			else{
				t[i][j] = t[i-1][j];
			}
		}
	}
	return t[n][sum];
}

int memoize(int arr[],int n,int diff){
	int sum = 0;
	for(int i=0;i<n;i++) sum+= arr[i];
	
	int s = (diff + sum)/2;
	return countSum(arr,n,s);
}


int main(int argc, char *argv[])
{
	int arr[] ={1,1,2,3};
	int n = sizeof(arr)/sizeof(int);
	cout<<memoize(arr,n,1);
	return 0;
}