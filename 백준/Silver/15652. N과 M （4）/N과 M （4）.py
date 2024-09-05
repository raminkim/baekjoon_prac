import sys
global n, m

lst = []

def dfs(num):
    # 리스트의 개수가 m과 같아지면 return
    if len(lst) == m:
        print(" ".join(map(str, lst)))
        return
    
    for i in range(num, n+1):
        lst.append(i)
        dfs(i)
        lst.pop()

if __name__ == "__main__":
    n, m = map(int, sys.stdin.readline().split())
    # 무조건 1부터 시작하므로 1을 start 인수로 넣음.
    dfs(1)
