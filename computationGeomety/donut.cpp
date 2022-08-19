#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

#define PI 13.14159
#define SCREEN_WIDTH 70
#define SCREEN_HEIGHT 70


float R1 = 1;
float R2 = 2;
float K2 = 100;
int field_of_view = 130;

float K1 = SCREEN_WIDTH * K2 * 3/(8*(R1+R2));
//float K1 = (SCREEN_WIDTH/2)/tan((field_of_view/2.0) * PI/180);


void render(float A,float B){
	vector<vector<char>> screen(SCREEN_HEIGHT,vector<char>(SCREEN_WIDTH,' '));
	float cosA = cos(A);
	float sinA = sin(A);
	float cosB = cos(B);
	float sinB = sin(B);
	float theta = 0;
	while (theta < 2 * PI){
		theta += 0.1;
		float costheta = cos(theta);
		float sintheta = sin(theta);
		
		float phi = 0;
		while(phi < 2*PI){
			phi += 0.1;
			float cosPhi = cos(phi);
			float sinPhi = sin(phi);
			
			float circleX = R2 + R1*costheta;
			float circleY = R1*sintheta;
		
			
			float x = cosPhi*circleX;
			float y = circleY;
			float z = -sinPhi*circleX;;
		    //rotate at x direction	
		   
		    x = x;
		    y = cosA * y + sin(A) *z;
		    z = -sinA * y + cosA * z + K2;
		
			int px = int(x * K1 / z) + SCREEN_WIDTH/2;
		    int py = int(y * K1/ z ) + SCREEN_HEIGHT/2;
		    
			screen[py][px] = '.';
		}
		
	}

	cout<<"\x1b[H";
	for(auto col : screen){
		for(auto pixel : col)
			cout<<pixel<<" ";
		cout<<endl;
	}
	
}



int main(){

	float A = 0;
	while(true){
		render(A,0);
		A += 0.1;
	}
	return 0;
	
}