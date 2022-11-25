#include <iostream>
#include <vector>
#include "leftMin.h"
#include "rightMin.h"
using namespace std;

int maxAreaHistogram(int arr[],int n){
	vector<int> rightMin = minRight(arr,n);
	vector<int> leftMin = minLeft(arr,n);

	int maxArea = 0; 
	for(int i=0;i<n;i++){
		int area = (rightMin[i] - leftMin[i]-1) * arr[i];
		maxArea = max(maxArea,area);
	}
	return maxArea;
}

int main(){
	int histo[] = {6,2,5,4,5,1,6};
	int n = sizeof(histo)/sizeof(*histo);
	cout<<maxAreaHistogram(histo,n)<<endl;
	return 0;
}
