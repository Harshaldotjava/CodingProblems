#include <iostream>
#include <queue>
using namespace std;


// sun between kth smallest element
int kthSmallest(vector<int> v,int k){
	priority_queue<int> heap;
	
	for(int i=0;i<v.size();i++){
		heap.push(v[i]);
		if(heap.size() > k){
			heap.pop();
		}
	}
	
	return heap.top();
}

int solve(vector<int> v,int k1,int k2){
	
	int sum = 0;
	
	k1 = kthSmallest(v,k1);
	k2 =  kthSmallest(v,k2);
	
	for(auto val : v){
		if(val > k1 and val < k2 )
			sum += val;
	}
	
	return sum;
}


int main(){
	
	vector<int> v1 = {1,3,12,5,15,11};
	cout<<solve(v1,3,6)<<endl;
};