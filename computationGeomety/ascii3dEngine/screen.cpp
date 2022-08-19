#include <iostream>
#include <math.h>
using namespace std;
#define PI 13.1415
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
	 void render(){
	 	std::cout<<"\x1b[H";
	 	for(int i=0;i < this->n;i++){
	 		for(int j=0;j<this->m;j++){
	 			std::cout<<this->matrix[i][j]<<" ";
	 		}
	 		std::cout<<std::endl;
	 	}
	 }
	 
	 void plot(int x,int y,char p){
	 	this->matrix[y][x] = p;
	 	return;
	 }	
};

class Point3D{
	float x;
	float y;
	float z;
	
	public:
	Point3D(){
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}
	Point3D(float x,float y,float z){
		this->x = x;
		this->y = y;
		this->z = z;
	}
	
	float getX(){
		return this->x;
	}
	float getY(){
		return this->y;
	}
	float getZ(){
		return this->z;
	}
	void setX(float x){
		this->x = x;
	}
	void setY(float y){
		this->y = y;
	}
	void setZ(float z){
		this->z = z;	
	}
};


// will do point translarion field of view other computations
class AsciiEngine{
	float Z0;
	float field_of_view;
	public:
	AsciiEngine(float field_of_view,float resolution){
		this->field_of_view = field_of_view;
		this->Z0 = (resolution/2.0) / tan((field_of_view/2.0)* 3.14159275/180.0);
		
	}
	
	float getZ0(){
		return this->Z0;
	}
	
	Point3D translate(Point3D orignal,Point3D translation){
		Point3D point;
		point.setX(orignal.getX() + translation.getX());
		point.setY(orignal.getY() + translation.getY());
		point.setZ(orignal.getZ() + translation.getZ());
		return point;
	}
	
	Point3D rotationX(Point3D orignal,float theta){
		float sinTheta = sin(theta);
		float cosTheta = cos(theta);
		
		Point3D rotatedPoint;
		rotatedPoint.setX(orignal.getX());
		rotatedPoint.setY(cosTheta*orignal.getY() + sinTheta * orignal.getZ());
		rotatedPoint.setZ(-sinTheta*orignal.getY() + cosTheta*orignal.getZ());
	    return rotatedPoint;
	}
	
	Point3D rotationY(Point3D orignal,float theta){
		float sinTheta = sin(theta);
		float cosTheta = cos(theta);
		
		Point3D rotatedPoint;
		rotatedPoint.setX(orignal.getX()*cosTheta + sinTheta*orignal.getZ());
		rotatedPoint.setY(orignal.getY());
		rotatedPoint.setZ(-sinTheta * orignal.getX() + cosTheta * orignal.getZ());
	    return rotatedPoint;
	}
	
	Point3D applyPerspective(Point3D object){
		Point3D projected;
		projected.setX(int(object.getX()*Z0/(Z0 + object.getZ())) + 70/2 );
		projected.setY(int(object.getY()*Z0/(Z0 + object.getZ())) + 70/2 );
		projected.setZ(object.getZ());
		return projected;
	}
	Point3D centerProjection(Point3D obj, int x,int y){
	}
};


int main(){
	AsciiEngine engine(45,70);
	float theta = 0;
	
	while (true){
		Point3D points[8];
		points[0] = Point3D(20,20,20);
		points[1] = Point3D(20,20,-20);
		points[2] = Point3D(20,-20,20);
		points[3] = Point3D(20,-20,-20);
		points[4] = Point3D(-20,20,20);
		points[5] = Point3D(-20,20,-20);
		points[6] = Point3D(-20,-20,20);
		points[7] = Point3D(-20,-20,-20);
		
		theta += 0.1;
	    Screen s(70,70);
    	for(int i=0;i<8;i++){
  	 	points[i] = engine.rotationY(points[i],theta);	
    	}
	   for(int i=0;i<8;i++){
		points[i] = engine.applyPerspective(points[i]);
   	}
  	for(int i=0;i<8;i++){
		s.plot(points[i].getX(),points[i].getY(),'i');
  	}
  	s.render();
	}
	return 0;
}



