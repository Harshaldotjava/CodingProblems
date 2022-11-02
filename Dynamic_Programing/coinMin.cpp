#include <iostream>
using namespace std;


int coinWays(int *arr,int n,int sum){
	int ways[n+1][sum+1];
	
	for(int i=0;i<n+1;i++){
		for(int j=0;j<sum+1;j++){
			if(j == 0){
				ways[i][j] = 1;
			}
			else if(i==0){
				ways[i][j] = 0;
			}
			else if(arr[i-1] <= j){
				ways[i][j] = ways[i][j-arr[i-1]] + ways[i-1][j];
			}
			else ways[i][j] = ways[i-1][j];
		}
	}
	return ways[n][sum];
}

int main(){

	int arr[] = {1,2,3,4};
	int sum = 5;

	return 0;
}
