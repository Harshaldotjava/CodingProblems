from linklist import Linklist



def merge(list1,list2):
	if(list1 == None):
		return list2
	if(list2 == None):
		return list1
	
	head = None
	if(list1.val < list2.
	val):
		head = list1
		head.next = merge(list1.next,list2)
	else:
		head = list2
		head.next = merge(list1,list2.next)
		
	return head
	


def dsplayList(head):
	temp = head 
	while temp:
		print(temp.val)
		temp = temp.next
		
	

listA = Linklist(1)	
listA.insert(2)
listA.insert(4)

listB = Linklist(1)
listB.insert(3)
listB.insert(4)


result = merge(listA.head,listB.head)
dsplayList(result)


	
	
