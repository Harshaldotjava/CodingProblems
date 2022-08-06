from linklist import Node

def reverseList(list):
	if(list.next == None or list == None):
		return list
		
		
	head = reverseList(list.next)
	list.next.next = list
	list.next = None
	
	return head
	
		
			
def display(head):
	temp = head
	while temp:
		print(temp.val)
		temp = temp.next
	return
	
	
head = Node(20)
head.next = Node(40)
head.next.next = Node(50)

head = reverseList(head)
display(head)