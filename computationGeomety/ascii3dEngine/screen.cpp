#include <iostream>
#include <math.h>
using namespace std;
#define PI 13.1415

#define screen_size 70
class Screen
{
	char **matrix;
	int n;
	int m;

  public:
	Screen(int n, int m)
	{
		this->n = n;
		this->m = m;
		this->matrix = new char *[n];
		for (int i = 0; i < n; i++)
		{
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

// will do point translarion field of view other computations
class AsciiEngine
{
	float Z0;
	float K2;
	float K1;
	float object_length;
	float resolution;

  public:
	//
	AsciiEngine(float distance_btw_objects_and_eye, float distance_between_screen_and_objects, float resolution){
		
		this->K2 = distance_btw_objects_and_eye;
		this->K1 = resolution * K2 * 1 / (1 * distance_between_screen_and_objects);
		this->object_length = distance_between_screen_and_objects;
		this->resolution = resolution;
	}

	float getZ0()
	{
		return this->Z0;
	}

	void setDistanceBtwObject(float K2)
	{
		this->K2 += K2;
	}
	void fov(float fov)
	{
		this->K2 = fov;
		this->K1 = resolution * fov * 1 / (1 * object_length);
	
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

class Cube
{
	Point3D points[8];

  public:
	Cube()
	{
	}
};

int main()
{
	AsciiEngine engine(9990, 100, screen_size);

	float theta = 0;
	float phi = 0;
	while (true)
	{	
		Point3D points[8];
		points[0] = Point3D(20, 20, 20);
		points[1] = Point3D(20, 20, -20);
		points[2] = Point3D(20, -20, 20);
		points[3] = Point3D(20, -20, -20);
		points[4] = Point3D(-20, 20, 20);
		points[5] = Point3D(-20, 20, -20);
		points[6] = Point3D(-20, -20, 20);
		points[7] = Point3D(-20, -20, -20);

		theta += 0.02;
		phi += 0.01;
		Screen s(screen_size, screen_size);
		for (int i = 0; i < 8; i++)
		{
			points[i] = engine.rotationY(points[i], theta);
			points[i] = engine.rotationX(points[i],phi);
			points[i] = engine.applyPerspective(points[i]);
	
		    if ((points[i].x < screen_size && points[i].x > 0) && (points[i].y < screen_size && points[i].y > 0))
			{
				s.plot(points[i].x, points[i].y, 'i');
			}
		}
		
		
		s.render();
	}
	return 0;
}
