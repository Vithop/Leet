from collections import defaultdict 
import heapq

from collections import defaultdict 
import heapq

def minCostToRepairEdges(n, edges, edgesToRepair):
    if (edges is None and edgesToRepair is None):
        return 0
    
    g = defaultdict(list)
    edgesInGraph = set()

    for e in edgesToRepair:
        g[e[0]].append((e[2], e[1]))
        g[e[1]].append((e[2], e[0]))
        edgesInGraph.add((e[0], e[1]))
        edgesInGraph.add((e[1], e[0]))

    for e in edges:
        if tuple(e) not in edgesInGraph:
            g[e[0]].append((0, e[1]))
            g[e[1]].append((0, e[0]))

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
    
    if (len(checkedNodes) != n or (not edges and not edgesToRepair)):
        return -1

    return cost



ans = minCostToRepairEdges(6, [], [[1, 4, 100], [2, 4, 10], [2, 3, 7], [2, 5, 15], [2, 1, 17], [5, 3, 1]])
print('test results 1')
print(ans)

print("nxt Test")
ans =  minCostToRepairEdges(1, [], [])
print('test results 2')
print(ans)

