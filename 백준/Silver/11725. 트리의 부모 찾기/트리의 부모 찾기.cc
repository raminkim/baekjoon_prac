#include <iostream>
#include <vector>
#define MAX 100001

using namespace std;

int n;
vector<int> vec[MAX];
bool visited[MAX];
int ans[MAX];

void dfs(int v) {
    visited[v] = 1;
    for (int i : vec[v]) {
        if (!visited[i]) {
            ans[i] = v;
            dfs(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 2; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    dfs(1);

    for (int i = 2; i <= n; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}