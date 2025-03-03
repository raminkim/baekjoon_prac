#include <iostream>
#include <algorithm>
#define endl "\n"

using namespace std;

int n;
// 상담을 완료하는데 걸리는 기간 T
int T[16] = {0};
// 상담을 했을 때 받을 수 있는 금액 P
int P[16] = {0};
int dp[16] = {0};
int ans = 0;


int main() {
    ios:: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> T[i];
        cin >> P[i];
    }

    dp[1] = (1 + T[1] - 1 <= n) ? P[1] : 0;
    ans = dp[1];

    for (int i = 2; i <= n; i++) {
        int num = (i + T[i] - 1 <= n) ? P[i] : 0;
        dp[i] = num;
        for (int j = 1; j < i; j++) {
            if (j + T[j] - 1 < i) {
                dp[i] = max(dp[j] + num, dp[i]);
            }
        }
        ans = (dp[i] > ans) ? dp[i] : ans;
    }

    cout << ans;
}