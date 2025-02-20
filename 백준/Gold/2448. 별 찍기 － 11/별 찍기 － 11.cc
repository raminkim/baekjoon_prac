#include <iostream>
#include <memory.h>

using namespace std;

int n;
char arr[3072][6144]; // 3 x (2^10) = 3072

void func(int i, int j, int size) {
    if (size == 3) {
        arr[i][j] = '*';

        arr[i+1][j-1] = '*';
        arr[i+1][j+1] = '*';

        arr[i+2][j-2] = '*';
        arr[i+2][j-1] = '*';
        arr[i+2][j] = '*';
        arr[i+2][j+1] = '*';
        arr[i+2][j+2] = '*';
    } else {
        func(i, j, size/2);
        func(i + (size/2), j - (size/2), size/2);
        func(i + (size/2), j + (size/2), size/2);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    // 배열 초기화
    memset(arr, ' ', sizeof(arr));

    func(0, n-1, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2*n; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }
    
    return 0;
}