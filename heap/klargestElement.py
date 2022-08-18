from heap import Heap



def klargestElement(arr,k):
	
	heap = Heap()
	
	for value in arr:
		heap.push(value)
		if heap.size() > k:
			heap.pop()
			
	ans = []
	while not heap.empty():
		ans.append(heap.pop())
	return ans
	
	
print(klargestElement([7,10,4,3,20,15],3))