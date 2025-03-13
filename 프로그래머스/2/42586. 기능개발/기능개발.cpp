#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> day;
    vector<int> answer;
    
    for (size_t i = 0; i < progresses.size(); i++) {
        int num = (100 - progresses[i]) / speeds[i];
        num = (100 - progresses[i]) > (num * speeds[i])? (num + 1) : num;
        day.push_back(num);
    }
    
    size_t n = day.size();
    for (size_t i = 0; i < n; i++) {
        size_t j = i+1;
        int cnt = 1;
        
        while (j < n) {
            if (day[i] >= day[j]) { cnt++; j++; }
            else { break; }
        }
        answer.push_back(cnt);
        i = j-1;
    }
    return answer;
}