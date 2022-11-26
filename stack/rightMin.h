#include <stack>
#include <vector>
#include <utility>

std::vector<int> minRight(int arr[],int n){
    std::stack<std::pair<int,int>> st;
    std::vector<int> ans(n,-1);

	for(int i = n-1; i!=-1; i--){
		if(st.empty())
			ans[i] = n;
		else if(st.top().second >= arr[i]){
			while(!st.empty() && st.top().second >= arr[i])
				st.pop();
			if(st.empty()) ans[i] = n;
			else ans[i] = st.top().first;
		}
		else ans[i] = st.top().first;

		st.push({i,arr[i]});
	}
	return ans;
}


