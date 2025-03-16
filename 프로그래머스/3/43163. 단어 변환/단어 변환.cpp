#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

bool visited[50] = {false};

int compare(string s1, string s2) {
    int cnt = 0;
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] != s2[i]) cnt++;
        // 한 글자를 초과하여 다르면 변환 불가인 -1 반환
        if (cnt > 1) { return -1; }
    }
    // 한 글자만 다르다면 0을 반환
    return (cnt == 1)? 0 : -1;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 987654321;
    if (find(words.begin(), words.end(), target) == words.end()) { return 0; }
    
    queue<tuple<string, int, int>> q;
    q.push(make_tuple(begin, 0, -1));

    
    while (!q.empty()) {
        tuple<string, int, int> t = q.front();
        q.pop();
        
        string s = get<0>(t);
        int d = get<1>(t);
        int idx = get<2>(t);
        
        cout << s << " " << d << endl;
        
        if (s == target) { answer = min(answer, d); continue; }
        
        
        for (int i = 0; i < static_cast<int>(words.size()); i++) {
            if (s != words[i] && !visited[i] && compare(s, words[i]) == 0) {
                q.push(make_tuple(words[i], d+1, i));
                visited[i] = true;
            }
        }
    }
    
    return answer;
}