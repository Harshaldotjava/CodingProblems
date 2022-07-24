#include <iostream>
#include <vector>
using namespace std;

template<typename T>
struct Node{
	T val;
	vector<Node*> childrens;
	Node(T val){
	   this->val = val;
	};	
};

void n_aryTreePreOrder(Node<int> *root){
	if(!root){
		cout<<root->val<<" ";
		for(auto child : root->childrens)
			n_aryTreePreOrder(child);	
	}
}

int main(int argc, char *argv[])
{
	Node<int> *root = new Node(20);
}