def sayHello(name,sirname):
	greeting = "hello {} {}"
	print(greeting.format(name,sirname))
	
	


def longestPalindrom(s):
	
	count = {}
	ans = 0
	isOdd = False
	for char in s:
		count[char] = count.get(char,0) + 1
		
	for value in count.values():
		if value % 2 == 0:
			ans += value
		else:
			isOdd = True
			ans += value - 1
	
	if isOdd:
		ans += 1
	return ans
	
	
print(longestPalindrom("abccccdd"))