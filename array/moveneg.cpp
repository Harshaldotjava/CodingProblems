#include <iostream>
#include "../traverseArray.h"
using namespace std;


int solve(int arr[],int n){
	
	int i = 0;
	int j= 0;
	while(j<n){
		if(arr[j] > 0){
			swap(arr[i],arr[j]);
			i++;
		}
		j++;
	}
	return 0;
}
int main(){
    int arr[] = {1, -1, 3, 2, -7, -5, 11, 6 };
	int n = sizeof(arr)/sizeof(*arr);
    traverse(arr,n);
	solve(arr,n);
	traverse(arr,n);
	return 0;
}
