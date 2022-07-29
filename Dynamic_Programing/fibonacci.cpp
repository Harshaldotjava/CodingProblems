#include <iostream>
using namespace std;


int fib(int n){
	
	int fibonacci[n+1];
	
	for(int i=0;i<=n+1;i++){
		if(i<2)
		   fibonacci[i] = i;
		else
		  fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
		  
	}
	return fibonacci[n];
}


int main(int argc, char *argv[])
{
	cout<<fib(5);
}