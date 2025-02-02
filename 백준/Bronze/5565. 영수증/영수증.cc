#include <iostream>

int main() {
    int arr[9] = {0};
    int sum, i;
    scanf("%d", &sum);

    for(i=0; i < 9; i++) {
        std::cin >> arr[i];
        sum -= arr[i];
    }
    std::cout << sum;
}