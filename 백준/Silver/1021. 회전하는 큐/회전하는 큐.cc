#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    deque<int> d;
    for (int i = 1; i <= n; i++) {
        d.push_back(i);
    }

    int result = 0;

    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
 
        auto iter = find(d.begin(), d.end(), num);
        int idx = iter - d.begin();
        
        int left = idx;
        int right = d.size() - idx;
        
        if (left <= right) {
            while (left--) {
                d.push_back(d.front());
                d.pop_front();
                result++;
            }
        } else {
            while (right--) {
                d.push_front(d.back());
                d.pop_back();
                result++;
            }
        }

        d.pop_front();
    }

    cout << result << endl;
}