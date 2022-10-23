#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    string s;
    getline(cin, s);
    for (int i = 12; i <= 12; i++) {
        for (int j = 0; j < s.size(); j++) {
            int nc = (s[j] - 'a' - i + 26) % 26;
            bool ischar = false;
            if (s[j] >= 'a' && s[j] <= 'z') {
                ischar = true;
            }

            if (s[j] >= 'A' && s[j] <= 'Z') {
                nc = (s[j] - 'A' - i + 26) % 26;
                ischar = true;
            }

            if (!ischar) {
                cout << s[j];
            } else {
                if (s[j] >= 'A' && s[j] <= 'Z') {
                    cout << (char)('A' + nc);
                } else {
                    cout << (char)('a' + nc);
                }
            }
        }
    }
    cout << endl;
    cout << flush;
    return 0;
}