import sys
global n, m

lst = []

def dfs(num):
    # 리스트의 개수가 m과 같아지면 return
    if len(lst) == m:
        print(" ".join(map(str, lst)))
        return
    for i in range(num+1, n+1):
        lst.append(i)
        dfs(i)
        lst.pop()

if __name__ == "__main__":
    n, m = map(int, sys.stdin.readline().split())
    dfs(0)