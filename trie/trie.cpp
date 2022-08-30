#include <iostream>
using namespace std;

#define ALPHABET_SIZE 26


struct TrieNode{
	TrieNode *children[ALPHABET_SIZE];
	bool endOfWord;
	
	TrieNode(){
		for(int i=0;i<ALPHABET_SIZE;i++)
			this->children[i] = NULL;
			this->endOfWord = false;
	}
};

void insert(TrieNode *root,string key){

	for(auto current : key){
		if(root->children[current-'a'] == NULL){
			root->children[current-'a'] = new TrieNode();
		}
		root = root->children[current-'a'];
	}
	
	root->endOfWord = true;
}
int main(){
	
	TrieNode *trie = new TrieNode();
	
	return 0;
}