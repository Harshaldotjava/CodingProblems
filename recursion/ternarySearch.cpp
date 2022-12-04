#include <iostream>
using namespace std;

int ternarySearch(int arr[],int left,int right,int key){
    if(left <= right){

        int midFirst = left + (right - left) / 3;
        int midSecond = midFirst + (right - midFirst) / 3;
        
        if(key == arr[midFirst]) return  midFirst;
        if(key == arr[midSecond]) return midSecond;

        if(key < arr[midFirst])
            return ternarySearch(arr,left,midFirst-1,key);

        if(key > arr[midSecond])
            return ternarySearch(arr,midSecond+1,right,key);

        return ternarySearch(arr,midFirst+1,midSecond-1,key);

    }

    return -1;
}

int main(){
    int arr[] = {0,1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(*arr);

    cout<<ternarySearch(arr,0,n-1,10)<<endl;
}
