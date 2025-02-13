#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph(1001);
bool visited[1001] = {false};
int ans = 0;

void dfs(int v) {
    if (visited[v]) return;

    // cout << "v = " << v << endl;

    visited[v] = true;
    for (int num : graph[v]) {
        if (!visited[num])
            dfs(num);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    while(m--) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> lst;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            lst.push_back(i);
            dfs(i);
            
            // cout << i << "->" << ans << endl;
            if (lst.size())
                ans++;
            lst.clear();
        }
    }
    cout << ans;
}