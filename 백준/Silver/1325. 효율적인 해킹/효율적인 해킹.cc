#include <iostream>
#include <vector>
#define endl "\n"

using namespace std;

int n, m;
// 최대 해킹가능한 수를 peak, 각 노드를 dfs할 때마다 방문하는 노드의 수를 count에 저장
int peak = 0, count = 0;
vector<int> ans;
vector<int> vec[10001];
bool visited[10001] = {false};

void dfs(int v) {
    // 해킹할 수 있는 최대 컴퓨터 수를 갱신
    visited[v] = true;
    count++;
    
    for (int i: vec[v]) {
        if (!visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    
    while (m--) {
        int a, b;
        cin >> a >> b;
        vec[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        count = 0;
        fill(visited, visited + 10001, false);
        dfs(i);

        if (count > peak) {
            peak = count;
            ans.clear();
            ans.push_back(i);
        } else if (count == peak) {
            ans.push_back(i);
        }
    }

    
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}