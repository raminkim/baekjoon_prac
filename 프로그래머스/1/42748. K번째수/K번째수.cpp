#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (size_t i = 0; i < commands.size(); i++) {
        int a = commands[i][0], b = commands[i][1], c = commands[i][2];
        vector<int> tmp(array.begin() + a - 1, array.begin() + b);
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[c-1]);
    }
    return answer;
}