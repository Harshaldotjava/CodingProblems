#pylint:disable=W0621
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
	
	def depth(self,s,visited):
    print(s,end=" ")
    visited.add(s)
    for neighbour in self.graph[s]:
      if neighbour not in visited:
        self.depth(neighbour,visited)
				    

	def DFS(self,s):
			visited = set()
			self.depth(s,visited)
			
			
	
nodes = {2,4,5,6,9}

edges = [(2,6),(2,5),(2,4),
				(4,2),(4,9),(5,6),(5,2),
				(6,5),(6,2),
				(9,4)]
			
graph = graph(*nodes)
graph.addEdge(*edges)
graph.DFS(9)

