#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int minRopCost(vector<int> ropes){
	int result = 0;
	priority_queue<int,vector<int>,greater<int>> heap;
	
	for(int i=0;i<ropes.size();i++)
		heap.push(ropes[i]);
		
	while(heap.size() !=1){
		int rope1 = heap.top(); heap.pop();
		int rope2 = heap.top(); heap.pop();
		int newRope = rope1 + rope2;
		result += newRope;
		heap.push(newRope);
	}
	
	return result;
}
int main(){
	vector<int> v = {1,2,3,4,5};
	cout<<minRopCost(v);
}