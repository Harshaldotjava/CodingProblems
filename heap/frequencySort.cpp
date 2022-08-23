#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;



vector<int> frequentSort(vector<int> v){
	priority_queue<pair<int,int>,vector<pair<int,int>>> heap;
	map<int,int> mp;
	vector<int> result;
	for(auto val : v)
		mp[val]++;
		
	for(auto i = mp.begin();i!=mp.end();i++ ){
		heap.push({i->second,i->first});
	}
	while(not heap.empty()){
		for(int i=0;i<heap.top().first;i++)
			result.push_back(heap.top().second);
		heap.pop();
	}
	return result;
}


int main(){
	vector<int> v = {1,1,1,3,2,2,4};
	auto ans = frequentSort(v);
	for(auto val : ans)
		cout<<val<<endl;
}
