from heap import MinHeap



def klargestElement(arr,k):
	
	heap = MinHeap()
	
	for value in arr:
		heap.push(value)
		if heap.size() > k:
			heap.pop()
			
	ans = []
	while not heap.empty():
		ans.append(heap.pop())
	return ans
	
	
print(klargestElement([69,7,25,10,4,3,9,100,20,15],3))