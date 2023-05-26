#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<int> apply(N + 10);
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        apply[l]++;
        apply[r+1]--;
    }
    vector<int> after(N + 10);
    int count = 0;
    for (int i = 0; i < N; i++) {
        count += apply[i];
        after[i] = count;
    }
    vector<int> order(N);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int a, int b) {
        return (after[a] > after[b]);
    });
    sort(A.rbegin(), A.rend());
    vector<int> ans(N);
    for (int i = 0; i < N; i++) {
        ans[order[i]] = A[i];
    }
    ll X = 0;
    for (int i = 0; i < N; i++) {
        X += (ll)ans[i] * after[i];
    }
    cout << X << endl;
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