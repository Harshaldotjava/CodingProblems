from node import Node

class Linklist:
	
	def __init__(self,*values):
		self.head = Node(None)
		temp = self.head
		for val in values:
			temp.next = Node(val)
			temp = temp.next
		
		self.head = self.head.next
		
	
		
	def __repr__(self):	
		temp = self.head
		values = []
		while temp:
			values.append(str(temp.val))
			temp = temp.next
	
		return "[" + "-> ".join(values) + "]"
	
	def __getitem__(self,index):
		temp = self.head
		for i in range(index):
			temp = temp.next
			
		return temp.val
		
	def __list__(self):
		print("hii")
		

if __name__ == "__main__":
	
	l = Linklist(1,2,3,5,1,5,7,5,4)
	print(l[5])