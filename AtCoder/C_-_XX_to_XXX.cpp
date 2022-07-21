#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    vector<pair<char, int>> S, T;
    S.reserve(s.size());
    T.reserve(t.size());

    bool ok = true;
    S.push_back({ s[0], 1 });
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == S.back().first) {
            S.back().second++;
        } else {
            S.push_back({ s[i], 1 });
        }
    }

    T.push_back({ t[0], 1 });
    for (int i = 1; i < t.size(); i++) {
        if (t[i] == T.back().first) {
            T.back().second++;
        } else {
            T.push_back({ t[i], 1 });
        }
    }

    if (S.size() != T.size()) {
        cout << "No" << endl;
        return 0;
    }

    for (int i = 0; ok && i < S.size(); i++) {
        if (S[i].first == T[i].first) {
            if (S[i].second > T[i].second) ok = false;
            if (S[i].second == T[i].second) continue;
            if (S[i].second >= 2 && T[i].second >= 2) continue;
            ok = false;
        }
        ok = false;
    }

    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    cout << flush;
    return 0;
}