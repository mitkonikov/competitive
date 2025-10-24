#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int as = 0, bs = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'a') as++;
        else bs++;
    }
    if (as == bs) {
        cout << 0 << endl;
        return;
    }
    if (as < bs) {
        swap(as, bs);
        for (int i = 0; i < N; i++) {
            if (S[i] == 'a') S[i] = 'b';
            else S[i] = 'a';
        }
    }
    // remove a
    int best = 1e9;
    int bal = 0;
    vector<int> stack(2 * N + 40, -1);
    int off = N + 5;
    stack[off] = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'a') {
            bal--;
        } else {
            bal++;
        }
        stack[bal + off] = i + 1;
        int f = bal + off + (as - bs);
        if (f < 2 * N + 40 && f >= 0) {
            auto q = stack[f];
            if (q != -1) {
                best = min(best, (i + 1) - q);
            }
        }
    }
    if (best == N) {
        cout << -1 << endl;
    } else {
        cout << best << endl;
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