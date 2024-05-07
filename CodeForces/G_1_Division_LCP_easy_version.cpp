#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

void testCase() {
    int N, L, R;
    cin >> N >> L >> R;
    string S;
    cin >> S;
    auto z = z_function(S);
    z[0] = N;
    int l = 0, r = N + 1;
    while (l + 1 < r) {
        int MID = (l + r) / 2;
        int prev = N;
        int k = 0;
        for (int i = N - 1; i >= 0; i--) {
            int ext = min(z[i], prev - i);
            if (ext >= MID) {
                prev = i;
                k++;
            }
        }
        if (k >= L) {
            l = MID;
        } else {
            r = MID;
        }
    }
    cout << l << endl;
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