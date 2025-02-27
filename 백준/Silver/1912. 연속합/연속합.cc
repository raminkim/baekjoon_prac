#include <iostream>
#define endl "\n"

using namespace std;

int n;
int ans = -1001;

int arr[100001] = {0,};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++) {
        arr[i] = max(arr[i-1] + arr[i], arr[i]);
        ans = (arr[i] > ans) ? arr[i] : ans;
    }

    cout << ans;
    
    return 0;
}