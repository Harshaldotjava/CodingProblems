#include <iostream>
#include <string.h>
using namespace std;



//basic patternMatching Function
bool patternMatch(string s,string pat){
	
	for(int k=0;k<s.size();k++){
		int i= k;
		for(int j=0;j<pat.size();j++){
			if(pat[j] == s[i]){
				if(j == pat.size() -1)
					return true;
				i++;
			}
			else break;	
		}
	}
	return false;
}

int main(){
	
	string s = "harshal";
	string pat = "rsha";
	cout<<s.substr(0,3);
	//cout<<patternMatch(s,pat);
}