#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

string possibleLexicalStr(string s){
	string ans = "";
	vector<int> frequency(0,s.size());
	for(char c : s)
		frequency[c - 'a']++;
		
	stack<int> st;
	reverse(s.begin(),s.end());
	int ind = 0;
	while(s.size()>0 || st.size()>0 ){
		if(ind != 26 && frequency[ind] == 0)
			ind++;
		
		if(st.size() && st.top() <= ind){
			ans.push_back(st.top() + 'a');
			st.pop();
			continue;
		}
		
		if(s.back() - 'a' == ind){
			frequency[ind]--;
			ans.push_back('a' + ind);
			s.pop_back();
		}
		else{
			frequency[ind];
			st.push('a' + ind);
			s.pop_back();
		}
	}
		
	
	return ans;
}


int main(int argc, char *argv[])
{
	
}