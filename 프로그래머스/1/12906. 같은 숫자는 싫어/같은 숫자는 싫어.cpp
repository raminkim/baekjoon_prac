#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int n = 0;
    answer.push_back(arr[0]);

    for (size_t i = 1; i < arr.size(); i++) {
        if (answer[n] != arr[i]) { answer.push_back(arr[i]); n++; }
    }
    return answer;
}