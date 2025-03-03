#include <iostream>
#include <algorithm>
#define endl "\n"

using namespace std;

int n, m;
int arr[1000][1000] = {0};
int dp[1000][1000] = {0};

int main() {
    ios:: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int X[3] = {1, 0, 1};
    int Y[3] = {0, 1, 1};

    dp[0][0] = arr[0][0];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 3; k++) {
                int x = i + X[k];
                int y = j + Y[k];
                if (x >= n || y >= m) continue;
                dp[x][y] = max(dp[i][j] + arr[x][y], dp[x][y]);
            }
        }
    }

    cout << dp[n-1][m-1] << endl;
}