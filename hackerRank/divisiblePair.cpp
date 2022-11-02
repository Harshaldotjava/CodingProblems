#include <iostream>
using namespace std;

/* given integers and positive interger k 
 * determind the number of (i,j) pairs where i < j
 * and array[i] + array[j] = k
 */


int solution(int *arr,int n,int k){
	int count = 0;

	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int pairSum = arr[i] + arr[j];
		    if(pairSum % k == 0) count++;	
		}
	}

	return count;
}


int main(){
	int arr[] = {1, 3, 2, 6, 1, 2};
	int n = sizeof(arr)/sizeof(*arr);
	int k=3;

	cout<<solution(arr,n,k)<<endl;
	return 0;
}
