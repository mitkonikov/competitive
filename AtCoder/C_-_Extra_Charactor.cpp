#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != t[i]) {
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << t.size() << endl;
    cout << flush;
    return 0;
}