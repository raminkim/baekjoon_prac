#include <iostream>
#include <vector>

#define endl "\n"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<string> arr(n);
    vector<string> click(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> click[i];
    }

    int dx[8] = {-1,-1,-1,0,0,1,1,1};
    int dy[8] = {-1,0,1,-1,1,-1,0,1};

    bool exploded = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (click[i][j] == 'x' && arr[i][j] == '*') {
                exploded = true;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (exploded && arr[i][j] == '*') {
                cout << '*';
                continue;
            } else if (click[i][j] == '.') {
                cout << '.';
                continue;
            }

            int bomb = 0;

            for (int k = 0; k < 8; k++) {
                int move_x = i+dx[k], move_y = j+dy[k];

                if (move_x < 0 || move_y < 0 || move_x >= n || move_y >= n) {
                    continue;
                }

                if (arr[move_x][move_y] == '*') {
                    bomb++;
                }
            }

            cout << bomb;
        }
        cout << endl;
    }
}
