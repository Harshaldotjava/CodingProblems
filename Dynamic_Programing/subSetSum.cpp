#include <iostream>

using namespace std;


bool subSetSum(int arr[],int n,int sum){
	if(sum == 0){
		return true;
	}
	if(n == 0){
		return false;
	}
	if( arr[n-1] <= sum){
		return subSetSum(arr,n-1,sum-arr[n-1]) ||
		subSetSum(arr,n-1,sum);
	}
	else
		return subSetSum(arr,n-1,sum);
}

bool memoSubset(int arr[],int n,int sum){
	bool t[n+1][sum+1];
	
	for(int i=0;i<n+1;i++){
		for(int j=0;j<sum+1;j++){
			if(j == 0)
				t[i][j] = true;
			else if(i == 0)
				t[i][j] = false;
			else if(arr[i-1] <= j){
				t[i][j] = t[i-1][j-arr[i-1]] ||
				t[i-1][j];
			}
			else t[i][j] = t[i-1][j];
		}
	}
	return t[n][sum];
}


int main(int argc, char *argv[])
{
	int arr[] = {2,3,7,8,10,1};
	int n = sizeof(arr)/sizeof(int);
	cout<<memoSubset(arr,n,14);
}