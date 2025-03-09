#include <iostream>
#include <algorithm>
#include <string.h>
#define endl "\n"

using namespace std;

int n;

long long arr[33][33] = {0};
long long dp[3][33][33];
long long ans = 0;

bool check(int x, int y) {
    return (x >= 1 && x <= n && y >= 1 && y <= n);
}

long long dfs(int x, int y, int d) {
    if (x == n && y == n) return 1;
    // already update
    if (dp[d][x][y] != -1) return dp[d][x][y];

    dp[d][x][y] = 0;
    if (d == 0) {
        if (check(x, y+1) && !arr[x][y+1]) dp[d][x][y] += dfs(x, y+1, 0);
        if (check(x+1, y+1) && !arr[x+1][y] && !arr[x+1][y+1] && !arr[x][y+1]) 
            dp[d][x][y] += dfs(x+1, y+1, 1);
        return dp[d][x][y];
    } else if (d == 1) {
        if (check(x, y+1) && !arr[x][y+1]) dp[d][x][y] += dfs(x, y+1, 0);
        if (check(x+1, y+1) && !arr[x+1][y] && !arr[x+1][y+1] && !arr[x][y+1]) 
            dp[d][x][y] += dfs(x+1, y+1, 1);
        if (check(x+1, y) && !arr[x+1][y]) dp[d][x][y] += dfs(x+1, y, 2);
        return dp[d][x][y];
    } else if (d == 2) {
        if (check(x+1, y+1) && !arr[x+1][y] && !arr[x+1][y+1] && !arr[x][y+1]) 
            dp[d][x][y] += dfs(x+1, y+1, 1);
        if (check(x+1, y) && !arr[x+1][y]) dp[d][x][y] += dfs(x+1, y, 2);
        return dp[d][x][y];
    }
    
    return dp[d][x][y];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    // 가로: 0
    ans += dfs(1, 2, 0);

    cout << ans;
}