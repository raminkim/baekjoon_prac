#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 987654321

using namespace std;

vector<int> board[20001];

int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        board[a].push_back(b);
        board[b].push_back(a);
    }

    /* BFS 시작 */
    queue<int> q;
    vector<int> dist(n+1, INF);

    q.push(1);
    dist[1] = 0;
    while(!q.empty()) {
        int num = q.front();
        q.pop();
        for (int v : board[num]) {
            if (dist[v] > dist[num] + 1) {
                dist[v] = dist[num] + 1;
                q.push(v);
            }
        }
    }
    /* BFS 함수 끝 */
    
    // 숨어야 하는 헛간 번호 구하기(최대로 먼 곳 구하기)
    int dis = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] != INF && dist[i] > dis)
            dis = dist[i];
    }
    
    // 그 헛간 번호와 같은 거리를 갖는 헛간의 리스트를 구하기
    vector<int> lst;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == dis) {
            lst.push_back(i);
        }
    }

    sort(lst.begin(), lst.end());

    cout << lst[0] << " " << dis << " " << lst.size() << endl;

    return 0;
}