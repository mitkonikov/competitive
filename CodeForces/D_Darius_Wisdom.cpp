#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    // we know exactly 0 1 2 where do they start
    vector<int> frq(3);
    for (int i = 0; i < N; i++) {
        frq[A[i]]++;
    }
    vector<int> pref(3);
    for (int i = 0; i < 3; i++) {
        if (i == 0) pref[i] = frq[i];
        else pref[i] = pref[i-1] + frq[i];
    }
    vector<vector<vector<int>>> buckets(3, vector<vector<int>>(3));
    for (int i = 0; i < N; i++) {
        if (i < pref[0]) {
            buckets[0][A[i]].push_back(i);
        } else if (i < pref[1]) {
            buckets[1][A[i]].push_back(i);
        } else {
            buckets[2][A[i]].push_back(i);
        }
    }
    vector<pair<int, int>> ans;
    auto make_swap = [&](int b1, int b2, int d1, int d2) {
        int mn = min(buckets[b1][d1].size(), buckets[b2][d2].size());
        for (int i = 0; i < mn; i++) {
            int i1 = buckets[b1][d1].back();
            int i2 = buckets[b2][d2].back();
            ans.push_back({ i1, i2 });
            buckets[b1][d1].pop_back();
            buckets[b2][d2].pop_back();
            buckets[b1][d2].push_back(i1);
            buckets[b2][d1].push_back(i2);
        }
    };
    for (int i = 0; i < N; i++) {
        make_swap(0, 2, 1, 0);
        make_swap(1, 2, 1, 0);
        make_swap(0, 2, 2, 1);
        make_swap(1, 2, 2, 1);
    }
    make_swap(0, 1, 1, 0);
    cout << ans.size() << endl;
    for (auto [u, v] : ans) {
        cout << u + 1 << " " << v + 1 << endl;
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