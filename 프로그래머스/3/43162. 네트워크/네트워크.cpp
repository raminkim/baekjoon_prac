#include <iostream>
#include <string>
#include <vector>

using namespace std;

int ans = 0, n2;
vector<vector<int>> com;
bool visited[200] = {false,};

void dfs(int v) {
    visited[v] = true;
    
    for (int i = 0; i < n2; i++) {
        if (!com[v][i] || visited[i]) continue;
        dfs(i);
    }
}

int solution(int n, vector<vector<int>> computers) {
    com = computers;
    n2 = n;
    
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;

        visited[i] = true;
        ans++;
        dfs(i);
    }
    return ans;
}