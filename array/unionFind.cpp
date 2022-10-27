#include <iostream>
#include <set>
using namespace std;

/* find union in sorted arrays
 * return count not elements
*/

bool search(int *arr,int size,int key){
	int low = 0, high = size-1;

	while(low <= high){
		int mid = (high + low)/2;
		if(arr[mid] == key) return true;

		cout<<arr[mid]<<endl;
		if(arr[mid] > key) high = mid-1;
		else low = mid + 1;
	}

	return false;
}

// if arrays are sorted
int unionCount(int *arr,int n,int *arr2, int n2){
	int total = n + n2;
	int commonElement = 0;

	for(int i=0;i<n2;i++){
        if(search(arr,n,arr2[i]))
			commonElement++;
	}

	cout<<commonElement<<endl;
	return total - commonElement;
}


// if arrays are not sorted
int unionUnsort(int *arr,int n,int *arr2,int n2){
	set<int> s;
	for(int i=0;i<n;i++)
		s.insert(arr[i]);
	for(int i=0;i<n2;i++)
		s.insert(arr2[i]);

	return s.size();
}


int main(){
    int array1[] = {85, 25, 1, 32, 54, 6};
	int array2[] = {85, 2} ;
	int n1 = sizeof(array1)/sizeof(*array1);
	int n2 = sizeof(array2)/sizeof(*array2);


	int result = unionUnsort(array1,n1,array2,n2);
	cout<<result<<endl;

}
