#include <iostream>
using namespace std;


int freq(int arr[],int n,int k){
    unsigned int result = 0;

    for(int i=0;i<n;i++){
	if(arr[i] == k) result++;
    }

    return result;
}


int main(){

}
