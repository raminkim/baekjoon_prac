#include <iostream>
#include <cstring>
using namespace std;

int stack[10001];
int len = 0;

void push(int num) {
    stack[len++] = num;
}

int size() {
    return len;
}

int empty() {
    if (size() == 0)
        return 1;
    else
        return 0;
}

int pop() {
    if (!empty())
        return stack[--len];
    return -1; // 만약 스택에 들어있는 정수가 없다면?
}

int top() {
    if (!empty()) // 스택의 가장 위에 있는 정수를 출력한다.
        return stack[len-1];
    return -1; // 만약 스택에 들어있는 정수가 없다면?
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        char command[10];
        cin >> command;

        if (strcmp(command, "push") == 0) {
            int num;
            cin >> num; // push 명령어일 때만 num 입력받기
            push(num);
        } else if (strcmp(command, "pop") == 0) {
            cout << pop() << endl;
        } else if (strcmp(command, "size") == 0) {
            cout << size() << endl;
        } else if (strcmp(command, "empty") == 0) {
            cout << empty() << endl;
        } else if (strcmp(command, "top") == 0) {
            cout << top() << endl;
        }
    }

    return 0;
}