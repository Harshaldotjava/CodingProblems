#include <iostream> 
using namespace std;

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
	
	Node(int val){
		data = val;
		left = NULL;
		right = NULL;
	}
	
};

Node* insert(Node *root,int val){
	if(root == NULL)
		return new Node(val);
	else if(val < root->data)
		root->left = insert(root->left,val);
	else if(val > root->data)
		root->right = insert(root->right,val);
		
	return root;
}

void preOrder(Node *root){
	if(root){
		 cout<<root->data<<" ";
		 preOrder(root->left);
		 preOrder(root->right);
	}

}

