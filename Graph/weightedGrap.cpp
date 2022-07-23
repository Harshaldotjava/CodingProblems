#include <iostream>
#include <queue>
#include <vector>
#include <set>
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
     
     vector<int> disjktra(int start){
     	int n = this->graph.size();
     	vector<int> visited(n,false);
     	vector<int> distance(n,INT_MAX);
     	set<pair<int,int>> st;
     	st.insert({0,start});
     	distance[start] = 0;
     	while(st.size()>0){
     		auto node = *st.begin();
     		int v = node.second;
     		int dist = node.first;
     		st.erase(st.begin());
     		if(visited[v]) continue;
     		visited[v] = true;
     		
     		for(auto neighbour : this->graph[v]){
     			int neigh_v = neighbour.first;
     			int wt = neighbour.second;
     			if(wt + dist < distance[neigh_v]){
     			    distance[neigh_v] = wt + dist;
     			    st.insert({wt+dist,neigh_v});
     			}
     		}	
     	}
     	return distance;		
     }
     		
};



int main(){
	
	Graph g = Graph(7);
	
    edges one = { 
       pair(2,1),pair(3,5)
    };
    
    edges two = {
    	pair(3,1),pair(4,2),pair(5,1)
    };
    
    edges three = {
      pair(5,2)
    };
    edges four = {
      pair(6,1),pair(5,3)
    };
    edges five = {
      pair(6,2)
    };
      
   
    g.addEdges(1,one);
    g.addEdges(2,two);
    g.addEdges(3,three);
    g.addEdges(4,four);
    g.addEdges(5,five);

	
	g.bst(1);
	cout<<endl;
	auto res = g.disjktra(1);
	
	for(auto i : res){
		cout<<i<<" ";	
	}
}