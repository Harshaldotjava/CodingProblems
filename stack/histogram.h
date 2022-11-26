#include <vector>
#include "leftMin.h"
#include "rightMin.h"

int maxAreaHistogram(int arr[],int n){
    std::vector<int> rightMin = minRight(arr,n);
    std::vector<int> leftMin = minLeft(arr,n);

	int maxArea = 0; 
	for(int i=0;i<n;i++){
		int area = (rightMin[i] - leftMin[i]-1) * arr[i];
		maxArea = std::max(maxArea,area);
	}
	return maxArea;
}

