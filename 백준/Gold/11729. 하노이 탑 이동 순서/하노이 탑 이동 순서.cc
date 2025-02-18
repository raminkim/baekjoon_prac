#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int ans = 0;
string answer = "";

void hanoi(int n, int start, int end, int sub) {
    if (n <= 0) return;

    hanoi(n-1, start, sub, end);
    answer.append(to_string(start)); answer.append(" "); answer.append(to_string(end)); answer.append("\n");
    ans++;
    hanoi(n-1, sub, end, start);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    hanoi(n, 1, 3, 2);
    cout << ans << endl;
    cout << answer;
}