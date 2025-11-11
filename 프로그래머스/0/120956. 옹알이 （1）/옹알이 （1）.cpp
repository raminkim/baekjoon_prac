#include <bits/stdc++.h>

using namespace std;

vector<string> arr = {"aya", "ye", "woo", "ma"};

int solution(vector<string> babbling) {
    int answer = 0;
    
    for (string s : babbling) {
        int idx = 0;
        bool isContain = false;
        
        do {
            isContain = false;
            
            for (string p : arr) {
                if (s.find(p) == idx) {
                    isContain = true;
                    idx += p.size();
                    break;
                }
            }
        
        } while (isContain);
        
        if (idx == s.size()) {
            answer++;
        }
    }
    
    return answer;
}