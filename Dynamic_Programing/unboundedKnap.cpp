#include <iostream>
using namespace std;

int memoize(int *arr,int *price,int n,int size){
    int t[n+1][size+1];

    for(int i=0;i<n+1;i++){
	for(int j=0;j<size+1;j++){
	   if(n == 0)
	      t[i][j] = 0;
	   else if(j >= arr[i-1]){

		t[i][j] = max(price[i] + t[i][j-arr[i-1]],t[i-1][j]);
	   }
	   else t[i][j] = t[i-1][j];
	}
    }

    return t[n][size];
}

int main(){



}
