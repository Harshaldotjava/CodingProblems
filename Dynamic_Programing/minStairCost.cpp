#include <iostream>
#include <vector>

using namespace std;


int minStair(vector<int> cost,int n){
	if(n == 0 || n == 1)
	   return 0;
	   
	
	int oneStep = cost[n-1] + minStair(cost,n-1);
	int twoStep = cost[n-2] + minStair(cost,n-2);
	return min(oneStep,twoStep);
	
}

int minStairMemo(vector<int> &cost){
	int dp[cost.size()+1];
	
	for(int i=0;i<cost.size()+1;i++){
		if(i == 0 || i == 1)
		   dp[i] = 0;
	    else{	   
	  	int stepOne = cost[i-1] + dp[i-1];
		  int stepTwo = cost[i-2] + dp[i-2];
		  dp[i] = min(stepOne,stepTwo);
	    }
	    
	}
	return dp[cost.size()];
}


int main(int argc, char *argv[])
{
	vector<int> v = {1,100,1,1,1,100,1,1,100,1};
//	reverse(v.begin(),v.end());
	cout<<minStairMemo(v);
}