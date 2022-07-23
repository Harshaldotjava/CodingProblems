#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef vector<pair<int,int>> edges;
class Graph{
	private:
 	vector<vector<pair<int,int>>> graph;
    public:
     Graph(int vertices){
     	for(int i=0;i<vertices;i++){
     	   vector<pair<int,int>> v;
     	   this->graph.push_back(v);
     	}	
     }
     void addEdges(int node,vector<pair<int,int>> nodes){
     	this->graph[node] = nodes;	
     }
     
      void display(){
         int i = 0;
     	for(auto vec : this->graph){
     		cout<<i<<"-> ";
     		for(auto pr : vec)
     		    cout<<pr.first<<":"<<pr.second<<" ";
     		cout<<endl;
     		i++;	
     	}	
     }
     
     void bst(int start){
     	queue<int> q;
     	bool visited[this->graph.size()];
     	for(int i=0;i < this->graph.size();i++)
     		visited[i] = false;
     		
     	visited[start] = true;
     	q.push(start);
     	
     	while(!q.empty()){
     		int popped = q.front();
     		q.pop();
     		cout<<popped<<" ";
     		for(auto pr : this->graph[popped]){
     			if(! visited[pr.first] ){
     				visited[pr.first] = true;
     				q.push(pr.first);
     			}	
     		}	
     	}
     	
     }
     		
};



int main(){
	
	Graph g = Graph(6);
	edges zero ={
	  pair(5,1),pair(2,3),
	  pair(1,5),pair(3,2)
    };
    
    edges one = { 
       pair(0,5),pair(3,7)
    };
    
    edges two = {
    	pair(0,3),pair(4,2)
    };
    
    edges three = {
      pair(0,2),pair(1,7)
    };
    edges four = {
      pair(5,1),pair(2,2)
    };
    edges five = {
      pair(0,1),pair(4,1)
    };
      
    g.addEdges(0,zero);
    g.addEdges(1,one);
    g.addEdges(2,two);
    g.addEdges(3,three);
    g.addEdges(4,four);
    g.addEdges(5,five);
	g.display();
	cout<<endl;
	g.bst(2);
}