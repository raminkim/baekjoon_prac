#include <iostream>
#include <algorithm>
#define endl "\n"

using namespace std;

int n, m;
int ans = 0;

int arr[1001][1001] = {0};
bool visited[1001][1001] = {false};

void solve(int x, int y) {
    if (x < 0 || y < 0) return;
    arr[x][y] = min({arr[x][y-1], arr[x-1][y-1], arr[x-1][y]}) + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);

    cin >> n >> m;
    string num;

    for (int i = 0; i < n; i++) {
        cin >> num;
        for (int j = 0; j < m; j++) {
            arr[i][j] = num[j] - '0';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j]) {
                solve(i, j);
                ans = max(arr[i][j], ans);
            }
        }
    }

    cout << ans * ans;
}