
class Matrix():
	
	def __init__(self,*rows):
		self.matrix = []
		for row in rows:
			self.matrix.append(row)
			
		
	def __getitem__(self,k):
		return self.matrix[k]
			
	def __mul__(self,b):
	   a = self.matrix
	   ans = [[0]*len(b[0]) for i in range(len(a))]
	   for i in range(len(a)):
	   	for j in range(len(b[0])):
	   		res = 0
	   		for k in range(len(a[i])):
	   			res += a[i][k] * b[k][j]
	   			ans[i][j] = res
	   return ans
	
			
			
mat1 = Matrix([1,2,3,5],[1,5,7,4])
mat2 = Matrix([5,8],[9,4],[1,5],[1,9])








"""

rotationX(
   x            y          z
 x 1            0          0
 y 0           cos(a)     sin(b)
 z 0           sin(a)     cos(a)
)


rotation y(
   cos(a)   0   -sin(a)
   0        1     0
   sin(a)   0    cos(a)

"""