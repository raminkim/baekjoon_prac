#include <iostream>
#include <vector>
#include <queue>

#define endl "\n"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> indegree(n+1, 0);
    vector<vector<int>> adj(n+1);

    queue<int> q;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        indegree[b]++;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << " ";

        for (int next : adj[cur]) {
            indegree[next]--;
            
            if (indegree[next] == 0 ) {
                q.push(next);
            }
        }
    }
}