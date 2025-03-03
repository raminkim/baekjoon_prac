#include <iostream>
#include <algorithm>
#define endl "\n"

using namespace std;

int n;
int dp[100001] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    
    for (int i = 1; i * i <= n; i++) {
        dp[i*i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        if (dp[i] == 1) continue;
        dp[i] = i;
        for (int j = i-1; j > i/2; j--) {
            int num = dp[j] + dp[i-j];
            dp[i] = (num < dp[i]) ? num : dp[i];
        }
    }

    cout << dp[n];
}