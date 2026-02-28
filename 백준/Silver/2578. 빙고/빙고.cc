#include <iostream>
#include <vector>

#define endl "\n"

using namespace std;

int n = 5;

int bingo = 0;

vector<pair<int, int>> pos(26);
vector<int> rowCnt(n), colCnt(n), diagCnt(2);
vector<char> rowDone(n, 0), colDone(n, 0), diagDone(2, 0);

bool checkBingo(int num) {
    pair<int, int> p = pos[num];
    int row = p.first, col = p.second;

    if (!rowDone[row] && ++rowCnt[row] == n) {
        rowDone[row] = 1;
        bingo++;
    }

    if (!colDone[col] && ++colCnt[col] == n) {
        colDone[col] = 1;
        bingo++;
    }

    if (row == col && !diagDone[0] && ++diagCnt[0] == n) {
        diagDone[0] = 1;
        bingo++;
    }

    if (row+col == n-1 && !diagDone[1] && ++diagCnt[1] == n) {
        diagDone[1] = 1;
        bingo++;
    }

    return bingo >= 3;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int num;
            cin >> num;

            pos[num] = {i, j};
        }
    }

    int call = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int num;
            cin >> num;
            call++;

            if (checkBingo(num)) {
                cout << call << endl;
                return 0;
            }
        }
    }
}
