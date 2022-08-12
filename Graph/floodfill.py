def floodfil(image,sr,sc,color):
	if image[sr][sc] == color:
		return
	initialColor = image[sr][sc]
	
	def helper(image,i,j,color):
		
		if(i < 0 or i >= len(image)):
			return
		if(j<0 or j>= len(image[i])):
			return
		if(image[i][j] != initialColor):
			return
		
		image[i][j] = color
		
		helper(image,i+1,j,color)
		helper(image,i-1,j,color)
		helper(image,i,j+1,color)
		helper(image,i,j-1,color)
		
	
	ans = 0
	for i in range(len(image)):
		for j in range(len(image[i][i])):
			if(image[i][j] != 0):
				helper(image,i+1,j,0)
				ans ++
	return ans
	


image = [
  [0,2,3,0,5,8],
  [0,2,3,1,1,0],
  [0,2,6,1,1,0],
  [0,2,2,0,0,0],
  [1,0,2,2,2,1],
  [3,0,0,0,0,1]
]

for col in image:
	print(col)


floodfil(image,2,1,10)
print("--------------")
for col in image:
	print(col)
	