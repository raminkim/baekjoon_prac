#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
set<int> s;
vector<int> vec[501];
int ans = 0;

void solve() {
    for (int i = n-1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            vec[i][j] += max(vec[i+1][j], vec[i+1][j+1]);
            // cout << i << " " << j << " -> " << vec[i][j] << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            int m;
            cin >> m;
            vec[i].push_back(m);
        }
    }

    if (n > 1)  solve();

    cout << vec[1][0] << "\n";

    return 0;
}