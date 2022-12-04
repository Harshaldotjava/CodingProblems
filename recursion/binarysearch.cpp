#include <iostream>
using namespace std;

int binarySearch(int arr[],int left,int right,int key){
    if(left <= right){
        int mid = left + (right - left)/2;

        if(arr[mid] > key)
            return binarySearch(arr,left,mid-1,key);
        if(arr[mid] < key)
            return binarySearch(arr,mid+1,right,key);

        return mid;
    }
    return -1;
}


int main(){

    int arr[] = {0,1,2,3,4,5,6};
    int size = sizeof(arr)/sizeof(arr[0]);

    int res = binarySearch(arr,0,size-1,2);
    cout<<res<<endl;
    return 0;
}
