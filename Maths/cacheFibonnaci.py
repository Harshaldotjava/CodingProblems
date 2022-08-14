import time

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
	
	
def fibgen(n):
	fib = cachefibo()
	for i in range(n):
		yield fib(i)
		
fibs = fibgen(10)
s = "hiiii"
sgen = iter(s)







	
	

