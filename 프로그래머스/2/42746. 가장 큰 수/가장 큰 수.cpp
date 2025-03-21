#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string s, string s2) {
    if (s + s2 > s2 + s) return true;
    return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strings;
    
    for (size_t i = 0; i < numbers.size(); i++) { strings.push_back(to_string(numbers[i])); }
    
    sort(strings.begin(), strings.end(), compare);
    
    for (size_t i = 0; i < strings.size(); i++) { answer += strings[i]; }
    // 모두 0인 경우 방지
    if (answer == string(answer.length(), '0')) return "0";
    
    return answer;
}