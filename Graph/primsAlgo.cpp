#include <vector>
#include <iostream>
#include <set>
using namespace std;

int minSpanning(vector<vector<int>> adj[],int v){
	vector<int> visited(v,false);
	set<pair<int,int>> st;
	st.insert({0,0});
	int ans = 0;
	while(st.size()>0){
		auto node = *st.begin();
		st.erase(st.begin());
		if(visited[node.second])
		    continue;
		ans += node.first;
		
		for(auto neigbhour : adj[node.second]){
			int vertice = neigbhour[0];
			int weight = neigbhour[1];
			if(!visited[vertice])
			   st.insert({weight,vertice});
		}
	}
	return ans;
}

int main(int argc, char *argv[])
{
	
}