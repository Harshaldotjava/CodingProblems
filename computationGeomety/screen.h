#include <iostream>
#include <vector>

using namespace std;

class Screen{
	char **matrix;
	int n;
	int m;
	public:
	 Screen(int n,int m){
	 	this->n = n; this->m = m;
	 	this->matrix = new char*[n];
	 	for(int i=0;i<n;i++){
	 	   this->matrix[i] = new char[m];
	 	   for(int j=0;j<m;j++)
	 	       this->matrix[i][j] = ' ';
	 	}
	 };
	 void print(){
	 	for(int i=0;i < this->n;i++){
	 		for(int j=0;j<this->m;j++){
	 			cout<<this->matrix[i][j]<<" ";
	 		}
	 		cout<<endl;
	 	}
	 }
	 
	 void plot(int x,int y,char p){
	 	this->matrix[y][x] = p;
	 	return;
	 }	
};


int main(){
	Screen scrn(50,50);
	return 0;	
}