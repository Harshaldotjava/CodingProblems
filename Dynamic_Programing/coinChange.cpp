#include <iostream>
using namespace std;

/*
 * input: [1,2,3]
 * output: 5
 * explanation: ways to get five
 * -> 1+1+1+1+1 = 5
 * -> 2 + 3 = 5
 * -> 2+2+1 = 5
 * -> 1+1+1+2 = 5
 * -> 1 + 1 + 2 = 5
 *  total 5 ways
*/



// resursive approach
int solve(int arr[],int n,int sum){
    if(n == 0) return 0;

    if(sum == 0) return 1;

    if(arr[n-1] <= sum){
	return solve(arr,n,sum-arr[n-1]) + solve(arr,n-1,sum);
    }
    else return solve(arr,n-1,sum);
}

//memoization

int solve2(int arr[],int n,int sum){
	int t[n+1][sum+1];

	for(int i=0; i<n+1; i++){
	for(int j=0; j<sum+1;j++){

		if(j == 0) t[i][j] = 1;
		else if(i == 0) t[i][j] = 0;
		else if(arr[i-1] <= j){
			t[i][j] = t[i][j-arr[i-1]] + t[i-1][j];
		}
		else t[i][j] = t[i-1][j];
	}
	}

	return t[n][sum];
}


int main(){
	int arr[] = {1,2,3};
	int n = 3;
	cout<<solve2(arr,n,5)<<endl;
	return 0;
}
