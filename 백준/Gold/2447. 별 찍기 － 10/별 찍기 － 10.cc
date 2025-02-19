#include <iostream>

using namespace std;

string pattern[6562];

int n;

void func(int size, int k, int pos) {
    if (size <= 3) {
        if (k == 4) {
            pattern[pos-2].append("   ");
            pattern[pos-1].append("   ");
            pattern[pos].append("   ");
        } else {
            pattern[pos-2].append("***");
            pattern[pos-1].append("* *");
            pattern[pos].append("***");
        }
    } else {
        int next = size / 3;
        for (int i = 0; i < 9; i++) {
            if (k == 4) func(next, 4, pos + (i/3) * next);
            else func(next, i, pos + (i/3) * next);
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n; 
    func(n, 1, 3);

    for (int i = 1; i <= n; i++) cout << pattern[i] << endl;
    return 0;
}