#include <iostream>
#include <math.h>
#include <vector>
using namespace std;


#define PI 13.1415
#define screen_size 70


class Screen{
	
	char **matrix;
	int n;
	int m;

  public:
	Screen(int n, int m){
		
		this->n = n;
		this->m = m;
		this->matrix = new char *[n];
		for (int i = 0; i < n; i++){
			
			this->matrix[i] = new char[m];
			for (int j = 0; j < m; j++)
				this->matrix[i][j] = ' ';
		}
	};
	void render()
	{
		std::cout << "\x1b[H";
		for (int i = 0; i < this->n; i++)
		{
			for (int j = 0; j < this->m; j++)
			{
				std::cout << this->matrix[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}

	void plot(int x, int y, char p)
	{
		this->matrix[y][x] = p;
		return;
	}
};

class Point3D
{
  public:
	float x;
	float y;
	float z;

	Point3D()
	{
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}
	Point3D(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
};
class Cube
{
	public:
	vector<Point3D> points;
	Cube(){
		
		for(int y=20;y>=-20;y--){
			for(int x = -20;x<=20;x++){
			  if(x == 20 || x == -20 || y == 20 || y == -20)
				points.push_back(Point3D(x,y,-20));
			}
		}
		
		for(int y=20;y>=-20;y--){
			for(int x = -20;x<=20;x++){
			  if(x == 20 || x == -20 || y == 20 || y == -20)
				points.push_back(Point3D(x,y,20));
			}
		}
		for(int y=20;y>=-20;y--){
			for(int z= -20;z<=20;z++){
			  if(z == 20 || z == -20 || y == 20 || y == -20)
				points.push_back(Point3D(-20,y,z));
			}
		}
		
		for(int y=20;y>=-20;y--){
			for(int z= -20;z<=20;z++){
			  if(z == 20 || z == -20 || y == 20 || y == -20)
				points.push_back(Point3D(20,y,z));
			}
		}
		
		for(int z=-20;z<=20;z++){
		  
			for(int x=-20;x<=20;x++){
				if(x == 20 || x == -20 || z == 20 || z == -20)
					points.push_back(Point3D(x,20,z));
			}
		}
		
		for(int z=-20;z<=20;z++){
			for(int x=-20;x<=20;x++){
			  if(x == 20 || x == -20 || z == 20 || z == -20)
				points.push_back(Point3D(x,-20,z));
			}
		}
		
	}
};

// will do point translarion field of view other computations
class AsciiEngine
{
	vector<vector<float>> zbuffer;
	float Z0;
	float K2;
	float K1;
	float object_length;
	float resolution;

  public:
	//
	AsciiEngine(float distance_btw_objects_and_eye, float distance_between_screen_and_objects, float resolution){
		this->K2 = distance_btw_objects_and_eye;
		this->K1 = resolution * K2 * 1/(1* distance_between_screen_and_objects);
		this->object_length = distance_between_screen_and_objects;
		this->resolution = resolution;
	}


	Point3D translate(Point3D orignal, Point3D translation)
	{
		Point3D point;
		point.x = orignal.x + translation.x;
		point.y = orignal.y + translation.y;
		point.z = orignal.z + translation.z;
		return point;
	}

	Point3D rotationX(Point3D orignal, float theta)
	{
		float sinTheta = sin(theta);
		float cosTheta = cos(theta);

		Point3D rotatedPoint;
		rotatedPoint.x = orignal.x;
		rotatedPoint.y = cosTheta * orignal.y + sinTheta * orignal.z;
		rotatedPoint.z = -sinTheta * orignal.y + cosTheta * orignal.z;
		return rotatedPoint;
	}

	Point3D rotationY(Point3D orignal, float theta)
	{
		float sinTheta = sin(theta);
		float cosTheta = cos(theta);

		Point3D rotatedPoint;
		rotatedPoint.x = orignal.x * cosTheta + sinTheta * orignal.z;
		rotatedPoint.y = orignal.y;
		rotatedPoint.z = -sinTheta * orignal.x + cosTheta * orignal.z;
		return rotatedPoint;
	}

	Point3D applyPerspective(Point3D object)
	{
		Point3D projected;
		projected.x = int(object.x * K1 / (K2 + object.z) + screen_size / 2);
		projected.y = int(object.y * K1 / (K2 + object.z) + screen_size / 2);
		projected.z = object.z;
		return projected;
	}
	Point3D perspectiveOnFieldOfView(Point3D object)
	{
		Point3D projected;
		projected.x = int(object.x * Z0 / (Z0 + object.z) + screen_size / 2);
		projected.y = int(object.y * Z0 / (Z0 + object.z) + screen_size / 2);
		projected.z = object.z;
		return projected;
	}
};




int main()
{
	AsciiEngine engine(100, 100, screen_size);

	float theta = 0;
	float phi = 0;
	while (true)
	{
		Cube c = Cube();
		theta += 0.02;
		phi += 0.01;
		Screen s(screen_size, screen_size);
		for (int i=0;i<c.points.size();i++)
		{
			c.points[i] = engine.rotationY(c.points[i], theta);
			c.points[i] = engine.rotationX(c.points[i],phi);
			c.points[i] = engine.applyPerspective(c.points[i]);
	         
		    if ((c.points[i].x < screen_size && c.points[i].x > 0) && (c.points[i].y < screen_size && c.points[i].y > 0))
			{
				s.plot(c.points[i].x, c.points[i].y, '.');
			}
		}
		
		
		
		s.render();
	}
	return 0;
}
