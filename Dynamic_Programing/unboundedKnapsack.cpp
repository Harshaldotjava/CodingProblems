#include <iostream>
using namespace std;


int rodCut(int lengths[],int price[],int n, int size){
	int t[n+1][size+1];
	
	for(int i=0;i<n+1;i++){
	for(int j=0;j<size+1;j++){
		if( i==0 || j==0 )
			t[i][j] = 0;
		else if(lengths[i-1] <= j){
			t[i][j] = max(
				price[i-1] + t[i][j-lengths[i-1]], t[i-1][j]
			);
		}
		else t[i][j] = t[i-1][j];
	}
	}
	
	return t[n][size];
}

int main(int argc, char *argv[])
{
	int arr[] = {1,2,3,4,5,6,7,8};
	int price[] ={1,5,8,9,10,17,17,20};
	int n = sizeof(arr)/sizeof(*arr);
	int size = 8;
	
	cout<<rodCut(arr,price,n,size)<<endl;
}
