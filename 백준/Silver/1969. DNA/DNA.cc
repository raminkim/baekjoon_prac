#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n;
    cin >> m;

    vector<string> vec;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        vec.push_back(s);
    }

    string result_str = "";

    for (int j = 0; j < m; j++) {
        map<char, int> map;

        for (int i = 0; i < n; i++) {
            map[vec[i][j]]++;
        }
        
        char best_char = 'A';
        int best_cnt = 0;

        for (auto &p : map) {
            if (p.second > best_cnt) {
                best_char = p.first;
                best_cnt = p.second;
            } else if (p.second == best_cnt && p.first < best_char) {
                best_char = p.first;
            }
        }
        
        result_str += best_char;
    }

    cout << result_str << endl;

    
    int result_cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vec[i][j] != result_str[j]) {
                result_cnt++;
            }
        }
    }

    cout << result_cnt << endl;
}