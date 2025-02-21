#include <iostream>
#include <memory.h>

using namespace std;

int n;
int arr[2187][2187]; // 3 ^ 7 = 2187
int ans[3] = {0, 0, 0};

bool check(int x, int y, int size) {
    int num = arr[x][y];
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            // 하나라도 틀린 것이 있다면 false를 반환
            if (num != arr[i][j]) return false;
        }
    }
    return true;
}

void func(int x, int y, int size) {
    if (size <= 1 || check(x, y, size)) {
        ans[arr[x][y]+1]++;
        // cout << x << " " << y << " | " << arr[x][y] << "이고, " << ans[arr[x][y]+1] << endl;
        return;
    } else {
        func(x, y, size/3);
        func(x, y + size/3, size/3);
        func(x, y + size*2/3, size/3);
        func(x + size/3, y, size/3);
        func(x + size/3, y + size/3, size/3);
        func(x + size/3, y + size*2/3, size/3);
        func(x + size*2/3, y, size/3);
        func(x + size*2/3, y + size/3, size/3);
        func(x + size*2/3, y + size*2/3, size/3);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    func(0, 0, n);
    
    for (int i = 0; i <= 2; i++) cout << ans[i] << endl;
    
    return 0;
}