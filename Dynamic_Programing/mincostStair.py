def minCostStair(cost,n):
	if(n <= 1):
		return 0
		
	
	cost1 = cost[n-1] + minCostStair(cost,n-1)
	cost2 = cost[n-2] + minCostStair(cost,n-2)
	
	return min(cost1,cost2)
	
	
	
def dyna(cost):
	
	dp = [0]*(len(cost)+1)
	
	for n in range(len(cost) + 1):
		if(n <= 0):
			dp[n] = 0
		else:
			c1 = cost[n-1] + dp[n-1]
			c2 = cost[n-2] + dp[n-2]
			dp[n] = min(c1,c2)
			
	return dp[len(cost)]


def dynaFib(f):
	fib = [0] * (f+1)
	
	for n in range(f+1):
		if(n <= 2):
			fib[n] = n
		else:
			fib[n] = fib[n-1] + fib[n-2]
	
	return fib[f]
	



cost = [1,100,1,1,1,100,1,1,100,1]

print(dynaFib(2))