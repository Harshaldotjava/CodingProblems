#include <iostream>
#include <stack>
using namespace std;

int isValid(string s){
	int count = 0;
	int maxCount = 0;

	for(int i=0,j=1;j<s.length();i++,j++){
		if(s[i] == '(' && s[j] == ')'){
			count += 2;
			i++;j++;
		}
		else{
			cout<<count<<endl;
			maxCount = max(maxCount,count);
			count = 0;
		}
	}
	maxCount = max(maxCount,count);
	return maxCount;
}

int main(){
	string s =  "(()";
	cout<<isValid(s)<<endl;
	return 0;
}
