#include <iostream>
#include <queue>
#include <vector>
using namespace std;



vector<int> ksortedArray(int arr[],int n,int k){
	priority_queue<int,vector<int>,greater<int>> queue;
	vector<int> result;
	for(int i=0;i<n;i++){
		queue.push(arr[i]);
		
		if(queue.size() > k){
			result.push_back(queue.top());
			queue.pop();	
		}
	}
	while(!queue.empty()){
		result.push_back(queue.top());
		queue.pop();
	}
	return result;	
}


int main(){
	int arr[] = {6,5,3,2,8,10,9};
	int size = sizeof(arr)/sizeof(int);
	vector<int> v = ksortedArray(arr,size,3);
	for(auto i : v) cout<<i<<endl;		
}