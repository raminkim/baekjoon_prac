#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define endl "\n"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;

        vector<vector<int>> adj(n+1);
        vector<int> indegree(n+1, 0);
        vector<int> time(n+1, 0);
        vector<int> dp(n+1, 0);

        queue<int> q;

        for (int j = 1; j <= n; j++) {
            cin >> time[j];
        }   

        for (int j = 0; j < k; j++) {
            int x, y;
            cin >> x >> y;
            
            adj[x].push_back(y);
            indegree[y]++;
        }

        for (int j = 1; j <= n; j++) {
            if (indegree[j] == 0) {
                q.push(j);
                dp[j] = time[j];
            }
        }

        int w;
        cin >> w;

        while (!q.empty()) {
            int prev = q.front();
            q.pop();
            
            for (int next : adj[prev]) {
                indegree[next]--;
                dp[next] = max(dp[next], dp[prev] + time[next]);

                if (!indegree[next]) {
                    q.push(next);
                }
            }
        }

        cout << dp[w] << endl;
    }
}