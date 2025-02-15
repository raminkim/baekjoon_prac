#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> q;

void push(int n) {
    q.push_back(n);
}

int pop() {
    if (!q.size()) return -1;

    int tmp = q.front();
    vector<int> q2;
    for (int i = 1; i < q.size(); i++) q2.push_back(q[i]);
    q = q2;
    return tmp;
}

int size() {
    return q.size();
}

int empty() {
    if (!size()) return 1;
    return 0;
}

int front() {
    if (!size()) return -1;
    return q[0];
}

int back() {
    if (!size()) return -1;
    return q[size()-1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    while(n--) {
        string s;
        cin >> s;
        if (s == string("push")) {
            int m;
            cin >> m;
            push(m);
        } else if (s == string("pop")) {
            cout << pop() << endl;
        } else if (s == string("size")) {
            cout << size() << endl;
        } else if (s == string("empty")) {
            cout << empty() << endl;
        } else if (s == string("front")) {
            cout << front() << endl;
        } else if (s == string("back")) {
            cout << back() << endl;
        }
    }

    return 0;
}