#include <iostream>
#include <vector>
#include <queue>

using namespace std;


vector<pair<int,int>> kclosetToOrigin(vector<vector<int>> points, int k){
	vector<pair<int,int>> result;
	priority_queue<pair<int,pair<int,int>>> heap;
	
	for(int i=0;i<points.size();i++){
		int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
		heap.push({dist,{points[i][0],points[i][1]}});
		if(heap.size() > k)
			heap.pop();	
	}
	
	while(!heap.empty()){
		result.push_back(heap.top().second);
		heap.pop();
	}
	return result;
}

int main(){
	vector<vector<int>> points = {{1,3},{-2,2},{5,8},{0,1}};
	auto res = kclosetToOrigin(points,2);
	for(auto i : res){
		cout<<i.first<<" "<<i.second<<endl;
	}
	return 0;	
}