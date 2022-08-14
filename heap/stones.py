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
		
def heapi(arr):
	for i in range(len(arr),-1,-1):
		heapify(arr,i)		

def stoneGame(stones):	
	heapi(stones)
	while len(stones) > 1:
		y = stones.pop(0)
		heapi(stones)
		x = stones.pop(0)
		heapi(stones)
		if x != y:
			stones.append(y-x)
			heapi(stones)
	if len(stones) == 0:
		return 0
	return stones[0]
	
	
print(stoneGame([2,7,4,1,8,1]))
	



	
