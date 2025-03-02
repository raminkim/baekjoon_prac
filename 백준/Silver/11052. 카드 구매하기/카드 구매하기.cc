#include <iostream>
#include <algorithm>

using namespace std;

int n;

int dp[1001] = {0};
int arr[1001] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // 구매하려고 하는 카드의 수 N
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int m;
        cin >> m;
        dp[i] = m;
        arr[i] = m;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] = max(dp[j] + arr[i-j], dp[i]);
        }
    }

    cout << dp[n];
}