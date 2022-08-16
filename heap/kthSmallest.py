from heap import Heap


def kthSmallest(array,k):
	
	heap = Heap()
	
	for val in array:
		heap.push(val)
		if heap.size() > k:
			heap.pop()
		
	return heap.top()
	
	


print(kthSmallest([7,10,4,3,20,15],3))