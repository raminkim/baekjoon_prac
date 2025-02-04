#include <iostream>
#include <queue>
#define MAX 1001

// 정점의 개수 n, 간선의 개수 m, 탐색을 시작할 정점의 번호 v
int n, m, v;
int graph[MAX][MAX];
bool visited[MAX];
std::queue<int> q;

void dfs(int v) {
    visited[v] = true;
    std::cout << v << " ";
    
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && graph[v][i] == 1)
            dfs(i);
    }
}

void bfs(int v) {
    visited[v] = true;
    q.push(v);
    std::cout << v << " ";

    while(!q.empty()) {
        v = q.front();
        q.pop();

        for (int i = 1; i <= n; i++) {
            if (!visited[i] && graph[v][i] == 1) {
                q.push(i);
                visited[i] = true;
                std::cout << i << " ";
            }
        }
    }
}

void clear() {
    std::cout << std::endl;
    for (int i = 1; i <= n; i++) {
        visited[i] = {false};
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &v);

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        graph[x][y] = 1; // 양방향으로 이어졌으므로 각 1로 처리.
        graph[y][x] = 1;
    }

    dfs(v);
    clear(); // 초기화
    bfs(v);
}