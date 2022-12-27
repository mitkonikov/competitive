#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    string s;
    cin >> s;
    int bal = 0;
    int ch[30];
    for (int i = 0; i < 30; i++) ch[i] = 0;
    stack<pair<int, int>> w;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            bal++;
        } else if (s[i] == ')') {
            while (!w.empty() && w.top().second == bal) {
                ch[w.top().first]--;
                w.pop();
            }
            bal--;
        } else {
            if (ch[s[i] - 'a'] > 0) {
                cout << "No" << endl;
                return 0;
            }
            ch[s[i] - 'a']++;
            w.push({ s[i] - 'a', bal });
        }
    }
    cout << "Yes" << endl;
    cout << flush;
    return 0;
}