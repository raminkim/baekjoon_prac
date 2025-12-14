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

    vector<vector<int>> adj(1001);
    vector<int> indegree(1001, 0);

    queue<int> q;
    vector<int> result;

    for (int i = 0; i < m; i++) {
        int seq;
        cin >> seq;

        int prev = 0;
        for (int j = 0; j < seq; j++) {
            int num;
            cin >> num;

            if (prev == 0) {
                prev = num;
                continue;
            }

            adj[prev].push_back(num);
            indegree[num]++;
            prev = num;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int prev = q.front();
        q.pop();

        for (int next : adj[prev]) {
            indegree[next]--;

            if (indegree[next] == 0) {
                q.push(next);
            }
        }

        result.push_back(prev);
    }

    if (result.size() == n) {
        for (int r : result) {
            cout << r << endl;
        }
    } else {
        cout << 0 << endl;
    }
}