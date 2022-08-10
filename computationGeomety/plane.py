from rotation import rotateY2D
from matrix import Matrix
import time



def render_screen(x,y):
	print(x,y)
	plane[y][x] = "@"
	print('\x1b[H')	
	for i in range(screen_height-1,-1,-1):
		for j in range(screen_width):
			print(plane[i][j],end= " ")
		print()


	
screen_height = 70
screen_width = 70
plane = [[" "]*screen_width for i in range(screen_height)]

ox = screen_width//2
oy = screen_height//2

x = ox + 10
y = oy

plane[y][x] = "@"
plane[ox][oy] = "@"


print("-------------------")

while True:
  for i in range(360):
  	new_point = rotateY2D(x,y,i,ox,oy)

  	render_screen(new_point[0][0],new_point[1][0])
  





