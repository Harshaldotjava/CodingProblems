
from rotation import rotate2D
from matrix import Matrix
import time
import math

class Screen:
	
	def clearScreen(self):
		self.screen =  [[" "]* self.width for i in range(self.height)]
	
	def __init__(self,height,width):
		self.height = height
		self.width = width
		self.screen = [[" "]*width for i in range(height)]
		
	def render(self):
		print('\x1b[H')	
		for i in range(self.height-1,-1,-1):
			for j in range(self.width):
				print(self.screen[i][j],end=" ")
			print()
				
	def plot(self,x,y,sym):
		self.screen[y][x] = sym


if __name__ == "__main__":
	screen_height = 70
	screen_width = 70
	ox = screen_width//2
	oy = screen_height//2
	
	
	screen = Screen(screen_height,screen_width)
	
	
	#n = int(input("how many rounds? "))
	print(math.pi * 2)
	count = 0
	while count != 1:
	  i = 0
	  sec = 0
	  while i < 2 * math.pi:
	  	i += 0.1
	  	screen.clearScreen()
	  	for line in range(30):
	  		x = ox
	  		y = ox + line
	  		new_point = rotate2D(x,y,i,ox,oy)
	  		screen.plot(new_point.x,new_point.y,"@")
	  		screen.plot(ox,oy,"o")
	  
	  	screen.render()
	 
	  count += 1
	  print(count)
	  
	
	
	
	
	