#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define MAX 10000000

using namespace std;

int number[MAX];
bool visited[MAX] = {false, };

int ans = 0, n;
string str;


void func(string s, int idx, int dep) {
    
    // 소수라면, 해당 index의 값을 0으로 만들고 ans를 1 증가시킨다.
    if (number[stoi(s)] != 0) {  number[stoi(s)] = 0; ans++; }
    // 이미 n개의 char로 숫자를 만들었다면, return한다.
    if (dep == n) { return; }
    
    visited[idx] = true;
    for (int i = 0; i < n; i++) {
        if (visited[i]) 
            continue;
        
        func(s + to_string(str[i]-48), i, dep+1);
        visited[i] = false;
    }
}

/** 
    에라토스테네스의 체 알고리즘
    : 이중 루프로 2부터 MAX까지 해당 수의 배수의 인덱스를 0으로 만들면, 나머지는 모두 소수이다.
      만약 루프를 돌다, number[i]가 0이라면 이미 소수가 아닌 것을 판단하였으므로 continue.
**/
void eratosthenes() {
    // 0, 1은 소수가 아니다.
    number[0] = 0;
    number[1] = 0;
    
    for (int i = 2; i < MAX; i++) {
        if (number[i] == 0) continue;
        
        for (int j = i + i; j < MAX; j+=i) {
            number[j] = 0;
        }
    }
}

int solution(string numbers) {
    fill(number, number + MAX, 1);
    eratosthenes();
    
    n = numbers.length();
    str = numbers;
    
    for (int i = 0; i < n; i++) {
        // 재귀를 돌기 전에 visited를 false로 모두 초기화
        fill(visited, visited + MAX, false);
        
        // to_string으로 변환할 경우, ascii값으로 들어가므로 -48로 처리해주었음.
        func(to_string(str[i]-48), i, 1);
    }
    
    return ans;
}