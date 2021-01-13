from collections import deque  

# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []

class Solution:
    def printGraph(self, node):
        visited = [False for i in range(100)]
        deq = deque()
        deq.append(node)
        while deq:
            cur = deq.popleft()
            if visited[cur.val] == False:
                nodep = str(cur.val) + " "
                visited[cur.val] = True
                for i in cur.neighbors:
                    nodep += str(i.val) + " "
                    deq.append(i)
                print(nodep)

    def cloneGraph(self, node: 'Node') -> 'Node':
        if node == None:
            return node

        adjc = [Node(i) for i in range(101)]
        visited = [False for i in range(101)]

        deq = deque()
        deq.append(node)
        while deq:
            cur = deq.popleft()
            id = cur.val
            if visited[cur.val] == False:
                visited[cur.val] = True
                for i in cur.neighbors:
                    if visited[i.val] == False:
                        deq.append(i)
                        adjc[id].neighbors.append(adjc[i.val])
                        adjc[i.val].neighbors.append(adjc[cur.val])
        
        return adjc[node.val]

test = Solution()
root = Node(1, [Node(2), Node(3, [Node(4), Node(5)])])
rootc = test.cloneGraph(root)
test.printGraph(rootc)