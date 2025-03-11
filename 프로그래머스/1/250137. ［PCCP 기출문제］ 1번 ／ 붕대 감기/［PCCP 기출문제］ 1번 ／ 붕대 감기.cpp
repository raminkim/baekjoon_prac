#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {

    int t, x, y;

    t = bandage[0]; // 시전시간
    x = bandage[1]; // 초당 회복량
    y = bandage[2]; // 추가 회복량

    int s = static_cast<int>(attacks.size());
    int n = attacks[s-1][0];
    int m = 0, time = 0;
    int max = health;

    for (int i = 1; i <= n; i++) {
        if (health <= 0) break;
        if (m < s && attacks[m][0] == i) { health -= attacks[m][1]; m++; time = 0; continue; }
        health += x;
        time++;
        if (time == t) { health += y; time = 0; }
        if (health > max) health = max;
    }

    return (health <= 0)? -1 : health;
}