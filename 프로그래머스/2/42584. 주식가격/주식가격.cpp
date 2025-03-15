#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    int cnt = 0, n = static_cast<int>(prices.size());
    
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = i+1; j < n; j++) {
            cnt++;
            if (prices[i] > prices[j]) { break; }
        }
        answer.push_back(cnt);
    }
    
    return answer;
}