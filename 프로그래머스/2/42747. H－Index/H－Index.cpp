#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int n = static_cast<int>(citations.size());
    int ans = 0;
    
    sort(citations.begin(), citations.end());
    int m = *max_element(citations.begin(), citations.end());
    
    // citations의 최댓값인 m부터 while문을 돌며 검사한다.
    while (m--) {
        int cnt = 0;
        for (int i = n-1; i >= 0; i--) {
            // m 이하라면 카운트를 멈춰야 하므로, break
            if (citations[i] < m) break;
            cnt++;
        }
        ans = (cnt >= m && m > ans)? m : ans;
    }
    
    return ans;
}