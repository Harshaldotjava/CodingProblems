#include <iostream>
using namespace std;

void heapify(int arr[],int n,int i){
	int largest = i;
	int left = ((i+1)*2)-1;
	int right = (i+1)*2;
	
	if(left< n && arr[left] > arr[largest])
		largest = left;
	if(right < n && arr[right] > arr[largest])
		largest = right;
	
	if(largest != i){
		int temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		heapify(arr,n,largest);	
	}
}

int main(int argc, char *argv[])
{
	int arr[] = {8,3,4,1,3,6,8,4,3};
	int n = sizeof(arr)/sizeof(int);
	
	for(int i=n-1;i>=0;i--)
	   heapify(arr,n,i);
	   
	for(int i=0;i<n;i++)
	   cout<<arr[i]<<"  ";
	
}