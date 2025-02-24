#include <iostream>
#define endl "\n"

using namespace std;

int n, m;
int arr[1025][1025] = {0,};


void solve(int x1, int y1, int x2, int y2) {
    int sum = 0;
    for (int i = x1; i <= x2; i++) {
        sum += (arr[i][y2] - arr[i][y1-1]);
    }
    cout << sum << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int num;
            cin >> num;
            arr[i][j] = num;
        }
    }

    // 같은 행의 값을 왼쪽->오른쪽 순으로 더해가기
    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= n; j++) {
            arr[i][j] += arr[i][j-1];
        }
    }

    for (int i = 0; i < m; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2 && y1 == y2) cout << arr[x1][y1] - arr[x1][y1-1] << endl;
        else solve(x1, y1, x2, y2);
    }
    
    return 0;
}