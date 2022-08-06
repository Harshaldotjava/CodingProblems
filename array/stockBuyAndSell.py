def minStock(stocks):
	minprice = stocks[0]
	maxProfit = 0
	
	for price in stocks:	
		minprice = min(minprice,price)	
		profit = price - minprice
		maxProfit = max(maxProfit,profit)
		
	if(maxProfit <= 0):
		return 0
	return maxProfit
	
	
print(minStock([7,6,4,3,1]))