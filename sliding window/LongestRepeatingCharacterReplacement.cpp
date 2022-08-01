#include <iostream>
#include <map>
using namespace std;


int solve(string s,int k){
	int ans = 0;
	map<char,int> mp;
	int maxf = 0;
	int i = 0;
	int j = 0;
	
	while(j<s.size()){
		
		mp[s[j]]++;
	    maxf = max(maxf,mp[s[j]]);
	  
	    while((j-i)+1 - maxf > k){
	       mp[s[i]]--;
	       i++;
	    }
	    
	    ans = max(ans,j-i+1);
	    j++;	
	}
	return ans;
}

int main(int argc, char *argv[])
{
	string s = "AAAB";
	cout<<solve(s,1);
}