#include <iostream>
#include <map>
#include <string>

int main() {
    int n, p;
    int i, j;

    std::cin >> n; // 테스트 케이스 개수

    for (i = 0; i < n; i++) {
        std::cin >> p; // 고려해야 될 선수의 수
        std::map<int, std::string> my_map;
        for (j = 0; j < p; j++) {
            int a;
            char b[20];
            scanf("%d %s", &a, b);
            my_map[a] = b; // 입력받은 값을 map에 추가하기
        }
        int max_key = my_map.rbegin() -> first;
        printf("%s\n", my_map[max_key].c_str());
    }
}