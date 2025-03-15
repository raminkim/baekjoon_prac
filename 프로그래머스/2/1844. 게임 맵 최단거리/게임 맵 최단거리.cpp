#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int ans = 987654321, n, m;

int movX[4] = {1, 0, -1, 0};
int movY[4] = {0, 1, 0, -1};
bool visited[100][100] = {false};
               
int solution(vector<vector<int>> maps)
{
    n = static_cast<int>(maps.size());
    m = static_cast<int>(maps[0].size());
    queue<tuple<int, int, int>> q;
    visited[0][0] = true;
    q.push(make_tuple(0, 0, 1));
    
    while (!q.empty()) {            
        tuple<int, int, int> t = q.front();
        q.pop();
        
        if (get<0>(t) == n-1 && get<1>(t) == m-1) ans = min(ans, get<2>(t));
        
        for (int i = 0; i < 4; i++) {
            int x = get<0>(t) + movX[i];
            int y = get<1>(t) + movY[i];
            if (x < 0 || x >= n || y < 0 || y >= m || !maps[x][y] || visited[x][y]) continue;
            visited[x][y] = true;
            q.push(make_tuple(x, y, get<2>(t)+1));
        }
    }
    
    return (ans == 987654321)? -1: ans;
}