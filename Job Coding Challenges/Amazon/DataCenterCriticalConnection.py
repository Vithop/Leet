
def BFS(graph, n):
	visited = [False] * len(graph)
	queue = []

	queue.append(n)
	visited[n] = True
	while queue:
		n = queue.pop(0)
		for i in graph[n]:
			if visited[i] == False:
				queue.append(i)
				visited[i] = True
	return visited


def findCriticalConn(serversNum, connectionsNum, connections):
	graph = defaultdict(list)
	for i in range(connectionsNum):
		graph[connections[i][0]].append(connections[i][1])
		graph[connections[i][1]].append(connections[i][0])

	for edge in connections:
		graph[edge[0]].remove(edge[1])
		graph[edge[1]].remove(edge[0])


