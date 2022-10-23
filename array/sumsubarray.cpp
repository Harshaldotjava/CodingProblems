#include <iostream>
#include <vector>
using namespace std;


/*
 * find subarray arrey of sum "s" return the starting and ending 
 * position of that subaray(not index)
 *
 */

//brute force method

vector<int> subSumB(int arr[],int n,int s){
	vector<int> ans;

	for(int i=0;i<n;i++){
		int sum = 0;
		for(int j=i;j<n;j++){
			sum += arr[j];
			if(sum == s){
				ans.push_back(i+1);
				ans.push_back(j+1);
				return ans;
			}
		}
		sum = 0;
	}
	ans.push_back(-1);
	ans.push_back(-1);
	return ans;
}

vector<int> subSumO(int arr[],int n,int s){
	vector<int> result;

	int sum = 0;
	int i=0;
	int j=0;
	while(j<n){
		if(sum < s){
			sum += arr[j];
			j++;
		}
		else if(sum == s){
			result.push_back(i+1);
			result.push_back(j;
			return result;
		}
		else{
			sum -= arr[i];
			i++;
		}
	}
	result.push_back(-1);
	result.push_back(-1);
	return result;
	
}

int main(){
	int arr[] = {1,2,3,7,5};
	int size = sizeof(arr)/sizeof(*arr);
    vector<int> result = subSumO(arr,size,12);
	for(auto i : result)
		cout<<i<<" \n";

	return 0;
}
