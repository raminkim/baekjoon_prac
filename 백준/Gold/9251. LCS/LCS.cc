#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"

using namespace std;

string a, b;
int dp[1001][1001] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a;
    cin >> b;

    int n = static_cast<int>(a.length());
    int m = static_cast<int>(b.length());

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // a의 한글자와 b를 순차적으로 비교해가면서, 
            // 맞으면 dp[i-1][j-1] + 1, 맞지 않으면 dp[i-1][j] or dp[i][j-1] 중 큰 값을 가져온다.
            if (a[i-1] == b[j-1]) dp[i][j]  = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << dp[n][m];
}