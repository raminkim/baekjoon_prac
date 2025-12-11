#include <iostream>
#include <queue>

#define endl "\n"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    queue<int> q;
    
    for (int i = 0; i < n; i++) {
        int num;
        string s;
        cin >> s;
        
        if (s == "push") {
            cin >> num;
            q.push(num);
        } else if (s == "pop") {
            if (q.size() > 0) {
                cout << q.front() << endl;
                q.pop();
                continue;
            }
            cout << -1 << endl;
        } else if (s == "size") {
            cout << (q.size() > 0 ? q.size() : 0) << endl;
        } else if (s == "empty") {
            cout << (q.size() == 0 ? 1 : 0) << endl;
        } else if (s == "front") {
            cout << (q.size() > 0 ? q.front() : -1) << endl;
        } else if (s == "back") {
            cout << (q.size() > 0 ? q.back() : -1) << endl;
        }
    }
}