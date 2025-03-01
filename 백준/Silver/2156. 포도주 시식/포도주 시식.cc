#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[10001] = {0,};
int dp[10001] = {0,};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    dp[0] = 0;
    dp[1] = arr[1];
    // 두 번째는 무조건 첫 번째 잔 + 두 번째 잔을 마신 결과
    dp[2] = arr[1] + arr[2];

    for (int i = 3; i <= n; i++) {
        /* 
        연속된 3개의 잔을 마실 수 없다. (3번째부터는 결정해야 할 필요성이 존재)
        1. (i-3), (i-1)번째의 잔을 마시고, 현재 i번째의 잔을 마신다.
        2. (i-2)번째의 잔을 마시고, 현재 i번째의 잔을 마신다.
        3. 현재 i번째의 잔을 마시지 않고, 이전 i-1의 값을 그대로 취한다.
        */
       dp[i] = max({dp[i-3] + arr[i-1] + arr[i], dp[i-2] + arr[i], dp[i-1]});
    }

    cout << dp[n];
}