from collections import deque

class graph:
	
	def addEdge(self,*edges):

		for edge in edges:
			src,dst = edge
			self.graph[src].append(dst)
				
	def __init__(self, *nodes):
		self.graph = {}
		self.node = len(nodes)
		
		for node in nodes:
			self.graph[node] = []
	
	def printadj(self):
		for node,neighbours in self.graph.items():
			print(node,"->;",neighbours)
			
	def BFS(self,s):
			queue = deque()
			visited = {}
			for key in self.graph.keys():
				visited[key] = False
				
			queue.append(s)
			visited[s] = True
			
			while(len(queue)):
				node = queue.popleft()
				print(node,end="  ")
				for neighbour in self.graph[node]:
					if(not visited[neighbour]):
						queue.append(neighbour)
						visited[neighbour] = True
			

nodes = {2,4,5,6,9
}
edges = [(2,6),(2,5),(2,4),
				(4,2),(4,9),(5,6),(5,2),
				(6,5),(6,2),
				(9,4)]
			
graph = graph(*nodes)
graph.addEdge(*edges)

graph.BFS(9)

