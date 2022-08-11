import math
from plane import Screen

r1 = 1
r2 = 2

k2 = 1000
screen_width = 70
screen_height = 70

k1 = screen_width * k2 *3/(8*(r1+r2))
screen = Screen(screen_height,screen_width)
def donut(a,b):
	cosa = math.cos(a)
	sina = math.sin(a)
	cosb = math.cos(b)
	sinb = math.sin(b)
	theta = 0
	while theta < math.pi * 2:
		theta += 0.1
		costheta = math.cos(theta)
		sintheta = math.sin(theta)
		phi = 0
		while phi < 2 * math.pi:
			phi += 0.5
			cosphi = math.cos(phi)
			sinphi = math.sin(phi)
			
			circlex = r2 + r1*costheta
			circley = r1*sintheta
			
			
			x = circlex * cosphi
			y = circley
			z = (circlex * sinphi)
		
			x = x
			y = y*cosa + z * -sina
			z = (y* sina) + (z* cosa)
			z += k2
	
			"""
			x = circlex *(cosb * cosphi + sina*sinb*sinphi) - (circley*cosa*sinb)
			y = circlex *(sinb* cosphi - cosb*sina*sinphi) + (circley*cosa*cosb)
			z = k2 + cosa*circlex*sinphi+ circley*sina
			"""
			ooz = 1/z
	
			xp = int(screen_width/2 + k1*ooz*x)
			yp = int(screen_height/2 - k1*ooz*y)
			screen.plot(xp,yp,"*")
			
	screen.render()
	screen.clearScreen()
			
a = 1.0
b = 7.0
while(True):
 donut(a,b)
 a += 0.1
 b += 0.0
 
 
 """
 (x,y,z) *  cosphi 0 sinphi
             0       1     0   
             sinphi 0    cosphi
          
   
  x = x*cosTheta + z *sinTheta
  y = y
  z = x*sinTheta + z*costheta
  
  (x,y,z)  *  1         0            0
              0      cosA         -sinA
              0        sinA        cosA
              
   x = x
   y = y*cosA + z * sinA
   z = y * - sinA + z * cosA
 
 
 """
		