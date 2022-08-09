from node import Node
val = Node(10)
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
	
	
		
		
list = Linklist(1,2,3,5,1,5,7,5,4)

print(list)