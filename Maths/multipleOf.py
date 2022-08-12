def sumOfMult(below, *args):
	sum = 0
	print(args)
	for num in range(1,below):
		for i in args:
			if num % i == 0:
				sum += num
				break
	return sum
	
	
print(sumOfMult(1000,3,5))