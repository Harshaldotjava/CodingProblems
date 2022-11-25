#include <iostream>            
#include <map>
using namespace std; 



int solve(string s,int k){
	map<int> mp;
	int i=0;
	int j=0;
	int maxF = 0;
	int ans = 0;
	while(j<s.length()){ 
		mp[s[j]]++;
		maxF = max(maxF,mp[s[j]]++;
		while((j-i+1) - maxF > k){
			mp[s[i]]--;
			i++;
		}
		ans = max(ans,(i-j+1));
		j++;
	}
	return ans;
}    

int main(){
	return 0;
	}
