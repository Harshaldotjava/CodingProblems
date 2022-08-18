from plane import Screen

def isOdd(n):
	return n % 2 != 0


def square(n,screen):
	if isOdd(n):
		n += 1
	
	for y in range(n//2,(-n//2)-1,-1):
		for i in range(-n//2,(n//2)+1):
			x = i
			for z in range(-(n//2),(n//2)+1):
				print(x,y,z)
			


K2 = 50
K1 = 70*K2 * 3/(8*300)
screen = Screen(70,70)	
square(4,screen)
#screen.render()