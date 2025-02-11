#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; // 컴퓨터의 수
    cin >> n;

    int m; // 컴퓨터 쌍의 수
    cin >> m;

    vector<vector<int>> board(n+2);
    bool visited[n+1] = {false};
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        board[a+1].push_back(b);
        board[b+1].push_back(a);
    }

    set<int> set_list; // 컴퓨터들의 리스트(set)
    queue<int> q;
    q.push(1);
    visited[1] = true;

    while(!q.empty()) {
        int n = q.front();
        q.pop();
        for (int v: board[n+1]) {
            if (!visited[v+1]) {
                q.push(v);
                visited[v+1] = true;
                set_list.insert(v);
            }
        }
    }

    set_list.erase(1); // 1번 제거.
    cout << set_list.size();
}