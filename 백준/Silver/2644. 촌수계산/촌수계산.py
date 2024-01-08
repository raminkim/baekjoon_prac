from collections import deque
def bfs():
    q = deque()
    q.append((start, 0))
    while q:
        v, cnt = q.popleft()
        if v == end: print(cnt); break # 관계가 있는 경우 촌수 print!
        if v not in visited:
            visited.add(v)
            for i in graph[v]:
                if i not in visited:
                    q.append((i, cnt+1))
    else:
        print(-1) # 아예 관계 없을 경우 촌수 계산이 불가능!!

n = int(input()) # 전체 사람의 수
graph = dict(); visited = set()
for i in range(1, n+1): graph[i] = []
start, end = map(int, input().split()) # 촌수 계산해야하는 번호.
m = int(input()) # 관계의 개수.
for i in range(m):
    a, b = map(int, input().split()) # 이어진 두 사람 번호들.
    graph[a].append(b); graph[b].append(a) # 그래프 update.
bfs()