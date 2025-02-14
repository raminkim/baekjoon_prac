#include <iostream>
#include <vector>
#include <string>

using namespace std;

int ans = 0;

int func(string two, string three) {
    int cnt = 0;
    ans++;

    if (two == string("c="))
        cnt++;
    else if (two == string("c-"))
        cnt++;
    else if (two == string("d-"))
        cnt++;
    else if (two == string("lj"))
        cnt++;
    else if (two == string("nj"))
        cnt++;
    else if (two == string("s="))
        cnt++;
    else if (two == string("z="))
        cnt++;
    
    if (three == string("dz="))
        cnt+=2;
    
    if (cnt)
        return cnt;
    
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;

    int i;

    for (i = 0; i < s.size(); i++) {
        string two = s.substr(i, 2);
        string three = s.substr(i, 3);
        i = i + func(two, three);
    }

    cout << ans;
    return 0;
}