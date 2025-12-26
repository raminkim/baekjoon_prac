#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"

using namespace std;

bool comp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second != b.second) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> vec;

    for (int i = 0; i < n; i++) {
        int a, b;
        pair<int, int> p;
        cin >> a >> b;

        p.first = a;
        p.second = b;

        vec.push_back(p);
    }
    sort(vec.begin(), vec.end(), comp);

    int last_end = -1;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        pair<int, int> p = vec[i];
        
        if (last_end > p.first) {
            continue;
        }

        last_end = p.second;
        cnt++;
    }

    cout << cnt << endl;
}