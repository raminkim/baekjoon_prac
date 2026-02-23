#include <iostream>
#include <vector>

#define endl "\n"

using namespace std;

vector<int> vec;

int junhyun(int budget) {
    int cnt = 0;
    for (int n : vec) {
        int b = 0;

        b = budget / n;
        budget -= n * b;
        cnt += b;
    }

    return budget + vec.back() * cnt;
}

int sungmin(int budget) {
    int cnt = 0;
    int up = 0, down = 0;

    for (int i = 1; i < vec.size(); i++) {
        int b = 0;

        if (vec[i] > vec[i-1]) {
            up++;
            down = 0;
        } else if (vec[i] < vec[i-1]) {
            up = 0;
            down++;
        } else {
            up = 0, down = 0;
        }

        if (up == 3) {
            budget += cnt * vec[i];
            cnt = 0;
        } else if (down == 3) {
            b = budget / vec[i];
            budget -= b * vec[i];
            cnt += b;
        }
    }

    return budget + vec.back() * cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int budget;
    cin >> budget;

    for (int i = 0; i < 14; i++) {
        int price;
        cin >> price;

        vec.push_back(price);
    }

    int jun = junhyun(budget);
    int sung = sungmin(budget);

    cout << ((jun > sung) ? "BNP" : (jun == sung ? "SAMESAME" : "TIMING"));
}
