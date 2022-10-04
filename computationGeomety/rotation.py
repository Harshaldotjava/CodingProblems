import math
from matrix import Matrix


class Point:
	
	def __init__(self,x,y):
		self.x = x
		self.y = y
		

		
def rotateY(x,y,z,rad):

	degSin = round(math.sin(rad),2)
	degCos = round(math.cos(rad),2)
	rotationMatrix = Matrix(
	 [degCos,degSin,0],
	 [degSin*-1,degCos,0],
	 [0,0,1])
	point = Matrix([x],[y],[z])
	
	return rotationMatrix * point
	
	
	
def rotate2D(x,y,deg,ox,oy):
	x -= ox
	y -= oy
	
	rad = math.radians(deg)
	rad = deg
	degSin = math.sin(rad)
	degCos = math.cos(rad)
	rotationMatrix = Matrix(
	 [degCos,degSin],
	 [-degSin,degCos],
	)
	product = Matrix([x],[y])
	product = rotationMatrix * product
	point = Point(int(product[0][0]),int(product[1][0]))
	point.x += ox
	point.y += oy
	return point
	
	
	
	


