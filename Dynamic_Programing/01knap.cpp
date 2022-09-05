#include <iostream>
#include <stdlib.h>
using namespace std;


int t[1000][1000];

int knapSack(int val[],int wieght[],int capacity,int n){
	if(n == 0 || capacity == 0){
		return t[n][capacity] = 0;
	}
	
	if(wieght[n-1] <= capacity){
		return t[n][capacity]  = max(
		  val[n-1] + knapSack(val,wieght,capacity - wieght[n-1],n-1),
		  knapSack(val,wieght,capacity,n-1)
		);
	}
	else
		return t[n][capacity] = knapSack(val,wieght,capacity,n-1);
}

int main(){
	memset(t,-1,sizeof(t));
	int wt[] ={1,3,4,5};
	int val[] ={1,4,5,7};
	int capacity = 7;
	
	cout<<knapSack(val,wt,capacity,4);
}