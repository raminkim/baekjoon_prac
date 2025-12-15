#include <iostream>
#include <vector>

#define endl "\n"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> vec;
    
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        vec.push_back(num);
    }

    int result = 0;

    for (int i = n-2; i >= 0; i--) {
        if (vec[i] >= vec[i+1]) {
            int diff = (abs(vec[i+1] - vec[i]) + 1);
            vec[i] -= diff;
            result += diff;
        }
    }

    cout << result << endl;
}