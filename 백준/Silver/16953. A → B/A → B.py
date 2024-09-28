import sys

global a, b
result = []

def dfs(n, cnt):
    # n의 값이 b보다 커졌을 경우는 더 이상 진행 X
    if n > b:
        return
    # n = b인 경우, result 리스트에 추가하기
    if n == b:
        result.append(cnt+1)
        return
    dfs(2*n, cnt+1) # 2를 곱하기
    dfs(n*10+1, cnt+1) # 1을 수의 가장 오른쪽에 추가하기

if __name__ == '__main__':
    a, b = map(int, sys.stdin.readline().split())
    dfs(a, 0)
    if result:
        print(min(result)) # 만들 수 있다면, result 리스트에서 최솟값을 출력
    else:
        print(-1) # 만들 수 없는 경우