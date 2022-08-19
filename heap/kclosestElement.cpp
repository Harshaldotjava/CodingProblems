#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<int> kclosest(vector<int> arr,int k,int x){
	priority_queue<pair<int,int>,vector<pair<int,int>>> q;
	vector<int> ans;
	
	for(auto val : arr){
		q.push({abs(val-x),val});
		if(q.size() > k){
			q.pop();
		}
	}
	while(!q.empty()){
		ans.push_back(q.top().second);
		q.pop();
	}
	return ans;
}

int main(){
	vector<int> arr = {5,6,7,8,9};
	auto v = kclosest(arr,3,7);
	for(int val : v) cout<<val<<endl;
	return 0;
}