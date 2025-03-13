#include <string>
#include <vector>
#include <queue>
#include <algorithm>

struct s {
    int priority;
    int location;
};

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<s> q;
    
    for (int i = 0; i < static_cast<int>(priorities.size()); i++) { q.push({priorities[i], i}); }
    sort(priorities.begin(), priorities.end(), [](int a, int b) { return a > b; });
    
    
    while (1) {
        struct s s1 = q.front();
        q.pop();
        
        if (s1.priority == priorities[answer]) {
            ++answer;
            
            if (s1.location == location) return answer;
            continue;
        }
        q.push(s1);
    }
    return 0;
}