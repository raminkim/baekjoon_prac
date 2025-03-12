#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// 가져갈 수 있는 수
int n, m;
vector<int> vec;

vector<int> cast2set(vector<int>nums) {
    set<int> s;
    for (int i = 0; i < n; i++) {
        s.insert(nums[i]);
    }
    
    vector<int> vtr(s.begin(), s.end());
    return vtr;
}

int solution(vector<int> nums)
{   
    ios::sync_with_stdio(false);
    cin.tie(0);

    n = static_cast<int>(nums.size());
    m = n / 2;
    
    nums = cast2set(nums);
    n = static_cast<int>(nums.size());
    
    return min(n, m);
}