class Node:
	
	def __init__(self,data):
		self.data = data
		self.left = None
		self.right = None
		





def add(root,data):
	if root == None:
		root = Node(data)
		return root
	
	if root.data > data:
		root.left = add(root.left,data)
	if root.data < data:
		root.right = add(root.right,data)
	
	return root
	
	
def treePrint(root):
	if(root != None):
		treePrint(root.left)
		print(root.data,end=" ")
		treePrint(root.right)

	

def sym(rootLeft,rootRight):
	if(rootLeft.data != rootRight.data):
		return False;
	if(rootLeft == None and rootRight == None):
		return True
	return sym(rootLeft.left,rootRight.right) and sym(rootLeft.right,rootRight.left)
		

root = None
