#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdlib>

using namespace std;

int ans = 99;

int solution(int n, vector<vector<int>> wires) {
    for (int i = 0; i < n-1; i++) {
        set<int> a;
        set<int> b;
        
        a.insert(wires[i][0]);
        b.insert(wires[i][1]);
        
        while (a.size() + b.size() < n) {
            for (int j = 0; j < n-1; j++) {
                if (i == j) continue;
                
                auto a1 = a.find(wires[j][0]);
                auto a2 = a.find(wires[j][1]);
                
                if (a1 != a.end() || a2 != a.end()) {
                    a.insert(wires[j][0]);
                    a.insert(wires[j][1]);
                }
                
                auto b1 = b.find(wires[j][0]);
                auto b2 = b.find(wires[j][1]);
                
                if (b1 != b.end() || b2 != b.end()) {
                    b.insert(wires[j][0]);
                    b.insert(wires[j][1]);
                }
            }
        }
        
        int diff = b.size() - a.size();
        ans = min((diff < 0)? -diff : diff, ans);
    }
    return ans;
}