from plane import Screen

def isOdd(n):
	return n % 2 != 0


def square(n,screen):
	if isOdd(n):
		n += 1
		
	x = -(n//2)
	while x <= n//2:
		x += 0.1
		y = n//2
		while y >= -(n//2):
			y -= 0.1
			xp = int(K1*x / K2) + 70//2
			yp = int(K1*y / K2) + 70//2
			
			screen.plot(xp,yp,".")
			

square_size = 4
K2 = 10
K1 = 70*K2 * 1/(2*square_size)
screen = Screen(70,70)	
square(square_size,screen)
screen.render()
