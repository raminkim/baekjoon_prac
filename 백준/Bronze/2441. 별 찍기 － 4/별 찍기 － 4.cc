#include <iostream>

int main() {
    int i, j, n;
    std::cin >> n;

    for(i = n; i > 0; i--) {
        for (j = n-i; j > 0; j--) {
            std::cout << " ";
        }
        for (j = i; j > 0; j--) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}