#include <iostream>
#include <math.h>
#include <string>
#include <vector> 
#include <sstream>

using namespace std;


int main(){
	ostringstream ss;
	const float PI = 3.14159;
	float K2 = 0.7;
	float K1 = 70*K2 /(5);
	float theta = 0;
	
	vector<vector<string>> screen(70,vector<string>(70," "));
	int radius = 10;

	while(theta < 2*PI){
	
		theta += 0.524;
		float x = radius*cos(theta);
		float y = radius*sin(theta);
		float ooz = 1/K2;
		int px = int(70/2 + x*ooz);
		int py = int(70/2 + y*ooz);
		screen[py][px] = "??";
	
	}
	for(auto row : screen){
		for(auto pixel : row){
			cout<<pixel<<" ";
		}
		cout<<endl;
	}
	return 0;
}