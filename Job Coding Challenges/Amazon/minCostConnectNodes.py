from collections import defaultdict 
import heapq

def minCostConnectNodes(N, connections):                    
    if (connections is None or N == 0):
        return 0

    g = defaultdict(list)

    for e in connections:
        g[e[0]].append((e[2], e[1]))
        g[e[1]].append((e[2], e[0]))

    cost = 0
    priQ = [(0,1)]
    heapq.heapify(priQ)
    checkedNodes = set()

    while priQ:
        minCost, node = heapq.heappop(priQ)
        if node not in checkedNodes:
            checkedNodes.add(node)
            cost += minCost
            for c, g_node in g[node]:
                if g_node not in checkedNodes:
                    heapq.heappush(priQ, (c, g_node))
    
    if (len(checkedNodes) != N or (not connections)):
        return -1

    return cost