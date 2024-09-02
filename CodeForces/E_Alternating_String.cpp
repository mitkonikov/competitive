#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<vector<int>> suff_frq(N + 2, vector<int>(26, 0));
    vector<vector<int>> pref_frq(N + 2, vector<int>(26, 0));
    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            suff_frq[i][j] = suff_frq[i+2][j];
        }
        suff_frq[i][S[i] - 'a']++;
    }
    for (int i = 0; i < N; i++) {
        if (i - 2 >= 0) {
            for (int j = 0; j < 26; j++) {
                pref_frq[i][j] = pref_frq[i-2][j];
            }
        }
        pref_frq[i][S[i] - 'a']++;
    }
    int ans = N;
    if (S.size() % 2 == 0) {
        int m1 = *max_element(suff_frq[0].begin(), suff_frq[0].end());
        int m2 = *max_element(suff_frq[1].begin(), suff_frq[1].end());
        int a1 = accumulate(suff_frq[0].begin(), suff_frq[0].end(), 0);
        int a2 = accumulate(suff_frq[1].begin(), suff_frq[1].end(), 0);
        ans = min(ans, a1 - m1 + a2 - m2);
    }
    auto acc = [&](vector<int>& a, const vector<int>& b) {
        for (int i = 0; i < 26; i++) {
            a[i] += b[i];
        }
    };
    if (S.size() % 2 == 1) {
        for (int i = 0; i < N; i++) {
            // delete the i-th element and merge pref with suff accordingly
            vector<int> merge1(26), merge2(26);
            if (i - 2 >= 0) acc(merge1, pref_frq[i-2]);
            if (i - 1 >= 0) acc(merge2, pref_frq[i-1]);
            if (i + 1 < N) acc(merge1, suff_frq[i+1]);
            if (i + 2 < N) acc(merge2, suff_frq[i+2]);
            int m1 = *max_element(merge1.begin(), merge1.end());
            int m2 = *max_element(merge2.begin(), merge2.end());
            int a1 = accumulate(merge1.begin(), merge1.end(), 0);
            int a2 = accumulate(merge2.begin(), merge2.end(), 0);
            ans = min(ans, a1 - m1 + a2 - m2 + 1);
        }
    }
    cout << ans << endl;
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