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
    vector<long> money(11, 0);
    vector<int> cnt(11, 0);

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    for (int i = n-1; i >= 0; i--) {
        if (arr[i] <= k) {
            int c = k / arr[i];
            int m = arr[i] * c;

            cnt[i] = cnt[i+1] + c;
            money[i] = money[i+1] + m;
            k -= m;

            continue;
        }

        cnt[i] = cnt[i+1];
        money[i] = money[i+1];
    }

    cout << cnt[0] << endl;
}