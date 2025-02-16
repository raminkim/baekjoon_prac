#include <iostream>
#include <string>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    string pattern;
    cin >> pattern;

    string front;
    string back;

    int idx = pattern.find("*");
    front = pattern.substr(0, idx);
    back = pattern.substr(idx+1);

    // cout << front << endl;
    // cout << back << endl;

    while(n--) {
        string name;
        cin >> name;
        
        int tmp = name.size()-back.size();
        // cout << name.substr(0, idx) << endl;
        // cout << name.substr(name.size()-back.size());
        if (name.size() >= (front.size() + back.size()) && tmp > 0 && name.substr(0, idx) == front && name.substr(tmp) == back) {
            cout << "DA" << endl;
        } else {
            cout << "NE" << endl;
        }
    }

    return 0;
}