#include <iostream>
#include <stdio.h>
using namespace std;


void  print(int a,int b){
	for(int i=0;i<a;i++)
		cout<<b<<" ";
}


void even(int n){

	if(n<= 0) return;


	
	for(int i=1;i<n/2;i++){
		if(n % i == 0 ){
			if(i % 2 == 0)
			  printf("%d ",i);
		}
	}

	return;
}

void  displayConvert(char c){

	if(c == tolower(c)){
		printf("%c ",toupper(c));
	}
	else{
		printf("%c ",tolower(c));
	}

	return;
}

bool checkVowel(char a){
	if(a == 'o' || a==  'a' || a== 'e' || a== 'i'|| a== 'u'){
		return true;
	}

	return false;
}

int main(){
	char n;
	printf("enter no \n");
	scanf("%c",&n);
	displayConvert(n);
	return 0;
}
