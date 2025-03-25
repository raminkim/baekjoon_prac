#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (size_t i = 0; i < scoville.size(); i++) {
        pq.push(scoville[i]);
    }
    
    
    while (pq.size() > 1 && pq.top() < K) {
        int fir_min = pq.top();
        pq.pop();
        
        int sec_min = pq.top();
        pq.pop();
        
        int mix = fir_min + sec_min * 2;
        pq.push(mix);

        answer++;
    }
    
    return (pq.top() >= K)? answer : -1;
}