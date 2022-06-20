#include <vector>
#include <iostream>
#include <list>
using namespace std;


void addEdge(vector<vector<int>> &graph,int src,int dst){
	graph[src].push_back(dst);
}
int main(int argc, char *argv[])
{
	int v = 5;
	

	vector<vector<int>> graph;
	for(int i=0;i<=v;i++){
		vector<int> v{i};
		graph.push_back(v);
	}
	
     
     addEdge(graph,1,2);
     addEdge(graph,1,3);
     addEdge(graph,1,5);
     addEdge(graph,2,1);
     addEdge(graph,2,3);
     
     
     for(auto i : graph){
		for(auto j : i)
			cout<<j<<" ";
		cout<<endl;
     }
}