#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <set>
using namespace std;
#define ENTER_KEY 13

void bfs(vector<int> adj[],int n,int start){
	queue<int> q;
	q.push(start);
	set<int> visited;
	visited.insert(start);
	cout<<"visiting.....\n";
	while(!q.empty()){
		int node = q.front();
		q.pop();
		cout<<node<<" ";
		for(auto edge : adj[node]){
			if(visited.find(edge) == visited.end()){
				visited.insert(edge);
				q.push(edge);
			}
		}	
	}
	return;	
}

void dfs(vector<int> adj[], int starting,set<int> &visited){
	visited.insert(starting);
	for(auto node : adj[starting]){
		if(visited.find(node) == visited.end()){
			dfs(adj,node,visited);
		}
	}
	
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