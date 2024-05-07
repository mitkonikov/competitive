#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void print(vector<int>& ans) {
    for (auto el: ans) cout << el << " ";
    cout << endl;
}

void testCase() {
    int N, K;
    cin >> N >> K;
    vector<int> ans(N);
    if (N == 1) {
        cout << K << endl;
        return;
    }
    // { 1, 0, 0, 0, 0, 0}
    //   0  1 1 1 1 1 1 1
    for (int j = 0; j < 31; j++) {
        if (K == ((1 << j) - 1)) {
            ans[0] = K;
            print(ans);
            return;
        } else if (K == (1 << j)) {
            ans[0] = K - 1;
            ans[1] = 1;
            print(ans);
            return;
        }
    }
    int best = 0;
    for (int j = 0; j < 31; j++) {
        if (K & (1 << j)) {
            best = j;
        }
    }
    ans[0] = (1 << best) - 1;
    ans[1] = K - ans[0];
    print(ans);
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