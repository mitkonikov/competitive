#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    string s;
    cin >> s;
    int ch[26];
    for (int i = 0; i < 26; i++) ch[i] = 0;
    for (int i = 0; i < 3; i++) ch[s[i] - 'a']++;
    for (int i = 0; i < 26; i++) {
        if (ch[i] == 1) {
            cout << (char)('a' + i) << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}