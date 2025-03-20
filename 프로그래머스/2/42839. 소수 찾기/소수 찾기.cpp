#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define MAX 10000000

using namespace std;

int number[MAX];
bool visited[10] = {false, };

int ans = 0, n;
string str;


void func(string s, string s2) {
    // 소수라면, 해당 index의 값을 0으로 만들고 ans를 1 증가시킨다.
    if (s2 != "" && number[stoi(s2)] != 0) { number[stoi(s2)] = 0; ans++; }
    
    for (int i = 0; i < n; i++) {
        if (visited[i])
            continue;
        visited[i] = true;
        func(s, s2 + to_string(str[i]-48));
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
    
    func(numbers, "");
    
    return ans;
}