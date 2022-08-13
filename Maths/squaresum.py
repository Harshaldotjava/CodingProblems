import sys

sys.setrecursionlimit(10000)

def sumOftheSquare(n):
	if( n == 1):
		return 1
	sum = 0
	sum = n**2 + sumOftheSquare(n-1)
	return sum
	
def squareOftheSum(n):
	if(n == 0):
		return 0
	sum = n + squareOftheSum(n-1)
	return sum
	
def difference(n):
	return (squareOftheSum(n)**2)-sumOftheSquare(n)
	


print(difference(100)) 