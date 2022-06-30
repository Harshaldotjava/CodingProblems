#include <iostream>
using namespace std;




int main(int argc, char *argv[])
{
	int Lmt[3][2] ={{3,4},{7,2},{5,9}};
	int Lrow = 3,Lcol = 2;
	
	int Rmt[2][3] = {{3,1,5},{6,9,7}};
	int Rrow = 2, Rcol = 3;
	
	int matrix[Lrow][Rcol];
	
	for(int i=0;i<Lrow;i++){
		
		for(int j=0;j<Rcol;j++){
			int ans = 0;
			for(int k=0;k<Lcol;k++){
				ans += Lmt[i][k] * Rmt[k][j];
		
			}
			matrix[i][j] = ans;
		}
	}
	
	for(int i=0;i<Lrow;i++){
		for(int j=0;j<Rcol;j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	
}