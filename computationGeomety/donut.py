import math



SCREEN_HEIGHT = 60
SCREEN_WIDTH = 60
R1 = 1
R2 = 2
K2 = 600


K1 = SCREEN_WIDTH * K2 * 3/(8*(R1+R2))

def donut(A):
	screen = []
	for i in range(SCREEN_HEIGHT):
		screen.append([" "]*SCREEN_WIDTH)
	cosA = math.cos(A)
	sinA = math.sin(A)
	
	theta = 0
	
	while theta < 2 * math.pi:
		theta += 0.1
		costheta = math.cos(theta)
		sintheta = math.sin(theta)
	
		phi = 0
		while phi < math.pi *2:
			phi += 0.01
			circleX = R2 + R1*costheta
			circleY = R1*sintheta
			circleZ = 0
			cosphi = math.cos(phi)
			sinphi = math.sin(phi)
			
			x = circleX * cosphi
			y = circleY
			z = (circleX * sinphi)
			
			x = x
			y = y * cosA + z * (-sinA)
			z = y * sinA + z * cosA + K2
			
			ooz = 1/z
			x = int(SCREEN_WIDTH/2 + K1*ooz*x)
			y = int(SCREEN_WIDTH/2 + K1*ooz*y)
			
			screen[x][y] = "."
	
	print('\x1b[H')	
	for i in range(SCREEN_HEIGHT):
		for j in range(SCREEN_WIDTH):
			print(screen[i][j], end=" ")
			
		print()
		
		
print("start")
a = 0
while True:
	donut(a)
	a += 0.2
print("end")

		
	
