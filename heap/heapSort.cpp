#include <stdio.h>
#include <stdlib.h>


void heapify(int arr[],int n,int i){
	int largest = i;
	int left = ((i+1)*2)-1;
	int right = (i+1)*2;
	
	if(left < n && arr[left]>arr[largest]){
		largest = left;
	}
	if(right < n && arr[right]>arr[largest]){
		largest = right;
	}
	
	if(largest!=i){
		int temp = arr[largest];
		arr[largest] = arr[i];
		arr[i] = temp;
		
		heapify(arr,n,largest);
	}
}


void heapsort(int arr[],int n){
    
	
	for(int i=n/2;i>=0;i--)
		heapify(arr,n,i);
		
	for(int i=n-1;i>0;i--){
		int temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		heapify(arr,i,0);
	}
	
}


int main()
{
	int arr[] = {10,9,6,-5,7,40,4,1};
	int n = sizeof(arr)/sizeof(int);
	
	heapsort(arr,n);
    	
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}