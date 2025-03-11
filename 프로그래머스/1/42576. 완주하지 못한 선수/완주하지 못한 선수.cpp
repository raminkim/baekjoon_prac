#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    string answer = "";
    unordered_map<string, int> hash;
    int n = static_cast<int>(participant.size());
    int m = static_cast<int>(completion.size());
    
    for (int i = 0; i < n; i++) {
        hash[participant[i]] += 1;
    }
    
    for (int i = 0; i < m; i++) {
        if(hash[completion[i]] == 1) { hash.erase(completion[i]); continue; }
        hash[completion[i]]--;
    }
    
    for (auto elem: hash) {
        answer = elem.first;
    }
    return answer;
}