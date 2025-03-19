#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int x = 0, y = 0;
    
    // 최댓값 산출하기
    for (size_t i = 0; i < sizes.size(); i++) {
        x = max(*max_element(sizes[i].begin(), sizes[i].end()), x);
        y = max(*min_element(sizes[i].begin(), sizes[i].end()), y);
    }

    
    return x * y;
}