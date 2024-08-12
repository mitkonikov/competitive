#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> intervals(N);
    for (int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
        intervals[i] = { A, B };
    }
    sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
        if (a.second == b.second) return (a.first < b.first);
        return (a.second < b.second);
    });
    ll ans = 0;
    for (int i = 1; i < N; i++) {
        int L = -1, R = i;
        while (L < R - 1) {
            int MID = (L + R) / 2;
            if (intervals[MID].second >= intervals[i].first) {
                R = MID;
            } else {
                L = MID;
            }
        }
        ans += i - R;
    }
    cout << ans << endl;
    return 0;
}