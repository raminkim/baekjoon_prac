#include <iostream>

#define endl "\n"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int result = 0;
    int openCnt = 0;
    
    char c;
    char before = '\0';
    while(cin.get(c)) {
        if (c == '(') {
            openCnt++;
        } else if (c == ')') {
            openCnt--;
            result += (before == '('? openCnt : 1);
        }

        before = c;
    }

    cout << result << endl;
}