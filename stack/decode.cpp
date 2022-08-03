#include <iostream>
#include <stack>
#include <string>
#include <ctype.h>
using namespace std;

bool isNumber(string s){
	for(auto ch :s){
		if(!isdigit(ch))
		  return false;
	}
	return true;
}

string decode(string s){
	stack<string> st;
	
	for(int i=0;i<s.size();i++){
		if(s[i] != ']'){
			st.push(string(1,s[i]));
		}
		else{
			string substr = "";
			while(st.top() != "["){
				substr = st.top() + substr;
				st.pop();
			}
			st.pop();
			string k = "";
		    while(!st.empty() && isNumber(st.top())){
		    	k = st.top() + k;
		    	st.pop();	
			}
			for(int i=0;i<stoi(k);i++)
			   st.push(substr);
		}	
	}
	string ans = "";
	while(!st.empty()){
		ans = st.top() + ans;
		st.pop();
	}
	return ans;
}


int main(int argc, char *argv[])
{
	stack<string> s;
	string tmp_string(1,'s');
	cout<<decode("5[a2[bc{]]")<<endl;
}