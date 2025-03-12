#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> um;
    
    for (size_t i = 0; i < clothes.size(); i++) {
        um[clothes[i][1]]+=1;
    }
    
    // 안입는 경우도 포함하기 위해 +1
    for (auto& u: um)
        answer *= u.second + 1;
    
    return answer - 1;
}