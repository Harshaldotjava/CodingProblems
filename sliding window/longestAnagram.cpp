#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> findAnagrams(string s, string p){
	vector<int> ans;
	map<char,int> mp;
	for(char ch : p)
	    mp[ch]++;
	int count = mp.size();
	int i = 0;
	int j = 0;	
	
	while(j<s.size()){
		
		if(mp.find(s[j]) != mp.end()){
			mp[s[j]]--;
			if(mp[s[j]] == 0)
			    count--;
				
		}
	
		if(count == 0){
		   ans.push_back(i);
		}
		   
		if(j-i+1 == p.size()){
			if(mp.find(s[i]) != mp.end()){
				mp[s[i]]++;
				if(mp[s[i]] == 1)
				   count++;
			}
		
			i++;
		}
		j++;
	}
	return ans;
}

int main(int argc, char *argv[])
{
	string s = "baa";
	string p = "aa";
	auto res = findAnagrams(s,p);
	
	for(auto i : res){
		cout<<i<<" ";;	
	}
	
}