#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total = brown + yellow;
    
    vector<int> numbers;
    /**
    최소 갈색 격자는 8, 노란 격자는 1이므로 3*3이 최소이다.
    따라서 for문의 초깃값 i = 3, i <= total / 3까지 루프를 반복한다.
    **/
    for (int i = 3; i <= total / 3; i++) {
        if (total % i == 0) {
            numbers.push_back(i);
        }
    }
        
    
    int n = static_cast<int>(numbers.size());
    
    for (int i = 0; i < n; i++) {
        int row = total / numbers[i], col = numbers[i];
        
        // 갈색 격자의 수 b = (행 길이 x + 열 길이 y) * 2 - 4;
        int b = (row + col) * 2 - 4;
        // 노란 격자의 수 y = 총 칸 수 - b;
        int y = total - b;
        
        if (b == brown && y == yellow) {
            answer.push_back(row);
            answer.push_back(col);
            break;
        }
    }
    
    return answer;
}