#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    if (s[0] == '0' || t[0] == '0') {
        cout << 0 << endl;
        return 0;
    }

    int count1 = 0, count2 = 0;
    int n = (int)s.size(), m = (int)t.size();
    for (int i = 0; i < n; i++) if (s[i] == 'S') count1++;
    for (int i = 0; i < m; i++) if (t[i] == 'S') count2++;

    int mul = count1 * count2;

    for (int i = 0; i < mul; i++) {
        cout << "S(";
    }
    cout << 0;
    for (int i = 0; i < mul; i++) {
        cout << ')';
    }
    cout << endl;
    return 0;
}