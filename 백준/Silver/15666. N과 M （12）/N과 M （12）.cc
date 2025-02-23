#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
set<int> s;
vector<int> vec;

void backtracking(int v, int cnt) {
    if (cnt == m) {
        for (int num: vec)
            cout << num << " ";
        cout << "\n";
        return;
    }
    for (auto x : s) {
        if (x >= v) {
            vec.push_back(x);
            backtracking(x, cnt+1);
            vec.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    
    while (n--) {
        int num;
        cin >> num;
        s.insert(num);
    }

    int cnt = 0;
    int v;
    for (auto x: s) {
        if (cnt > 0) break;
        v = x;
        cnt++;
    }

    backtracking(v, 0);
    return 0;
}