def spiralMatrix(matrix):
	spiral = list()
	rowBegin = 0
	rowEnd = len(matrix)
	columnBegin = 0
	columnEnd = len(matrix[0])
	
	while rowBegin <= rowEnd and columnBegin <= columnEnd:
		
		for i in range(len(matrix[rowBegin])):
			
			for i in range(columnBegin,columnEnd):
				spiral.append(matrix[rowBegin][i])
			rowBegin += 1
			
			for i in range(rowBegin,rowEnd):
				spiral.append(matrix[i][columnEnd-1])
			columnEnd -= 1
			
			if not (rowBegin < rowEnd and columnBegin < columnEnd):
				break
			
			for i in range(columnEnd-1,columnBegin - 1,-1):
				spiral.append(matrix[rowEnd-1][i])
			
			rowEnd -= 1
			
			for i in range(rowEnd-1,rowBegin-1,-1):
				spiral.append(matrix[i][columnBegin])
			
			columnBegin += 1
		
		return spiral
		
		
		
matrix =  [[1,2,3,4],[5,6,7,8],[9,10,11,12]]

print(spiralMatrix(matrix))