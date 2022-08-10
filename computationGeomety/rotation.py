import math
from matrix import Matrix



		
def rotateY(x,y,z,deg):
	rad = math.radians(deg)
	degSin = round(math.sin(rad),2)
	degCos = round(math.cos(rad),2)
	rotationMatrix = Matrix(
	 [degCos,degSin,0],
	 [degSin*-1,degCos,0],
	 [0,0,1])
	point = Matrix([x],[y],[z])
	
	return rotationMatrix * point
	
	
def rotateY2D(x,y,deg,ox,oy):
	x -= ox
	y -= oy
	
	rad = math.radians(deg)
	degSin = math.sin(rad)
	degCos = math.cos(rad)
	rotationMatrix = Matrix(
	 [degCos,degSin],
	 [degSin,degCos],
	)
	point = Matrix([x],[y])
	point = rotationMatrix * point
	point[0][0] = int(point[0][0])
	point[1][0] = int(point[1][0])
	point[0][0] += ox
	point[1][0] += oy
	return point
	
	
	
	


