#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target ){
	vector<int> ans;
	int sum = 0;
	map<int,int> mp;

	for(int i=0;i<nums.size();i++){
		
		if(mp.find(target - nums[i]) != mp.end()){
			return {mp[target-nums[i]],i};
		}
		mp[nums[i]] = i;
	}
	return {0,0};
}



int main(int argc, char *argv[])
{
	vector<int> v = {3,2,3};
	auto ans = twoSum(v,6);
	for(auto num : ans)
	   cout<<num<<endl;
}