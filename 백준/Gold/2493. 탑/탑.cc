#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    
    stack<pair<int, int>> s;
    
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        while (!s.empty()) {
            if (s.top().second > num) {
                cout << s.top().first + 1 << " ";
                break;
            }
            s.pop();
        }
        if (s.empty()) cout << "0 ";
        s.push(make_pair(i, num));
    }

    return 0;
}