import sys
global n, m

numbers = []
lst = []
visited = []

def dfs():
    before = 0
    if len(lst) == m:
        print(*lst)
        return
    for i in range(n):
        if before != numbers[i] and not visited[i]:
            lst.append(numbers[i]); visited[i] = True
            before = numbers[i]
            dfs()
            lst.pop(); visited[i] = False


if __name__ == "__main__":
    n, m = map(int, sys.stdin.readline().split())
    numbers = sorted(list(map(int, sys.stdin.readline().split())))
    visited = [False for i in range(n)]
    dfs()