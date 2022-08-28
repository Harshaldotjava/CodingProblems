#include <iostream> 
#include <vector>
using namespace std;


void comb(int n,vector<int> nums,int out){
	
	if(n == 0){
		cout<<out<<endl;
		return;
	}
	

	for(int i=0;i<nums.size();i++){
		int res = out;
		res = res*10 + nums[i];
		comb(n-1,nums,res);
	}
}


int main(){
	vector<int> v = {1,2,3,4,5,6,7,8,9};
	vector<int> result;
	comb(10,v,0);

}
