#include <iostream>

using namespace std;

int n, k; // 물품의 수 N, 버틸 수 있는 무게 K

int W[101] = {0,};
int V[101] = {0,};
int dp[101][100001];

void func() {
    for (int j = 1; j <= k; j++) { // 담을 수 있는 무게
        for (int i = 1; i <= n; i++) { // 아이템 수
            if (W[i] > j) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-W[i]] + V[i]);
            }
        }
    }
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> W[i] >> V[i];
    
    // 배열 초기화
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = 0;
        }
    }

    func();
    cout << dp[n][k];
    return 0;
}