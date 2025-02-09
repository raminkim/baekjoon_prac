#include <iostream>
using namespace std;

string board[65];

bool check(int x, int y, int n) {
    
    for (int i = x; i < x+n; i++) {
        for (int j = y; j < y+n; j++) {
            if (board[i][j] != board[x][y])
                return false;
        }
    }
    return true;
}

void func(int x, int y, int n) {
    if (check(x, y, n)) {
        cout << board[x][y];
        return;
    } else {
        int tmp = n / 2; // 4등분 시키기

        cout << "(";
        func(x, y, tmp); // 2사분면
        func(x, y+tmp, tmp); // 1사분면
        func(x+tmp, y, tmp); // 3사분면
        func(x+tmp, y+tmp, tmp); // 4사분면
        cout << ")";
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> board[i];

    func(0, 0, n);
    return 0;
}