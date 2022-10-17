#include <iostream>
using namespace std;

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = *a;
}

int sort(int *arr,int n){
   int track = 0;

   for(int i=track;i<n;i++){
	if(arr[i] == 0){
	   swap(arr[i],arr[track]);
	   track++;
	}
   }

   for(int i=track;i<n;i++){
	if(arr[i] == 1){
	   swap(arr[i],arr[track]);
	   track++;
	}
   }

   return 1;

}

int main(){
   int arr[] = {1,2,0,0,2,2,0,1,1};
   int n = sizeof(arr)/sizeof(*arr);

   sort(arr,n);
   for(int i=0;i<n;i++)
	cout<<arr[i]<<" ";


   return 0;

}
