import sys
global n, m

numbers = []
lst = []

def backtracking(d):
    # d가 m과 같아지면 return
    if d == m:
        print(" ".join(map(str, lst)))
        return
    for i in range(n):
        if numbers[i] in lst: continue;
        lst.append(numbers[i])
        backtracking(d+1)
        lst.pop()

if __name__ == "__main__":
    n, m = map(int, sys.stdin.readline().split())
    numbers = sorted(list(map(int, sys.stdin.readline().split())))
    backtracking(0)
