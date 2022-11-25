#include <iostream>
#include <stack>
using namespace std;


int isValid(string str){	
	stack<int> st;
	int count = 0;
	int maxCount = 0;
	for(int i=0; i<str.length();i++){
		int j;
		for(j=i;j<str.length();j++){
			if(str[j] == '(')
				st.push(str[j]);
			else if(str[j] == ')' && !st.empty()){
				st.pop();
				if(st.size() == 0)
					count = j-i+1;
			}
			else{
				count = j-i;
				break;
			}
		}
		while(!st.empty()) st.pop();
		
		maxCount = max(maxCount,count);
		count = 0;
	}
	return maxCount;
}
int main(){
	cout<<isValid("()(()");
	return 0;
}
