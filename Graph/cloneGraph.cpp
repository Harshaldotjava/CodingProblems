#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Node{
	public:
	int val;
	vector<Node*> neighbors;
	Node(int val){
		this->val = val;	
	}
	Node(int val,vector<Node*>neighbors){
		this->val = val;
		this->neighbors = neighbors;
	}	
};

Node *clone(Node* node,map<Node*,Node*>&mp){
	Node* duplicate = new Node(node->val);
	mp[node] = duplicate;
	vector<Node*> neighbors;
	for(auto n : node->neighbors){
		if(mp.find(n) != mp.end())
			neighbors.push_back(mp[n]);
		else
			neighbors.push_back(clone(n,mp));	
	}
	duplicate->neighbors = neighbors;
	return duplicate;	
}

int main(){
	return 0;
}