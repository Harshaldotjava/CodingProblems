def heapify(arr,i):
	largest = i
	left = ((i+1)*2)-1
	right = ((i+1)*2)
	
	if(left < len(arr) and arr[left] > arr[largest]):
		largest = left
	if(right < len(arr) and arr[right] > arr[largest]):
		largest = right
		
	if(i != largest):
		temp = arr[largest]
		arr[largest] = arr[i]
		arr[i] = temp
		heapify(arr,largest)
		
		

def stoneGame(stones):
	for i in range(len(stones),-1,-1):
		heapify(stones,i)
	print(stones)
	while len(stones) > 1:
		x = 1
		y = 0
		
		if(stones[x] == stones[y]):
			stones.pop(x)
			stones.pop(y)
		else:
			stones[y] -= stones[x]
			stones.pop(x)
			heapify(stones,y)
			
	return  stones[0]
	
	
print(stoneGame([1]))
