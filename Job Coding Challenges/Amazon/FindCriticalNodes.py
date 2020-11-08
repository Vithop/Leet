from collections import defaultdict 

def BFS(graph, n, blocked_n):
	visited = [False] * (len(graph))
	queue = []

	queue.append(n)
	visited[n-1] = True
	while queue:
		n = queue.pop(0)
		# print("parent", n)
		for i in graph[n]:
			if i==blocked_n:
				continue
			# print ("child",i)
			if visited[i-1] == False:
				queue.append(i)
				visited[i-1] = True
				
	return visited

def findCriticalNodes(nodeNum, edges):
	graph = defaultdict(list)
	criticalNodes = []
	print (edges)
	print (nodeNum)

	if nodeNum < 2:
		return [1]

	for edge in edges:
		graph[edge[0]].append(edge[1])
		graph[edge[1]].append(edge[0])

	for i in range(nodeNum):
		visited = BFS(graph, graph[i][0], i)
		num_visited = visited.count(True)
		# print("Removed ", i, " Num Visited ", num_visited)
		if num_visited < nodeNum-1:
			criticalNodes.append(i)

	return criticalNodes

