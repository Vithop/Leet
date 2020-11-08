from collections import defaultdict 

def BFS(graph, n):
	visited = [False] * (len(graph))
	queue = []

	queue.append(n)
	visited[n-1] = True
	while queue:
		n = queue.pop(0)
		# print("parent", n)
		for i in graph[n]:
			# print ("child",i)
			if visited[i-1] == False:
				queue.append(i)
				visited[i-1] = True
				
	return visited


def findCriticalConn(serversNum, connectionsNum, connections):
	graph = defaultdict(list)
	criticalConn = []
	for i in range(connectionsNum):
		graph[connections[i][0]].append(connections[i][1])
		graph[connections[i][1]].append(connections[i][0])

	for edge in connections:
		graph[edge[0]].remove(edge[1])
		graph[edge[1]].remove(edge[0])
		visited = BFS(graph, edge[0])
		if visited[edge[1]-1] == False:
			criticalConn.append(edge)
		graph[edge[0]].append(edge[1])
		graph[edge[1]].append(edge[0])

	return criticalConn

print(findCriticalConn(4, 4, [[1, 2], [1, 3], [3, 2], [3, 4]]))



