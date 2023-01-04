#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, M;
    cin >> N >> M;
    vector<ll> A(N);
    vector<ll> pref(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (i == 0) pref[i] = A[i];
        else pref[i] = pref[i-1] + A[i];
    }
    bool fine = true;
    for (int i = 0; i < N; i++) {
        if (pref[i] < pref[M-1]) {
            fine = false;
            break;
        }
    }
    if (fine) {
        cout << 0 << endl;
        return;
    }
    auto solve = [&](vector<int> a) {
        ll pref = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        int result = 0;
        for (int i = 0; i < a.size(); i++) {
            pref += a[i];
            pq.push(a[i]);
            while (pref < 0) {
                pref -= 2LL * pq.top();
                pq.pop();
                result++;
            }
        }
        return result;
    };
    vector<int> B, C;
    for (int i = M-1; i > 0; i--) B.push_back(-A[i]);
    for (int i = M; i < N; i++) C.push_back(A[i]);
    cout << solve(B) + solve(C) << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}