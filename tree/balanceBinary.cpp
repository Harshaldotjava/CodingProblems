#include <iostream>
#include <cstdlib.h>
#include "tree.h"
using namespace std;


int height(Node *root){
	if(!root)
		return 0;
		
	return 1 + max(height(root->left),height(root->right));
}


int isBalance(Node *root){
	if(!root)
		return true;
		
	int hl = height(root->left);
	int hr = height(root->right);
	
	if(abs(hl-hr) > 1) return false;
	
	return isBalance(root->left) && isBalance(root->right);
}

int main(int argc, char *argv[])
{
	Node *root = NULL;
	
}