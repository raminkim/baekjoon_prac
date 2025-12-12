#include <iostream>
#include <stack>

#define endl "\n"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    stack<char> stack;

    int result = 0;
    int cnt = 1;

    char c;
    char before = '\0';
    while (cin.get(c)) {
        if (c == '(') {
            stack.push(c);
            cnt*=2;
        } else if (c == '[') {
            stack.push(c);
            cnt*=3;
        } else if (c == ')') {
            if (stack.empty() || stack.top() != '(') {
                result = 0;
                break;
            }

            stack.pop();

            if (before == '(') {
                result += cnt;
            }

            cnt /= 2;
        } else if (c == ']') {
            if (stack.empty() || stack.top() != '[') {
                result = 0;
                break;
            }

            stack.pop();

            if (before == '[') {
                result += cnt;
            }

            cnt /= 3;
        }

        before = c;
    }

    cout << (stack.size() > 0 ? 0 : result) << endl;
}