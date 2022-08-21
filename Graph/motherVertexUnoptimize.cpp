#include <iostream>
#include <set>
#include <vector>
using namespace std;


void dfs(vector<int> adj[], int starting,set<int> &visited){
	visited.insert(starting);
	for(auto node : adj[starting]){
		if(visited.find(node) == visited.end()){
			dfs(adj,node,visited);
		}
	}
	
}

int motherVertex(vector<int> adj[],int n){
	for(int i=0;i<n;i++){
		set<int> visited;
		dfs(adj,i,visited);
		if(visited.size() == n)
			return i;
	}
	return -1;
}


int main(){
	int n = 5;
	vector<int> adj[n];
	adj[0] = {2,3};
	adj[1] = {0};
	adj[2] = {1};
	adj[3] ={4};
	adj[4] = {};
	cout<<motherVertex(adj,n);
	return 0;
}