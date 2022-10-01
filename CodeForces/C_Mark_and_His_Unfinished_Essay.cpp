#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

struct sub {
    ll L, R;
    ll jump;
};

void testCase() {
    int n, copy, q;
    cin >> n >> copy >> q;
    string s;
    cin >> s;

    vector<sub> v;
    v.push_back({ 0, n-1, 0 });

    for (int i = 0; i < copy; i++) {
        ll L, R;
        cin >> L >> R;
        L--; R--;

        v.push_back({
            v.back().R + 1,
            v.back().R + 1 + (R - L),
            L
        });
    }

    for (int i = 0; i < q; i++) {
        ll K;
        cin >> K;
        K--;
        for (const auto& SUB: v) {
            if (K >= SUB.L && K <= SUB.R) {
                K = SUB.jump + K - SUB.L;
                while (K >= n) {
                    for (int i = 0; i < v.size(); i++) {
                        const auto& SUB = v[i];
                        if (K >= SUB.L && K <= SUB.R) {
                            K = SUB.jump + K - SUB.L;
                        }
                    }
                }
                cout << s[K] << endl;
                break;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}