#include <iostream>
#define endl "\n"
using namespace std;

int n;
int ans = 0;

int arr[16];

bool check(int x, int y) {
    for (int i = 0; i < x; i++) {
        if (arr[i] == y || abs(i - x) == abs(arr[i] - y)) {
            return false; // 같은 열 or 대각선에 놓이면 X (재귀하는 위치가 같은 행은 아님)
        }
    }
    return true;
}

void backtracking(int m) {
    if (m == n) {
        ans++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (check(m, i)) {
            arr[m] = i;
            backtracking(m+1);
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    backtracking(0);

    cout << ans;
    
    return 0;
}