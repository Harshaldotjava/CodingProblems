#include <iostream>
using namespace std;

int uniquePath(int m,int n){
	if(m == 1 || n == 1)
	   return 1;
	   
	return uniquePath(m-1,n) + uniquePath(m,n-1);
	
}

int uniquePathMemo(int m,int n){
	int paths[m+1][n+1];
	
	for(int i=1;i<m+1;i++){
		for(int j=1;j<n+1;j++){
			if(i == 1 || j == 1)
			   paths[i][j] = 1;
			else{
				paths[i][j] = paths[i-1][j] + paths[i][j-1];
			}
		}
	}
	return paths[m][n];
}


int main(int argc, char *argv[])
{
	cout<<uniquePathMemo(2,3);
	
}
