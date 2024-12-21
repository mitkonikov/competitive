#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, X, Y;
    cin >> N >> X >> Y;
    vector<int> ans(N);
    if (N % 2 == 0) {
        for (int i = 0; i < N; i++) {
            ans[i] = i % 2;
        }
        if (ans[X-1] != ans[Y-1] ^ 1) {
            ans[X-1] = 2;
        }
    } else {
        for (int i = 0; i < N; i++) {
            ans[(X + i) % N] = i % 2;
        }
        ans[X-1] = 2;
    }
    for (auto el: ans) cout << el << " ";
    cout << endl;
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