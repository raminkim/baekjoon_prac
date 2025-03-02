#include <iostream>

using namespace std;

int n;
long long dp[101][10] = {0};
long long ans = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    // n=1일 때 {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}

    for (int i = 1; i <= 9; i++) {
        dp[1][i] = 1;
    }
    
    // n=2일 때 {1, 2, 2, 2, 2, 2, 2, 2, 2, 1}
    // n=3일 때 {1, 3, 3, 5, 5, 3, 4, 4, 3, 1}
    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i-1][1];
        for (int j = 1; j <= 8; j++) {
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000;
        }
        dp[i][9] = dp[i-1][8];
    }

    for (int i = 0; i <= 9; i++) {
        ans += dp[n][i];
    }

    cout << ans % 1000000000;
}