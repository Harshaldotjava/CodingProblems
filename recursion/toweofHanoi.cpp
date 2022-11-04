#include <iostream>
using namespace std;


void toh(char start,char end,char mid,int n){
	if(n == 1){
		cout<<"move "<<n<<"to "<<"end rod"<<endl;
		return;
	}

	toh(start,mid,end,n-1);
	cout<<"move "<<n<<"to "<<"end rod"<<endl;
	toh(mid,end,start,n-1);
}
	

int main(){
	toh('a','b','c',3);
	return 0;
}
