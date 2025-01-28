#include <iostream>

int main() {
    int i, n;
    std::cin >> n;
    
    long long arr[91]; // 최대 90번째까지의 입력값이 조건
    arr[0] = 0; // 0번째 요소는 값이 0.
    arr[1] = 1; // 1번째 요소는 값이 1.

    for (i = 2; i <= n; i++)
        arr[i] = arr[i-1] + arr[i-2];
    std::cout << arr[n];
}