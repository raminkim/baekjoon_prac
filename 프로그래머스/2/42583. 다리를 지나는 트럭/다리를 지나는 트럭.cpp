#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int n = static_cast<int>(truck_weights.size());
    int cur_weight = 0, idx = 0, t = 0;
    queue<pair<int, int>> q;
    
    while (!q.empty() || idx < n) {
        ++t;
        // 트럭이 다리를 지나갔다면
        if (!q.empty() && q.front().second == bridge_length) {
            cur_weight -= q.front().first;
            q.pop();
        }
        
        // 트럭을 다리 위에 올릴 수 있을 때
        if (idx < n && cur_weight + truck_weights[idx] <= weight) {
            q.push(make_pair(truck_weights[idx], 0));
            cur_weight += truck_weights[idx];
            idx++;
        }
        
        for (int i = 0; i < static_cast<int>(q.size()); i++) {
            pair<int, int> p = q.front();
            q.pop();
            p.second++;
            q.push(p);
        }
    }
    
    return t;
}