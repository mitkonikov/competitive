#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<int> M, B;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (x % 2 == 0) {
            M.push_back(x);
        } else {
            B.push_back(x);
        }
    }
    sort(M.rbegin(), M.rend());
    sort(B.begin(), B.end());
    ll MS = 0, BS = 0;
    for (int i = 0; i < M.size(); i++) {
        MS += M[i];
    }
    bool ok = true;
    for (int i = 0; i < B.size(); i++) {
        BS += B[i];
        ok &= (MS > BS);
    }
    cout << (ok ? "YES" : "NO") << endl;
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