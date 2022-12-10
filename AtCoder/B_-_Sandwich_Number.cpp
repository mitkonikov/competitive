#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    string s;
    cin >> s;
    if (s.size() != 8) {
        cout << "No" << endl;
        return 0;
    }
    bool ok = true;
    ok &= (s.front() >= 'A' && s.front() <= 'Z');
    ok &= (s.back() >= 'A' && s.back() <= 'Z');
    int d = stoi(s.substr(1, 6));
    ok &= (d >= 100000 && d <= 999999);
    cout << (ok ? "Yes" : "No") << endl;
    cout << flush;
    return 0;
}