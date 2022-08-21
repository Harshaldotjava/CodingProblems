#include <vector>
#include <iostream>
#include <list>
#include <queue>
#include <stdlib.h>
using namespace std;


void addEdge(vector<vector<int>> &graph,int src,int dst){
	graph[src].push_back(dst);
}

void bfs(vector<vector<int>>&graph,int node){
	queue<int> que;
	bool visited[graph.size()];
	memset(visited,false,graph.size()*sizeof(int));
	
	
	
	cout<<node<<" ";
	visited[node] = true;
	que.push(node);
	
	while(!que.empty()){
		node = que.front();
		que.pop();
		for(int i=0;i<graph[node].size();i++){
			
			if(!visited[graph[node][i]]){
				cout<<graph[node][i]<<" ";
				visited[graph[node][i]] = true;
	            que.push(graph[node][i]);

			}
		}
	}
}
int main(int argc, char *argv[])
{
	int v = 7;
	

	vector<vector<int>> graph;
	

}