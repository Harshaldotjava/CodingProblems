class Heap:
	
	def __init__(self):
		self.heap = []
	
	
	def __heapify(cls,i):

		largest = i
		left = ((i+1)*2)-1
		right = (i+1)*2
		heap_size = len(cls.heap)
		

		if(left <  heap_size and cls.heap[left] > cls.heap[largest]):
			largest = left
		if(right < heap_size and cls.heap[right] > cls.heap[largest]):
			largest = right
		
		if i != largest:
			cls.heap[i],cls.heap[largest] = cls.heap[largest],cls.heap[i]
			
		
	def push(self,val):
		self.heap.append(val)
		for i in range(len(self.heap)-1,-1,-1):
			self.__heapify(i)
			
	def pop(self):
		val = self.heap.pop(0)
		self.__heapify(0)
		return val
	
	def print(self):
		print(self.heap)
			
	def empty(self):
		return len(self.heap) == 0
	
	def top(self):
		if not self.empty():
			return self.heap[0]
		return None
		
	def size(self):
		return len(self.heap)			

class MinHeap(Heap):
	def __heapify(cls,i):
		
		largest = i
		left = ((i+1)*2)-1
		right = (i+1)*2
		heap_size = len(cls.heap)
		

		if(left <  heap_size and cls.heap[left] < cls.heap[largest]):
			largest = left
		if(right < heap_size and cls.heap[right] < cls.heap[largest]):
			largest = right
		
		if i != largest:
			cls.heap[i],cls.heap[largest] = cls.heap[largest],cls.heap[i]
			
	def push(self,val):
		self.heap.append(val)
		for i in range(len(self.heap)-1,-1,-1):
			self.__heapify(i)

	
	def pop(self):
		val = self.heap.pop(0)
		self.__heapify(0)
		return val
		
		




		