import sys

if __name__ == '__main__':
    n = int(sys.stdin.readline())
    lst = []
    dp = [[0 for _ in range(3)] for _ in range(n)]

    for i in range(n):
        lst.append(list(map(int, sys.stdin.readline().split())))
    dp[0] = lst[0] # dp의 첫 줄을 맨 처음 집으로 세팅

    for i in range(n):
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + lst[i][0] # 이전 집의 최솟값 + dp[i][0]
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + lst[i][1] # 이전 집의 최솟값 + dp[i][1]
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + lst[i][2] # 이전 집의 최솟값 + dp[i][2]

    print(min(dp[n-1])) # 결과 출력