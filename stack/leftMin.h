#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> minLeft(int arr[],int n){
	stack<pair<int,int>> st;
	vector<int> ans(n,-1);

	for(int i=0;i<n;i++){
		if(st.empty()){
			ans[i] = -1;
		}
		else if(st.top().second < arr[i]){
			ans[i] = st.top().first;
		}
		else{
			while(!st.empty() && st.top().second >= arr[i])
				st.pop();
			if(st.empty())
				ans[i] = -1;
			else
				ans[i] = st.top().first;
		}
		st.push({i,arr[i]});
	}
	
	return ans;
}


