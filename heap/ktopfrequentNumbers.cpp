#include<iostream>
#include <map>
#include <queue>

using namespace std;

//top k frequent numbers
int* kfrequent(int arr[],int n,int k){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> heap;
	map<int,int> mp;
	int ans[3];
	memset(ans,0,sizeof(ans));
	for(int i=0;i<n;i++)
		mp[arr[i]]++;
	
	for(auto i = mp.begin();i!=mp.end();i++){
		heap.push({i->second,i->first});
		if(heap.size()>k)
			heap.pop();
	}
	int i=0;
	while(heap.size() > 0){
		ans[i] = heap.top().second;
		heap.pop();
		i++;	
	}
	return ans;
}

int main(){
	int arr[] = {1,1,1,3,3,3,2,2,4,4};
	int *res = kfrequent(arr,9,3);
	
	for(int i=0;i<3;i++)
		cout<<*(res + i)<<endl;
	return 0;	
}