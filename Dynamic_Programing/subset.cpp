#include <iostream>
using namespace std;



bool sum(int arr,int n, int k,int sum){
	if(sum == k)
		return true;
	if(n == 0)
		return false;
	
	return sum(int arr,n-1,sum+arr[n-1]) ||
	  sum(int arr,n-1,sum);
}


int main(){
	
	
	return 0;
}