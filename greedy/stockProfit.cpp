#include <iostream>
using namespace std;


int stockProfit(int stocks[],int n){
	int maxProfit = 0;
	int minStock = stocks[0];

	for(int i=0;i<n;i++){
		minStock = min(minStock,stocks[i]);
		maxProfit = max(maxProfit,stocks[i] - minStock);
	}
	return maxProfit;
}

int main(){
	return 0;
}
