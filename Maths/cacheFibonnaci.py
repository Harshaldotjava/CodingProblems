
def cachefibo():
	fib = [-1] * 100000
	def func(n):
		nonlocal fib
		if n < 2:
			return n
		if fib[n] != -1:
			return fib[n]
		fib[n] = func(n-1) + func(n-2)
		return fib[n]
	return func
	
	
fibonacci = cachefibo()


print(fibonacci(10))


	
	

