#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> v[3];

void init() {
    for (int i: {1, 2, 3, 4, 5}) {
        v[0].push_back(i);
    }
    for (int i: {2, 1, 2, 3, 2, 4, 2, 5}) {
        v[1].push_back(i);
    }
    for (int i: {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}) {
        v[2].push_back(i);
    }
    
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    init();
    
    int n = static_cast<int>(answers.size());
    int max_num = 0;
    
    for (int i = 0; i < 3; i++) {
        int ans = 0;
        int m = static_cast<int>(v[i].size());
        
        for (int j = 0; j < n; j++) {
            if (v[i][j%m] == answers[j]) ans++;
        }
        if (ans > max_num) { max_num = ans; answer.clear(); answer.push_back(i+1); }
        else if (ans == max_num) { answer.push_back(i+1); }
    }
    return answer;
}