#include <iostream>

using namespace std;

int n;
int ans = 0;

long dp[1001][10];

int main() {
    cin >> n;

    for (int i = 0; i < 10; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i-1][0];
        for (int j = 1; j < 10; j++) {
            for (int k = 0; k <= j; k++) {
                dp[i][j] += (dp[i-1][k] % 10007);
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        ans += dp[n][i];
    }

    cout << ans % 10007;
}