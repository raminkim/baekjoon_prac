#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int n;
// 이미 위험지역 표시
bool boom_visited[100][100] = {false,};

int movX[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int movY[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

int solution(vector<vector<int>> board) {
    int answer = 0;
    n = static_cast<int>(board.size());
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j]) {
                for (int k = 0; k < 9; k++) {
                    int x2 = i + movX[k];
                    int y2 = j + movY[k];
                    
                    if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= n) continue;
                    if (!boom_visited[x2][y2]) { boom_visited[x2][y2] = true; answer++; }
                }                
            }
        }
    }
    
    return n*n - answer;
}