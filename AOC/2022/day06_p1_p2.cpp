#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    string s;
    cin >> s;
    for (int i = 14; i < s.size(); i++) {
        set<char> d;
        for (int j = 0; j < 14; j++) {
            d.insert(s[i-j]);
        }
        if (d.size() == 14) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << s.size() << endl;
    return 0;
}