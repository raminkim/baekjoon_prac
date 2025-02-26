#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#define endl "\n"

using namespace std;

// 회원의 수 n, 각 회원의 점수를 임시저장할 c, 최저 점수를 저장할 m
int n, c = 0, m = 52;

vector<int> vec[51];
vector<int> ans;
bool visited[51] = {false};

void bfs(int v) {
    queue<pair<int, int>> q;
    q.push(make_pair(v, 0));
    visited[v] = true;

    while (!q.empty()) {
        pair<int, int> tmp = q.front();
        int num = get<0>(tmp); // 번호
        int dep = get<1>(tmp); // 친구 관계
        q.pop();


        // c를 갱신
        if (dep > c) c = dep;

        for (int i: vec[num]) {
            if (!visited[i]) {
                visited[i] = true;
                // cout << num << "에서 " << i << "의 깊이 변화 : " << dep << " -> " << dep+1 << endl;
                q.push(make_pair(i, dep+1));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    while(1) {
        int a, b;
        cin >> a >> b;
        if (a == -1 && b == -1) break;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        // cout << "----" << endl;
        // cout << i << " 시작" << endl;

        c = 0;
        fill(visited, visited+51, false);
        bfs(i);
        // cout << "점수는 " << c << endl;

        // 최저 점수 m을 갱신하거나, 같다면 ans 벡터 리스트에 추가(push)한다.
        if (c < m) {
            m = c;
            ans.clear();
            ans.push_back(i);
        } else if (c == m) {
            ans.push_back(i);
        }
    }

    cout << m << " " << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    return 0;
}