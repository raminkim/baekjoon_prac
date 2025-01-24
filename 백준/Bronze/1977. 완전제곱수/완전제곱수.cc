#include <iostream>

int main() {
    int m, n;
    int i, result = 0, min = -1;

    std::cin >> m;
    std::cin >> n;

    for (i = 1; i * i <= n; i++) {
        int tmp = i * i;
        if (tmp >= m && tmp <= n) {
            result += tmp;
            if (min == -1) {
                min = tmp;
            }

        } else if (tmp > n) {
            result = -1;
            break;
        }
    }

    if (result == 0) {
        std::cout << -1;
        return 0;
    } else {
        std::cout << result << std::endl;
        std::cout << min;
    }
}