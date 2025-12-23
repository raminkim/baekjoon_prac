#include <iostream>
#include <vector>

#define endl "\n"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<long> arr;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    int cnt = 0;

    for (int i = n-1; i >= 0; i--) {
        if (arr[i] <= k) {
            cnt += k / arr[i];
            k %= arr[i];
        }
    }

    cout << cnt << endl;
}