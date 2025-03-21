#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int ans = 0;
bool visited[8] = {false, };

bool compare(vector<int> &a, vector<int> &b) { return a[0] > b[0]; }

void dfs(vector<vector<int>> dungeons,  size_t dungeons_rows, int k, int d) {
    // 탐험한 던전의 수가 최댓값을 넘어가면, 갱신한다.
    if (d > ans) ans = d;
    
    for (size_t i = 0; i < dungeons_rows; i++) {
        // 방문하지 않은 던전이면서, 해당 던전의 최소 필요 피로도가 현재 피로도보다 작거나 같아야 한다.
        if (!visited[i] && k >= dungeons[i][0]) {
            visited[i] = true;
            dfs(dungeons, dungeons_rows, k - dungeons[i][1], d+1);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    sort(dungeons.begin(), dungeons.end(), compare);
    dfs(dungeons, dungeons.size(), k, 0);
    return ans;
}