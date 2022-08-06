class Node:
	
	def __init__(self,val):
		self.val = val
		self.next = None
		

class Linklist:
	
	def __init__(self,val):
		self.head = Node(val)
		
	def insert(self,val):
		
		temp = self.head
		while(temp.next != None):
			temp = temp.next
	
		temp.next = Node(val)
		
			
	def display(self):
		temp = self.head
		while temp != None:
			print(temp.val)
			temp = temp.next
			
			


