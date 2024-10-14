from collections import deque
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**5)

N = int(input())
edge = [[] for _ in range(N+1)]
for index in range(N-1):
  data = input().split()
  edge[int(data[0])].append(int(data[1]))
  edge[int(data[1])].append(int(data[0]))

def bfs(edge,start,q=None,visited=None,length=0):
  visited = set()
  q = deque()
  length = 0
  total = 0
  q.append(start)
  visited.add(start)
  while True:
    if not q:
      break

    cur_length = len(q)

    for index in range(cur_length):
      cur_node = q.popleft()
      flag = True
      for node in edge[cur_node]:
        if node not in visited:
          visited.add(node)
          q.append(node)
          flag = False
      if flag:
        total += length

    length += 1
  return total
answer = bfs(edge,1)
print("Yes" if answer % 2 == 1 else "No")