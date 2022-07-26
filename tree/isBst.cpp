#include <iostream>
using namespace std;

struct Node{
	int val;
	Node *left = NULL;
	Node *right = NULL;
};

bool isBst(Node* root){
	static Node *prev = NULL;
	
	if(root){
		if(!isBst(root->left))
		   return false;
		   
		if(prev != NULL && prev->val <= root->val)
		    return false;
		   
		prev = root;
		
	    return isBst(root->right);	
	}
	return true;
}

int main(int argc, char *argv[])
{

	
}