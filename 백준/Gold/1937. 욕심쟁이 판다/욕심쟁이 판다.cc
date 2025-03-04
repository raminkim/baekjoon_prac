#include <iostream>
#include <algorithm>
#define endl "\n"

using namespace std;

int n;
int cnt = 0, ans = 0;

int arr[501][501] = {0};
int dp[501][501] = {0};

int movX[4] = {-1, 1, 0, 0};
int movY[4] = {0, 0, -1, 1};

int dfs(int a, int b) {
    if (dp[a][b] > 0) return dp[a][b];
    dp[a][b] = 1;

    for (int i = 0; i < 4; i++) {
        int x = a + movX[i];
        int y = b + movY[i];
        
        if (x < 0 || x >= n || y < 0 || y >= n) continue;
        if (arr[a][b] >= arr[x][y]) continue;

        dp[a][b] = max(dp[a][b], dfs(x, y) + 1);
    }
    return dp[a][b];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans = max(dfs(i, j), ans);
        }
    }

    cout << ans;
}