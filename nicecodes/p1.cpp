#include <iostream>
#include <vector>
using namespace std;


string divi(int i,int div,string put){
	if(i % div == 0)
		return put;
	return "";
}


int main(){

	int num  = 1;
	
	while(num<100){
		vector<int> checks = {3,5};
		vector<string> message = {"fizz","buzz"}; 
		string output = "";
		for(int i=0;i<checks.size();i++){
			output += divi(num,checks[i],message[i]);
		}


		if(output != "") cout<<output<<endl;
		else cout<<num<<endl;
		num++;
	}

}
