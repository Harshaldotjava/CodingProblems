#include <iostream>
#include "tree.h"
using namespace std;


Node *lowAncestor(Node* root,Node* p,Node *q){
	if(root == NULL)
		return root;
		
	if(root->data > p->data && root->data > q->data)
	    return lowAncestor(root->left,p,q);
	
	 if(root->data < p->data && root->data,p,q) 
	    return lowAncestor(root->right,p,q);
	    
	 return root;
}

int main(int argc, char *argv[])
{
	
}