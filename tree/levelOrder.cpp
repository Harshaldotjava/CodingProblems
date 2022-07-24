#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<vector<int >> levelOrder(Node *root){
	vector<vector<int>> ans;
	if(!root) return ans;
	queue<Node*> q;
	q.push(root);
	
	while(!q.empty()){
		vector<int> values;
		vector<Node*> nodes;
		while(!q.empty()){
			nodes.push_back(q.front());
			q.pop();	
		}
		for(auto node : nodes){
			values.push_back(node->val);
			if(node->left)
			   q.push(node->left);
			if(node->right)
			   q.push(node->right);
	    }
	    ans.push_back(values);	
	}
	return ans;
}
int main(int argc, char *argv[])
{
	
	
}