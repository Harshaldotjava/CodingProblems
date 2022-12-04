#include <iostream>
using namespace std;


int solution(int *arr,int n){
    int min = INT_MAX;

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int xOr = (arr[i] & arr[j]) ^ (arr[i] | arr[j]);
            if(xOr < min)
                min = xOr;
        }
    }
    return min;
}


int main(){
    int arr[] = {2,4,7};
    cout<<solution(arr,3);
    return 0;
}
