#include <iostream>
#include <stack>
using namespace std;

int isValid(string s){
	int i = 0;
	int j = 1;
	int count = 0;
	int max = 0;
	for(int i=0;i<s.length()-1;i++,j++){
		if(s[i] == ')' && s[j] == '('){
			count+=2;
			i++; j++;
		}
		else{
			max = (max > count)? max : count;
			count = 0;
		}
	}
	return count;
}

int main(){
	string s =  ")()())";
	cout<<isValid(s)<<endl;
	return 0;
}
