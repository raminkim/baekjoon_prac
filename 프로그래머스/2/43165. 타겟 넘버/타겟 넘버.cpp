#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> v;
int t, n, ans = 0;

void dfs(int sum, int dep) {
    
    if (dep == n) { 
        ans += (sum == t)? 1 : 0;
        // if (sum == t) cout << sum << " " << dep << " " << ans << endl;
        return; 
    }
    dfs(sum + v[dep], dep+1);
    dfs(sum - v[dep], dep+1);
}

int solution(vector<int> numbers, int target) {
    t = target;
    n = static_cast<int>(numbers.size());
    v = numbers;
    
    dfs(numbers[0], 1);
    dfs(-numbers[0], 1);
    
    return ans;
}