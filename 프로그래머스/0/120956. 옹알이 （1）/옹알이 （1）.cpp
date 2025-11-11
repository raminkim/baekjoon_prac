#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    for (string s : babbling) {
        size_t idx = 0;
        
        idx = s.find("aya");
        if (idx != string::npos) { s.replace(idx, 3, " "); }
        
        idx = s.find("ye");
        if (idx != string::npos) { s.replace(idx, 2, " "); }
        
        idx = s.find("woo");
        if (idx != string::npos) { s.replace(idx, 3, " "); }
        
        idx = s.find("ma");
        if (idx != string::npos) { s.replace(idx, 2, " "); }
        
        answer += s.find_first_not_of(" ") == string::npos;
    }
    
    return answer;
}