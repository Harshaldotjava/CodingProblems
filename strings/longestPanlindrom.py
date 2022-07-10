import sys
def palin(str,low,high):
	
	
	while(low >= 0 and high < len(str) and str[low] == str[high]):
		low -= 1
		high += 1
		
	
	return (high - low) - 1
	
	
def longestPalin(str):
	maximum = 0
	for i in range(0,len(str)-1):
		even = palin(str,i,i)
		odd = palin(str,i,i+1)
		num = max(even,odd)
		if(num > maximum):
			maximum = num
	return maximum

	

str = "keabaa"

t = longestPalin(str)
print(t)

	