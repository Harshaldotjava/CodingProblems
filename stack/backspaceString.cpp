#include <iostream>
#include <map>
#include <stack>
using namespace std;

stack<char> helper(string s){
	stack<char> ans;
	
	for(auto ch : s){
		if(!ans.empty() && ch == '#')
			ans.pop();
			
	   if(ch != '#')
	     ans.push(ch)
	}
	return ans;
}

bool solve(string s, string t){
	stack<char> a = helper(s);
	stack<char> b = helper(t);
	
	return a == b;	
}

int main(int argc, char *argv[])
{
	if(solve("ab#c","ad#c"))
		cout<<"true";
	else
	   cout<<"false";
}