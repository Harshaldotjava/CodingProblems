#include <iostream>
#include <vector>
#include "../traverseArray.h"
using namespace std;

void swap(int &a,int &b){
	int temp = a;
	a = b;
	b = temp;
	return;
}

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

void move(int arr[],int n){
	vector<int> pos;
	vector<int> neg;

	for(int i=0;i<n;i++){
		if(arr[i] < 0) neg.push_back(arr[i]);
		else pos.push_back(arr[i]);		
	}

	int j = 0;
	for(int i=0;i<pos.size();i++){
		arr[j] = pos[i];
		j++;
	}
	for(int i=0;i<neg.size();i++){
		arr[j] = neg[i];
		j++;
	}

	return;
}
int main(){
    int arr[] = {1, -1, 3, 2, -7, -5, 11, 6};
	int n = sizeof(arr)/sizeof(*arr);
    traverse(arr,n);
	move(arr,n);
	traverse(arr,n);
	return 0;
}
