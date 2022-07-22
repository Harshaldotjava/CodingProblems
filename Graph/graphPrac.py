def createGraph(*nodes):
	graph = {}
	for node in nodes:
		graph[node] = []
	

	return graph

def addEdge(graph,src,nodes):
	graph[src] = nodes
	

def dfs(graph,starting,visited):
	visited.add(starting)
	print(starting)
	
	for neighbour in graph[starting]:
		if(neighbour not in visited):
			dfs(graph,neighbour,visited)
			

			
	
nodes = [1,2,3,4,5,6,7,8,9,10]

graph = createGraph(*nodes)
addEdge(graph,1,[4,2])
addEdge(graph,2,[1,3,7,5,8])
addEdge(graph,3,[4,2,10,9])
addEdge(graph,4,[1,3])
addEdge(graph,5,[6,2,7,8])
addEdge(graph,6,[5])
addEdge(graph,7,[5,8,2])
addEdge(graph,8,[5,2,7])
addEdge(graph,9,[3])
addEdge(graph,10,[3])


visited = set()

dfs(graph,1,visited)
	
	
	
