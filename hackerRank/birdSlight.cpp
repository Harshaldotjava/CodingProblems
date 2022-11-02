#include <iostream>
#include <stdlib.h>
using namespace std;

int solve(int *arr,int n){
	int result = 0, m = 0;

	for(int i=0;i<n;i++)
		m = max(arr[i],m);
	int map[m+1];
	memset(map,0,sizeof(map));

	for(int i=0;i<n;i++)
		map[arr[i]]++;

	int h = 0;
	for(int i=0;i<m+1;i++){
		if(map[i] > h){
			result = i;
			h = map[i];
		}
	}

	return result;
}

int main(){
	int arr[] = {1,1, 2,2, 3};
	int n = sizeof(arr)/sizeof(*arr);
	cout<<solve(arr,n);
	return 0;
}
