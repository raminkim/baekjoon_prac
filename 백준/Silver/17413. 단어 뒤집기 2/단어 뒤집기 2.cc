#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    bool isTag = false;

    string input;
    string buf = "";
    string result = "";

    getline(cin, input);

    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '<') {
            reverse(buf.begin(), buf.end());
            result += buf;
            buf = "";

            isTag = true;
            result += input[i];
            continue;
        } else if (isTag && input[i] == '>') {
            isTag = false;
            result += input[i];
            continue;
        }

        if (isTag) {
            result += input[i];
        } else {
            if (input[i] == ' ') {
                reverse(buf.begin(), buf.end());
                result += buf + ' ';
                buf = "";
                continue;
            }

            buf += input[i];
        }
    }

    reverse(buf.begin(), buf.end());
    result += buf;

    cout << result << endl;
}