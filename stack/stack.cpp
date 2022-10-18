#include <iostream>
#include <map>
#include <stack>
using namespace std;

bool solve(string s, string t){
	stack<char> sStk;
	stack<char> tStk;
	
	for(auto ch : s){
		if(!sStk.empty() && ch == '#')
			sStk.pop();
				
	}	
}

int main(int argc, char *argv[])
{
	cout<<solve("","");
}