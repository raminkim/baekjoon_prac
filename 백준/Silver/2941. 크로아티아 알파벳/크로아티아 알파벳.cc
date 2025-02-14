#include <iostream>
#include <vector>
#include <string>

using namespace std;

int ans = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<string> alphabet = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    
    string s;
    cin >> s;

    for (int i = 0; i < 8; i++) {
        while(1) {
            if (s.find(alphabet[i]) == -1)
                break;
            s.replace(s.find(alphabet[i]), alphabet[i].size(), "#");
        }
    }

    cout << s.size();
    return 0;
}