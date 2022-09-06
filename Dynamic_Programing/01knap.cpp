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

int TopDown(int val[],int wt[],int capacity,int n){
	int t[n+1][capacity + 1];
	
	for(int i=0;i<n+1;i++){
		for(int j=0; j<capacity+1;j++){
			if(i == 0 || j ==0){
				t[i][j] = 0;
			}
			else if( wt[i-1] <= j ){
			
				t[i][j] = max( val[i-1] + t[i-1][j-wt[i-1]],
				  t[i-1][j]);
		
			}
			else{
				t[i][j] = t[i-1][j];
			}
		}
	}
	return t[n][capacity];
}

int main(){
	memset(t,-1,sizeof(t));
	int wt[] ={1,3,4,5};
	int val[] ={1,4,5,7};
	int capacity = 7;
	
	cout<<TopDown(val,wt,capacity,4);
}