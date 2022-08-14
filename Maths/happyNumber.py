from functools import reduce
import time

def split(number):
	numbers = []
	
	while number != 0:
		numbers.append(number % 10)
		number = number //10
		
	return numbers[::-1]
	


def isHappy(n):
	
	
	s = set()
	while True:
		numbers = split(n)
		sum = 0
		for number in numbers:
			sum += number**2
		if sum in s:
			return False
		s.add(sum)
		if sum == 1:
			return True
		n = sum
		
		
		
lis = [1,2,3,4,5]
print(isHappy(19))

		