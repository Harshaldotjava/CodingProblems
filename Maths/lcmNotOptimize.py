def lcm(num1, num2):
	num1Mul = {}
	num2Mul = {}
	i = 1
	while True:
		if num1 * i in num2Mul.keys():
			return num1 * i
		if num2 * i in num1Mul.keys():
			return num2 * i
			
		num1Mul[num1 * i] = i
		num2Mul[num2 * i] = i
		i += 1
		
		
		
print(lcm(7,10))
		