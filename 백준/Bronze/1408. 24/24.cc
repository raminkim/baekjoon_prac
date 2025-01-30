#include <iostream>

int main() {
    int h, m, s; // 첫 번째 입력
    int h2, m2, s2; // 두 번째 입력

    scanf("%d:%d:%d", &h, &m, &s);
    scanf("%d:%d:%d", &h2, &m2, &s2);

    int start = h * 3600 + m * 60 + s;
    int end = h2 * 3600 + m2 * 60 + s2;

    if (start > end) // 첫 번째 입력이 두 번째 입력보다 더 크면 24시간을 두 번째 입력에 더한다.
        end += (24 * 3600);
    int result = end - start;

    h2 = result / 3600;
    result -= (h2 * 3600);

    m2 = result / 60;
    result -= (m2 * 60);

    s2 = result;

    printf("%02d:%02d:%02d", h2, m2, s2);
}