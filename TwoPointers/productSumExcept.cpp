#include <iostream>
#include <vector>
using namespace std;


vector<int> solve(vector<int> &nums){
	int prodLeft[nums.size()+1];
	prodLeft[0] = 1;
	
	int prodRight[nums.size()+1];
	prodRight[nums.size()] = 1;
	
	for(int i=0;i<nums.size();i++){
		prodLeft[i+1] = prodLeft[i]*nums[i];
	}
	
	for(int i=nums.size()-1;i>=0;i--)
		prodRight[i] = prodRight[i+1]*nums[i];
	
	vector<int> ans;
	
	for(int i=0;i<nums.size();i++){
		ans.push_back(prodLeft[i]*prodRight[i+1]);		
	}
	
	return ans;

}



int main(int argc, char *argv[])
{
	vector<int> v = {1,2,3,4};
	auto ans = solve(v);
	
	for(auto i:ans)
		cout<<i<<" ";
		
	
}