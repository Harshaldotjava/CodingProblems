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
int main(){
	int n = 5;
	vector<int> adj[n];
	adj[0] = {5,1,2,3,4};
	adj[1] = {1,0};
	adj[2] = {0,5};
	adj[3] = {0};
	adj[4] = {1,0};
	adj[5] = {0,2};
	
	bfs(adj,n,5);
	
	return 0;
}