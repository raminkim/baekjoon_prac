#include <iostream>
#include <queue>
#define endl "\n"

using namespace std;

int n;
int cnt = 0; // 과일 종류의 수
int ans = 0;
queue<int> dq;
int type[10] = {0,}; // 과일 종류가 얼마나 들어가 있는지 ?

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    
    while (n--) {
        int m;
        cin >> m;
        dq.push(m);

        if (type[m]++ == 0) {
            cnt++;
        }

        while (cnt > 2) {
            int k = dq.front();
            dq.pop();
            if (--type[k] == 0) {
                --cnt;
            }
        }

        ans = max(ans, static_cast<int>(dq.size()));
    }

    cout << ans;
    return 0;
}