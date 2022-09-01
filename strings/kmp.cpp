#include <iostream>
#include <string.h>
#include <vector>
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

vector<int> pie(string pat){
	int prevPie = 0;
	vector<int> result(pat.size(),0);
	
	int i = 1;
	while(i < pat.size()){
		if( pat[i] == pat[prevPie]){
			result[i] = prevPie + 1;
			prevPie++;
			i++;
		}
		else if(prevPie == 0){
			result[i] = 0;
			i++;
		}
		else
 		prevPie = result[prevPie - 1];
	}
	return result;
}

bool kmp(string s,string pat){
	vector<int> pi = pie(pat);
	
	int j = 0,i = 0;
	
	while(i<s.size()){
		if(s[i] == pat[j]){
			i++;
			j++;
		}
		else if(j == 0)
			i++;
		else
			j = pi[j-1];
		
		if(j == pat.size())
			return true;
	}
	return false;
}


int main(){
	
	string s = "harshal";
	string p = "rshl";
	cout<<kmp(s,p);
}