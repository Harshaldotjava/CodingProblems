#include <iostream>
#include <vector>
using namespace std;

#define FINAL_STATE 1
bool validLanguage(vector<pair<char,int>> g[],string s){
	int pos = 0;
	for(auto symbol : s){
		pos = g[pos][symbol - '0'].second;
	}
	
	return pos == FINAL_STATE;
}


int main(){
	vector<pair<char,int>> g[3];
	
	g[0].push_back({'0',1});
	g[0].push_back({'1',2});
	g[1].push_back({'0',1});
	g[1].push_back({'1',1});
	g[2].push_back({'0',2});
	g[2].push_back({'1',2});
	
	cout<<validLanguage(g,"103");

	return 0;
}