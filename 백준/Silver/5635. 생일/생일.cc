#include <iostream>
#include <cstring>

int main() {
    int n, i;
    std::cin >> n;
    int max = 0, min = 99999999; // max는 나이가 가장 적은 사람(숫자가 가장 큼), min은 나이가 가장 많은 사람.
    char max_s[15], min_s[15];

    for (i = 0; i < n; i++) {
        char name[15];
        int y, m, d;
        scanf("%s %d %d %d", name, &d, &m, &y);
        int sum = y*10000+m*100+d;
        if (sum > max) {
            max = sum;
            std::strcpy(max_s, name);
        } else if (sum < min) {
            min = sum;
            std::strcpy(min_s, name);
        }
    }
    std::cout << max_s << std::endl;
    std::cout << min_s << std::endl;
}