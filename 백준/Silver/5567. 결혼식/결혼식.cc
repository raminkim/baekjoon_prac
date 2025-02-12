#include <iostream>
#include <queue>
#include <set>
#include <tuple>
using namespace std;

int graph[501][501];
bool visited[501] = {false};

int n; // 상근이의 동기의 수 n
int m; // 리스트의 길이 m
int ans = 0; // 결혼시 초대하는 동기 수

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    queue<tuple<int, int>> q;
    q.push(make_tuple(1, 0));
    visited[1] = true;

    while(!q.empty()) {
        int v, deep;
        tie(v, deep) = q.front();
        q.pop();

        // cout << "v => " << v << " " << deep << endl;
        
        if (deep >= 2) continue;

        for (int i = 1; i <= n; i++) {
            if (!visited[i] && graph[v][i]) {
                // cout << "i => " << i << " " << endl;
                visited[i] = true;
                q.push(make_tuple(i, deep+1));
                ans++;
            }
        }
    }

    cout << ans;
}