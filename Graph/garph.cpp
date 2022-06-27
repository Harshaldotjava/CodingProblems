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
	
	for(int i=0;i<=v;i++){
		vector<int> v;
		graph.push_back(v);
	}
	
	addEdge(graph,1,2);
	addEdge(graph,2,1);
	addEdge(graph,2,3);
	addEdge(graph,2,4);
	addEdge(graph,2,5);
	addEdge(graph,3,2);
	addEdge(graph,3,4);
	addEdge(graph, 3,6);
	addEdge(graph,4,3);
	addEdge(graph,4,2);
	addEdge(graph,5,2);
	addEdge(graph,5,6);
	addEdge(graph,6,5);
	addEdge(graph,6,3);
   bfs(graph,5);
    /*
    int pos = 0; 
     for(auto i : graph){
     	cout<<pos++<<"  ";
		for(auto j : i)
			cout<<j<<" ";
		cout<<endl;
     }
     */
}