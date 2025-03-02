#include <iostream>
#define endl "\n"

using namespace std;

int n, m, k;
int dp[301][301] = {0};


int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int num;
            cin >> num;
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + num;
        }
    }

    cin >> k;
    while (k--) {
        int i, j, x, y;
        cin >> i >> j >> x >> y;
        cout << dp[x][y] - dp[i-1][y] - dp[x][j-1] + dp[i-1][j-1] << endl;
    }
}