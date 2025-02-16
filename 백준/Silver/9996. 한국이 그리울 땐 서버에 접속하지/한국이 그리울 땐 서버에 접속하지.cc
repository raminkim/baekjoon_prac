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

    int idx = pattern.find("*");
    string front = pattern.substr(0, idx); // front(* 앞부분)
    string back = pattern.substr(idx+1); // back(* 뒷부분)

    while(n--) {
        string name;
        cin >> name;

        // front(* 앞부분), back(* 뒷부분)의 크기보다 name의 크기가 더 커야 함. (겹칠 수 있음.)
        if (name.size() < (front.size() + back.size())) {
            cout << "NE" << endl;
            continue;
        }
        
        int tmp = name.size()-back.size();
        if (tmp > 0 && name.substr(0, idx) == front && name.substr(tmp) == back) {
            cout << "DA" << endl;
        } else {
            cout << "NE" << endl;
        }
    }

    return 0;
}