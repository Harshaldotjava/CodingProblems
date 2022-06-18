#include <iostream>
#include <vector>
using namespace std;


int trap(vector<int> height){
	int maxl[height.size()];
	int maxr[height.size()];
	int sum = 0;
	maxl[0] = height[0];
	maxr[height.size()-1] = height[height.size()-1];
	
	for(int i=1;i<height.size();i++)
		maxl[i] = max(height[i],maxl[i-1]);
	
	for(int i = height.size()-2;i>=0;i--)
		maxr[i] = max(height[i],maxr[i+1]);
		
	for(int i=0;i<height.size();i++){
		maxl[i] = min(maxl[i],maxr[i]);
		maxl[i] = maxl[i] - height[i];
		sum += maxl[i];
	}
	return sum;
}


int main(int argc, char *argv[])
{
	vector<int> v = {4,2,0,3,2,5};
	cout<<trap(v);
}