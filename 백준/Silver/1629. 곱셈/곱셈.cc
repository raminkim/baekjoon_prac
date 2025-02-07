#include <iostream>

using namespace std;

long long cal(long long a, long long b, long long c) {
    if (b == 0)
        return 1;
    else if (b == 1)
        return a % c;

    long long tmp;
    tmp = cal(a, b/2, c);
    tmp = tmp * tmp % c;

    if (b % 2 == 1) // 홀수라면? a를 한번 더 곱해야 한다.
        tmp = tmp * a % c;
    return tmp;
}

int main() {
    long long a, b, c;
    cin >> a >> b >> c;

    cout << cal(a, b, c);
}