#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (s.size() == 2) {
        if (s[0] == s[1]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        return 0;
    }

    if (s.front() == 'B') {
        cout << "Yes" << endl;
        return 0;
    }

    if (s.front() == 'A') {
        if (s.back() == 'B') {
            cout << "No" << endl;
            return 0;
        }

        cout << "Yes" << endl;
    }
    cout << flush;
    return 0;
}