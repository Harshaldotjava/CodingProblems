def lca(node,p,q):
	if not node:
		return None
		
	if p.val < node.val and q.val < node.val:
		return lca(node.left,p,q)
	if p.val > node.val and q.val > node.val:
		return lca(node.right,p,q)
		
	return node
	
	
